#include "core/StaticFileHandler.hpp"
#include <sstream>
#include <fstream>
#include <regex>

StaticFileHandler::StaticFileHandler()
{

}

StaticFileHandler::~StaticFileHandler()
{
}


void StaticFileHandler::onRequest(std::unique_ptr<proxygen::HTTPMessage> headers) noexcept
{
  std::string requestedUrl = headers->getURL();
  std::cout << "Static file request for " << requestedUrl << std::endl;
  p_responseBuilder = new proxygen::ResponseBuilder(downstream_);
  std::string filename = "public" + requestedUrl;

  std::string contentType;
  std::regex imageFilesMatcher(".*\\.(ico|jpg|png|gif)", std::regex_constants::ECMAScript | std::regex_constants::icase);
  std::regex textFilesMatcher(".*\\.(html|css|js)", std::regex_constants::ECMAScript | std::regex_constants::icase);
  std::smatch matches;
  bool openBinary = false;
  if (std::regex_match(requestedUrl, matches, imageFilesMatcher))
  {
    contentType = "image/" + matches[1].str();
    openBinary = true;
  }
  else if (std::regex_match(requestedUrl, matches, textFilesMatcher))
  {
    std::string append = matches[1].str();
    if (append == "js")
    {
      append = "javascript";
    }
    contentType = "text/" + append + "; charset=utf-8";
  }

  std::ios_base::openmode mode = std::ios::in | std::ios::ate;
  if (openBinary) {
    mode = std::ios::in | std::ios::binary | std::ios::ate;
  }

  std::ifstream file(filename.c_str(), mode);
  if (file.is_open())
  {
    int fileSize = file.tellg();
    char* buffer = new char[fileSize];

    std::unique_ptr<folly::IOBuf> fileContent = folly::IOBuf::takeOwnership(buffer, fileSize, fileSize, nullptr, nullptr, true);
    file.seekg(0, std::ios::beg);
    file.read(buffer, fileSize);
    file.close();

    p_responseBuilder->status(200, "OK")
      .header("Content-Type", contentType)
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
