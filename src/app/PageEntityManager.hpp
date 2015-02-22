#ifndef PAGE_ENTITY_MANAGER_H_INCLUDED
#define PAGE_ENTITY_MANAGER_H_INCLUDED

#include "common/Singleton.hpp"
#include "core/EntityManager.hpp"

class Page;

class PageEntityManager: public EntityManager<Page>, public Singleton<PageEntityManager>
{
  friend class Singleton<PageEntityManager>;
  public:

  protected:
    PageEntityManager();
    virtual ~PageEntityManager();

  private:

};

#endif // PAGE_ENTITY_MANAGER_H_INCLUDED
