#ifndef PAGE_H_INCLUDED
#define PAGE_H_INCLUDED

#include "common/Types.hpp"
#include "core/SQLEntity.hpp"

#include <iostream>

class JSONSerializable;

class Page: public SQLEntity, public JSONSerializable
{
  public:
    Page();
    virtual ~Page();

    void setId(INTEGER<12> id) { p_id = id; }
    void setName(STRING<255> name) { p_name = name; }
    void setUserId(INTEGER<12> userId) { p_userId = userId; }
    void setPageViews(INTEGER<12> pageViews) { p_pageViews = pageViews; }

    INTEGER<12> getId() { return p_id; }
    STRING<255> getName() { return p_name; }
    INTEGER<12> getUserId() { return p_userId; }
    INTEGER<12> getPageViews() { return p_pageViews; }

  private:
    INTEGER<12> p_id;
    STRING<255> p_name;
    INTEGER<12> p_userId;
    INTEGER<12> p_pageViews;

  protected:
    virtual std::map<std::string, const JSONSerializable*> getSerializedData() const
    {
        std::map<std::string, const JSONSerializable*> result;
        result["id"] = &p_id;
        result["name"] = &p_name;
        result["pageViews"] = &p_pageViews;
        return result;
    }

};

#endif // PAGE_H_INCLUDED
