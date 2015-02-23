#include "PageController.hpp"

PageController::PageController(proxygen::ResponseBuilder* responseBuilder) : RESTController(responseBuilder)
{

}

PageController::~PageController()
{

}

void PageController::list(std::unique_ptr<proxygen::HTTPMessage>* message)
{

  p_responseBuilder->status(200, "OK").header("Content-Type", "application/json").body("{\"id\":\"1\",\"name\":\"First Page\"}").sendWithEOM();
}

void PageController::find(std::unique_ptr<proxygen::HTTPMessage>* message)
{

}

void PageController::create(std::unique_ptr<proxygen::HTTPMessage>* message)
{

}

void PageController::update(std::unique_ptr<proxygen::HTTPMessage>* message)
{

}

void PageController::remove(std::unique_ptr<proxygen::HTTPMessage>* message)
{

}
