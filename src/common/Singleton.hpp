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

This code comes from http://tfc.duke.free.fr/coding/singleton.html Thanks to David Henry!
*/

#ifndef SINGLETON_H_INCLUDED
#define SINGLETON_H_INCLUDED

template <typename T>
class Singleton
{
  protected:
    // Constructor/Destructor forbidding the explicit instanciation of the inherited classes
    Singleton() { }
    ~Singleton() { }

  public:
    // Public interface
    static T* getInstance()
    {
      if (nullptr == instance)
      {
        instance = new T;
      }

      return (static_cast<T*>(instance));
    }

    static void kill()
    {
      if (nullptr != instance)
      {
        delete instance;
        instance = nullptr;
      }
    }

  private:
    // Unique instance
    static T *instance;
};

template <typename T>
T *Singleton<T>::instance = nullptr;

#endif // SINGLETON_H_INCLUDED
