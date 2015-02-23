#include "core/RouterHandler.hpp"
#include "core/Router.hpp"
#include <proxygen/httpserver/ResponseBuilder.h>

RouterHandler::RouterHandler()
{

}

RouterHandler::~RouterHandler()
{
  delete p_responseBuilder;
}


void RouterHandler::onRequest(std::unique_ptr<proxygen::HTTPMessage> headers) noexcept
{
  std::cout << "Request received for " << headers->getURL() << std::endl;
  p_responseBuilder = new proxygen::ResponseBuilder(downstream_);
  p_handler = Router::getInstance()->getHandler(headers->getURL(), &headers, p_responseBuilder);
}

void RouterHandler::onBody(std::unique_ptr<folly::IOBuf> body) noexcept
{

}

void RouterHandler::onEOM() noexcept
{
  try
  {
    p_handler();
  }
  catch (...)
  {
    p_responseBuilder->status(404, "Not Found")
      .sendWithEOM();
  }
}

void RouterHandler::onUpgrade(proxygen::UpgradeProtocol proto) noexcept
{

}

void RouterHandler::requestComplete() noexcept
{
  delete this;
}

void RouterHandler::onError(proxygen::ProxygenError err) noexcept
{
  delete this;
}
