#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include <proxygen/httpserver/ResponseBuilder.h>

class Controller
{
  public:
    Controller(proxygen::ResponseBuilder* responseBuilder);
    virtual ~Controller();

  protected:
    proxygen::ResponseBuilder* p_responseBuilder;

};

#endif // CONTROLLER_H_INCLUDED
