#include "app/UserEntityManager.hpp"
#include "app/User.hpp"
#include "app/Page.hpp"
#include "app/PageEntityManager.hpp"
#include <iostream>

using namespace std;

UserEntityManager::UserEntityManager()
{

}

UserEntityManager::~UserEntityManager()
{

}

std::vector<Page*> UserEntityManager::getUserPages(const User* user) {
  cout << "UserEntityManager: Getting user pages" << endl;
  return PageEntityManager::getInstance()->getRelated<INTEGER<12>>("userId", &Page::getUserId, user->getId());
}
