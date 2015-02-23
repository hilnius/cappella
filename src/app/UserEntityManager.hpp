#ifndef USER_ENTITY_MANAGER_H_INCLUDED
#define USER_ENTITY_MANAGER_H_INCLUDED

#include "common/Singleton.hpp"
#include "core/EntityManager.hpp"
#include "common/Types.hpp"

class User;
class Page;

class UserEntityManager: public EntityManager<User>, public Singleton<UserEntityManager>
{
  friend class Singleton<UserEntityManager>;
  public:
    std::vector<Page*> getUserPages(const User* user);

    virtual void load();
    User* getUserById(INTEGER<12> id);

  protected:
    UserEntityManager();
    virtual ~UserEntityManager();

  private:

};

#endif // USER_ENTITY_MANAGER_H_INCLUDED
