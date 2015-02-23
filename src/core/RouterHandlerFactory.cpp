#include "core/RouterHandlerFactory.hpp"
#include "core/RouterHandler.hpp"

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
  return new RouterHandler();
}
