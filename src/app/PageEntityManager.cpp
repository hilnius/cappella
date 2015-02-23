#include "app/PageEntityManager.hpp"
#include "app/Page.hpp"
#include "core/MySQLDatabaseDriver.hpp"
#include <iostream>

using namespace std;

PageEntityManager::PageEntityManager()
{

}

PageEntityManager::~PageEntityManager()
{

}

void PageEntityManager::load()
{
  MySQLQueryBuilder* qb = MySQLDatabaseDriver::getInstance()->getQueryBuilder();
  sql::ResultSet* rst = qb->select("*", "pages")->get();
  while (rst->next()) {
    cout << "NEW RESULT" << endl;
    cout << "\tid = '" << rst->getString("id") << "'" << endl;
    cout << "\tname = '" << rst->getString("name") << "'" << endl;
    cout << "\tuserId = '" << rst->getString("userId") << "'" << endl;
    cout << "\tpageViews = '" << rst->getString("pageViews") << "'" << endl;

    Page* page = new Page();
    page->setId(rst->getInt("id"));
    page->setName(std::string(rst->getString("name")));
    page->setUserId(rst->getInt("userId"));
    page->setPageViews(rst->getInt("pageViews"));
    this->addEntity(page);

  }
  delete rst;
  delete qb;
}
