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
