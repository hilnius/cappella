#include "core/RouterHandlerFactory.hpp"
#include "core/RouterHandler.hpp"
#include "core/StaticFileHandler.hpp"


#include <regex>

RouterHandlerFactory::RouterHandlerFactory()
{

}

RouterHandlerFactory::~RouterHandlerFactory()
{

}


void RouterHandlerFactory::onServerStart() noexcept
{

}

void RouterHandlerFactory::onServerStop() noexcept
{

}

proxygen::RequestHandler* RouterHandlerFactory::onRequest(proxygen::RequestHandler* previousHandler, proxygen::HTTPMessage* message) noexcept
{
  std::regex staticFilesMatcher("/test\\.jpg", std::regex_constants::ECMAScript | std::regex_constants::icase);
  std::cout << "URL requested " << message->getURL() << std::endl;
  std::cout << std::regex_match(message->getURL(), staticFilesMatcher) << std::endl;
  if (std::regex_match(message->getURL(), staticFilesMatcher))
  {
    std::cout << "static file handler called" << std::endl;
    return new StaticFileHandler();
  }
  return new RouterHandler();
}
