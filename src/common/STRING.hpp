#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <string>

template<int T>
class STRING
{
  public:
    STRING(std::string value = "") { p_value = value; }
    virtual ~STRING() {}

  private:
    std::string p_value;
};

#endif // STRING_H_INCLUDED
