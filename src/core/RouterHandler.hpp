#ifndef ROUTER_HANDLER_H_INCLUDED
#define ROUTER_HANDLER_H_INCLUDED

#include <proxygen/httpserver/RequestHandler.h>
#include <proxygen/httpserver/ResponseBuilder.h>

class RouterHandler: public proxygen::RequestHandler
{
  public:
    RouterHandler();
    virtual ~RouterHandler();

    void onRequest(std::unique_ptr<proxygen::HTTPMessage> headers) noexcept override;
    void onBody(std::unique_ptr<folly::IOBuf> body) noexcept override;
    void onEOM() noexcept override;
    void onUpgrade(proxygen::UpgradeProtocol proto) noexcept override;
    void requestComplete() noexcept override;
    void onError(proxygen::ProxygenError err) noexcept override;

  private:
    std::function<void()> p_handler;
    proxygen::ResponseBuilder* p_responseBuilder;
};

#endif // ROUTER_HANDLER_H_INCLUDED
