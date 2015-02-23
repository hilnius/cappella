#include "core/Router.hpp"

Router::Router()
{

}

Router::~Router()
{

}


std::function<void()> Router::getHandler(std::string route, std::unique_ptr<proxygen::HTTPMessage>* message, proxygen::ResponseBuilder* responseBuilder)
{
  auto method = (*message)->getMethod().get();
  if (p_routesHandlers[method].find(route) != p_routesHandlers[method].end())
  {
    return p_routesHandlers[method][route](message, responseBuilder);
  }
  return []() {};
}

