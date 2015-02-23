#ifndef USER_CONTROLLER_H_INCLUDED
#define USER_CONTROLLER_H_INCLUDED

#include "core/RESTController.hpp"
#include <proxygen/httpserver/ResponseBuilder.h>

class UserController: public RESTController
{
  public:
    UserController(proxygen::ResponseBuilder* responseBuilder);
    virtual ~UserController();

    virtual void list(std::unique_ptr<proxygen::HTTPMessage>* message);
    virtual void find(std::unique_ptr<proxygen::HTTPMessage>* message);
    virtual void create(std::unique_ptr<proxygen::HTTPMessage>* message);
    virtual void update(std::unique_ptr<proxygen::HTTPMessage>* message);
    virtual void remove(std::unique_ptr<proxygen::HTTPMessage>* message);

  private:

};

#endif // USER_CONTROLLER_H_INCLUDED
