#include "core/StaticFileHandler.hpp"
#include <sstream>
#include <fstream>

StaticFileHandler::StaticFileHandler()
{

}

StaticFileHandler::~StaticFileHandler()
{
}


void StaticFileHandler::onRequest(std::unique_ptr<proxygen::HTTPMessage> headers) noexcept
{
  std::cout << "Static file request for " << headers->getURL() << std::endl;
  p_responseBuilder = new proxygen::ResponseBuilder(downstream_);
  std::string filename = "public/image.jpg";

  std::ifstream file(filename.c_str(), std::ios::in | std::ios::binary | std::ios::ate);
  if (file.is_open())
  {
    int fileSize = file.tellg();
    char* buffer = new char[fileSize];

    std::unique_ptr<folly::IOBuf> fileContent = folly::IOBuf::takeOwnership(buffer, fileSize, fileSize, nullptr, nullptr, true);
    file.seekg(0, std::ios::beg);
    file.read(buffer, fileSize);
    file.close();

    p_responseBuilder->status(200, "OK")
      .header("Content-Type", "image/jpg")
      .body(std::move(fileContent))
      .sendWithEOM();
  }
  else
  {
    p_responseBuilder->status(404, "Not Found").sendWithEOM();
  }

  delete p_responseBuilder;
}

void StaticFileHandler::onBody(std::unique_ptr<folly::IOBuf> body) noexcept
{

}

void StaticFileHandler::onEOM() noexcept
{
}

void StaticFileHandler::onUpgrade(proxygen::UpgradeProtocol proto) noexcept
{

}

void StaticFileHandler::requestComplete() noexcept
{
  delete this;
}

void StaticFileHandler::onError(proxygen::ProxygenError err) noexcept
{
  delete this;
}
