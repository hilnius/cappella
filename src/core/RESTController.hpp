#ifndef RESTController_H_INCLUDED
#define RESTController_H_INCLUDED

#include "core/Controller.hpp"

#include <proxygen/lib/http/HTTPMessage.h>

class RESTController: public Controller
{
  public:
    RESTController(proxygen::ResponseBuilder* responseBuilder);
    virtual ~RESTController();

    virtual void list(std::unique_ptr<proxygen::HTTPMessage>* message) = 0;
    virtual void find(std::unique_ptr<proxygen::HTTPMessage>* message) = 0;
    virtual void create(std::unique_ptr<proxygen::HTTPMessage>* message) = 0;
    virtual void update(std::unique_ptr<proxygen::HTTPMessage>* message) = 0;
    virtual void remove(std::unique_ptr<proxygen::HTTPMessage>* message) = 0;

  private:

};

#endif // RESTController_H_INCLUDED
