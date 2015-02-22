#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include "common/Types.hpp"
#include "core/SQLEntity.hpp"

class Page;
class UserEntityManager;

class User: public SQLEntity
{
  public:
    User();
    virtual ~User();

    static UserEntityManager* getEntityManager();
    int getTotalPageViews();
    INTEGER<12> getId() const;
    void setId(INTEGER<12> id);

    static std::string getTableName() { return "users"; }

  private:
    INTEGER<12> p_id;
    STRING<255> p_name;
    MANY<Page> p_pages;

};

#endif // USER_H_INCLUDED
