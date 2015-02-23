#ifndef ROUTER_HANDLER_FACTORY_H_INCLUDED
#define ROUTER_HANDLER_FACTORY_H_INCLUDED

#include <proxygen/httpserver/RequestHandlerFactory.h>
#include <proxygen/httpserver/RequestHandler.h>

class RouterHandlerFactory: public proxygen::RequestHandlerFactory
{
  public:
    RouterHandlerFactory();
    virtual ~RouterHandlerFactory();

    void onServerStart() noexcept override;
    void onServerStop() noexcept override;
    proxygen::RequestHandler* onRequest(proxygen::RequestHandler* previousHandler, proxygen::HTTPMessage* message) noexcept override;

  private:

};

#endif // ROUTER_HANDLER_FACTORY_H_INCLUDED
