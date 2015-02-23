#include "app/UserController.hpp"
#include "app/UserEntityManager.hpp"
#include "app/User.hpp"
#include "app/Page.hpp"

UserController::UserController(proxygen::ResponseBuilder* responseBuilder) : RESTController(responseBuilder)
{

}

UserController::~UserController()
{

}

void UserController::list(std::unique_ptr<proxygen::HTTPMessage>* message)
{
  User* user = UserEntityManager::getInstance()->getUserById(1);
  user->getTotalPageViews();
  p_responseBuilder->status(200, "OK").header("Content-Type", "application/json").body(user->toJSON()).sendWithEOM();
}

void UserController::find(std::unique_ptr<proxygen::HTTPMessage>* message)
{

}

void UserController::create(std::unique_ptr<proxygen::HTTPMessage>* message)
{

}

void UserController::update(std::unique_ptr<proxygen::HTTPMessage>* message)
{

}

void UserController::remove(std::unique_ptr<proxygen::HTTPMessage>* message)
{

}
