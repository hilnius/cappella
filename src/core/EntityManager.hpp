/*
The MIT License (MIT)

Copyright (c) 2015 Robin Nicollet

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

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
      std::cout << "finding related inside " << p_entities.size() << " entities " << std::endl;
      for (int i = 0; i < p_entities.size(); ++i)
      {
      std::cout << "value inside loop check is \"" << value << "\"" << std::endl;
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
