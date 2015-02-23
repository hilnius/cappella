#ifndef ROUTER_H_INCLUDED
#define ROUTER_H_INCLUDED

#include "common/Singleton.hpp"

#include <proxygen/lib/http/HTTPMessage.h>
#include <proxygen/httpserver/ResponseBuilder.h>

#include <string>
#include <functional>
#include <map>

class Router: public Singleton<Router>
{
  friend class Singleton<Router>;
  public:
    Router();
    virtual ~Router();

    std::function<void()> getHandler(std::string route, std::unique_ptr<proxygen::HTTPMessage>* message, proxygen::ResponseBuilder* responseBuilder);

    template<typename T>
    void rest(std::string route)
    {
      // GET (list) all resources of this type
      p_routesHandlers[proxygen::HTTPMethod::GET][route] = [](std::unique_ptr<proxygen::HTTPMessage>* message, proxygen::ResponseBuilder* responseBuilder) {
        T* handlerController = new T(responseBuilder);
        return [handlerController, message]() {
          handlerController->list(message);
          delete handlerController;
        };
      };
      // GET a specified resource
      p_routesHandlers[proxygen::HTTPMethod::GET][route + "/{}"] = [](std::unique_ptr<proxygen::HTTPMessage>* message, proxygen::ResponseBuilder* responseBuilder) {
        T* handlerController = new T(responseBuilder);
        return [handlerController, message]() {
          handlerController->find(message);
          delete handlerController;
        };
      };
      // POST (create) a new resource
      p_routesHandlers[proxygen::HTTPMethod::POST][route] = [](std::unique_ptr<proxygen::HTTPMessage>* message, proxygen::ResponseBuilder* responseBuilder) {
        T* handlerController = new T(responseBuilder);
        return [handlerController, message]() {
          handlerController->create(message);
          delete handlerController;
        };
      };
      // PUT (update) the specified resource
      p_routesHandlers[proxygen::HTTPMethod::PUT][route + "/{}"] = [](std::unique_ptr<proxygen::HTTPMessage>* message, proxygen::ResponseBuilder* responseBuilder) {
        T* handlerController = new T(responseBuilder);
        return [handlerController, message]() {
          handlerController->update(message);
          delete handlerController;
        };
      };
      // DELETE the specified resource
      p_routesHandlers[proxygen::HTTPMethod::DELETE][route + "/{}"] = [](std::unique_ptr<proxygen::HTTPMessage>* message, proxygen::ResponseBuilder* responseBuilder) {
        T* handlerController = new T(responseBuilder);
        return [handlerController, message]() {
          handlerController->remove(message);
          delete handlerController;
        };
      };
    }

    template<typename T>
    void get(std::string route, std::function<void(T*, std::unique_ptr<proxygen::HTTPMessage>*)> handler)
    {
      p_routesHandlers[proxygen::HTTPMethod::GET][route] = [&handler](std::unique_ptr<proxygen::HTTPMessage>* message, proxygen::ResponseBuilder* responseBuilder) {
        T* handlerController = new T(responseBuilder);
        return [handlerController, &handler, message]() {
          handler(handlerController, message);
          delete handlerController;
        };
      };
    }
  private:
    std::map<proxygen::HTTPMethod, std::map<std::string, std::function<std::function<void()>(std::unique_ptr<proxygen::HTTPMessage>*, proxygen::ResponseBuilder*)>>> p_routesHandlers;
};

#endif // ROUTER_H_INCLUDED
