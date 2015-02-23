#include <iostream>
#include <proxygen/httpserver/HTTPServer.h>

#include "core/MySQLDatabaseDriver.hpp"
#include "core/Router.hpp"
#include "core/RouterHandlerFactory.hpp"
#include "app/UserEntityManager.hpp"
#include "app/PageEntityManager.hpp"
#include "app/User.hpp"
#include "app/Page.hpp"
#include "app/PageController.hpp"
#include "app/UserController.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  cout << "Cappella started" << endl;

  Router::getInstance()->rest<PageController>("/page");
  Router::getInstance()->rest<UserController>("/user");
  MySQLDatabaseDriver::getInstance()->connect("127.0.0.1:3306", "root", "");
  MySQLDatabaseDriver::getInstance()->use("cappella");

  UserEntityManager::getInstance()->load();
  PageEntityManager::getInstance()->load();

  MySQLDatabaseDriver::kill();
  MySQLDatabaseDriver::kill();

  // START THE SERVER
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();

  std::vector<proxygen::HTTPServer::IPConfig> IPs = {
    {folly::SocketAddress("localhost", 8001, true), proxygen::HTTPServer::Protocol::HTTP},
  };

  proxygen::HTTPServerOptions options;
  options.threads = sysconf(_SC_NPROCESSORS_ONLN);
  options.idleTimeout = std::chrono::milliseconds(60000);
  options.shutdownOn = {SIGINT, SIGTERM};
  options.handlerFactories = proxygen::RequestHandlerChain()
      .addThen<RouterHandlerFactory>()
      .build();

  proxygen::HTTPServer server(std::move(options));
  server.bind(IPs);

  // Start HTTPServer mainloop in a separate thread
  std::thread t([&] () {
    server.start();
  });

  t.join();

  return 0;
}
