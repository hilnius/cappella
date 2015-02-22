#include "app/PageEntityManager.hpp"
#include "app/Page.hpp"
#include <iostream>

using namespace std;

PageEntityManager::PageEntityManager()
{
  this->addEntity(new Page());
}

PageEntityManager::~PageEntityManager()
{

}
