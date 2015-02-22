#ifndef ENTITY_MANAGER_H_INCLUDED
#define ENTITY_MANAGER_H_INCLUDED

#include "core/Entity.hpp"
#include <vector>
#include <functional>
#include <iostream>

template<typename T>
class EntityManager
{
  public:
    EntityManager() {}
    virtual ~EntityManager() {}

    template<typename S>
    std::vector<T*> getRelated(std::string column, std::function<S(T*)> getter, S value)
    {
      std::vector<T*> result;
      std::cout << "EntityManager finding related " << column << " among " << p_entities.size() << " entities " << std::endl;
      std::cout << "\tValue to look for is \"" << value << "\"" << std::endl;
      for (int i = 0; i < p_entities.size(); ++i)
      {
        if (getter(p_entities[i]) == value)
        {
          result.push_back(p_entities[i]);
        }
      }
      return result;
    }

  protected:
    void addEntity(T* entity)
    {
      p_entities.push_back(entity);
    }

  private:
    std::vector<T*> p_entities;
};

#endif // ENTITY_MANAGER_H_INCLUDED
