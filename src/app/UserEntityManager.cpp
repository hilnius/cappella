#include "app/UserEntityManager.hpp"
#include "app/User.hpp"
#include "app/Page.hpp"
#include "app/PageEntityManager.hpp"
#include "core/MySQLDatabaseDriver.hpp"
#include <iostream>

using namespace std;

UserEntityManager::UserEntityManager()
{

}

UserEntityManager::~UserEntityManager()
{

}

void UserEntityManager::load()
{
  MySQLQueryBuilder* qb = MySQLDatabaseDriver::getInstance()->getQueryBuilder();
  sql::ResultSet* rst = qb->select("*", "users")->get();
  while (rst->next()) {
    cout << "NEW RESULT" << endl;
    cout << "\tname = '" << rst->getString("name") << "'" << endl;
    cout << "\tid = '" << rst->getString("id") << "'" << endl;

    User* user = new User();
    user->setId(rst->getInt("id"));
    user->setName(std::string(rst->getString("name")));
    this->addEntity(user);

  }
  delete rst;
  delete qb;
}

std::vector<Page*> UserEntityManager::getUserPages(const User* user) {
  cout << "UserEntityManager: Getting user pages" << endl;
  return PageEntityManager::getInstance()->getRelated<INTEGER<12>>("userId", &Page::getUserId, user->getId());
}

User* UserEntityManager::getUserById(INTEGER<12> id)
{
  for (unsigned int i = 0; i < p_entities.size(); ++i)
  {
    if (p_entities[i]->getId() == id)
    {
      return p_entities[i];
    }
  }
  return nullptr;
}
