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

#ifndef MANY_H_INCLUDED
#define MANY_H_INCLUDED

#include <functional>
#include <vector>

template<typename T>
class MANY
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

  private:
    std::vector<T*> p_related;
    std::function<std::vector<T*>()> p_relatedGetter;
    bool p_loaded;
};

#endif // MANY_H_INCLUDED
