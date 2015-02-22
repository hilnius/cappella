#ifndef PAGE_H_INCLUDED
#define PAGE_H_INCLUDED

#include "common/Types.hpp"
#include "core/SQLEntity.hpp"

#include <iostream>

class Page: public SQLEntity
{
  public:
    Page() {}
    virtual ~Page() {}

    INTEGER<12> getId() { return p_id; }
    INTEGER<12> getUserId() { return p_userId; }
    INTEGER<12> getPageViews() { return p_pageViews; }

  private:
    INTEGER<12> p_id;
    INTEGER<12> p_userId;
    INTEGER<12> p_pageViews;

};

#endif // PAGE_H_INCLUDED
