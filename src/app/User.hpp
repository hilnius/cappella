#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include "common/Types.hpp"
#include "core/SQLEntity.hpp"

class Page;
class UserEntityManager;

class User: public SQLEntity, public JSONSerializable
{
  public:
    User();
    virtual ~User();

    static UserEntityManager* getEntityManager();
    int getTotalPageViews();

    void setId(INTEGER<12> id);
    void setName(STRING<255> name);

    INTEGER<12> getId() const;
    STRING<255> getName() const;
    MANY<Page>* getPages();

    static std::string getTableName() { return "users"; }

  protected:
    virtual std::map<std::string, const JSONSerializable*> getSerializedData() const;

  private:
    INTEGER<12> p_id;
    STRING<255> p_name;
    MANY<Page> p_pages;

};

#endif // USER_H_INCLUDED
