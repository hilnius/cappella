#ifndef MANY_H_INCLUDED
#define MANY_H_INCLUDED

#include "common/JSONSerializable.hpp"
#include <functional>
#include <vector>
#include <iostream>

template<typename T>
class MANY: public JSONSerializable
{
  public:
    MANY(std::function<std::vector<T*>()> relatedGetter)
    {
      p_loaded = false;
      p_relatedGetter = relatedGetter;
    }
    virtual ~MANY() {}

    unsigned int size()
    {
      this->load();
      return p_related.size();
    }

    T* operator[](const int& i)
    {
        return p_related[i];
    }

    virtual std::string toJSON(std::vector<std::string> wantedFields = std::vector<std::string>(0)) const
    {
      std::string result = "[";
      std::cout << " printing " << p_related.size() << " entities " << std::endl;
      for (auto it = p_related.begin(); it != p_related.end(); it++)
      {
        JSONSerializable* serializableEntity = dynamic_cast<JSONSerializable*>(*it);
        if (!serializableEntity)
        {
          return result + "error]";
        }
        if (it != p_related.begin())
        {
          result += ",";
        }
        result += serializableEntity->toJSON(wantedFields);
      }
      result += "]";
      return result;
    }

  protected:
    void load(bool force = false)
    {
      if (p_loaded && !force)
      {
        return;
      }
      p_loaded = true;
      p_related = p_relatedGetter();
    }

    virtual std::map<std::string, const JSONSerializable*> getSerializedData() const { return {}; }

  private:
    std::vector<T*> p_related;
    std::function<std::vector<T*>()> p_relatedGetter;
    bool p_loaded;
};

#endif // MANY_H_INCLUDED
