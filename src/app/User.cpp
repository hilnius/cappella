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
  std::cout << "START PAGE VIEW COUNT" << std::endl;
  for (unsigned int i = 0; i < p_pages.size(); i++)
  {
    views += p_pages[i]->getPageViews();
  }
  std::cout << "END PAGE VIEW COUNT" << std::endl;
  return views;
}

INTEGER<12> User::getId() const
{
  return p_id;
}

void User::setId(INTEGER<12> id)
{
  p_id = id;
}
