#include "app/User.hpp"
#include "app/UserEntityManager.hpp"
#include "app/Page.hpp"
#include "core/SQLEntity.hpp"

#include <functional>

User::User() : p_pages(std::bind(&UserEntityManager::getUserPages, User::getEntityManager(), this))
{

}

User::~User()
{

}

UserEntityManager* User::getEntityManager() {
  return UserEntityManager::getInstance();
}

int User::getTotalPageViews()
{
  int views = 0;
  for (unsigned int i = 0; i < p_pages.size(); i++)
  {
    views += p_pages[i]->getPageViews();
  }
  return views;
}

void User::setId(INTEGER<12> id)
{
  p_id = id;
}

void User::setName(STRING<255> name)
{
  p_name = name;
}

INTEGER<12> User::getId() const
{
  return p_id;
}

STRING<255> User::getName() const
{
  return p_name;
}

MANY<Page>* User::getPages()
{
  return &p_pages;
}


std::map<std::string, const JSONSerializable*> User::getSerializedData() const
{
  std::map<std::string, const JSONSerializable*> result;
  result["name"] = &p_name;
  result["id"] = &p_id;
  result["pages"] = &p_pages;
  return result;
}
