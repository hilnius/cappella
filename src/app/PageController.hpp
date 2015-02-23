#ifndef PAGE_CONTROLLER_H_INCLUDED
#define PAGE_CONTROLLER_H_INCLUDED

#include "core/RESTController.hpp"
#include <proxygen/httpserver/ResponseBuilder.h>

class PageController: public RESTController
{
  public:
    PageController(proxygen::ResponseBuilder* responseBuilder);
    virtual ~PageController();

    virtual void list(std::unique_ptr<proxygen::HTTPMessage>* message);
    virtual void find(std::unique_ptr<proxygen::HTTPMessage>* message);
    virtual void create(std::unique_ptr<proxygen::HTTPMessage>* message);
    virtual void update(std::unique_ptr<proxygen::HTTPMessage>* message);
    virtual void remove(std::unique_ptr<proxygen::HTTPMessage>* message);

  private:

};

#endif // PAGE_CONTROLLER_H_INCLUDED
