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
