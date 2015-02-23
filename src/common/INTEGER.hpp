#ifndef INTEGER_H_INCLUDED
#define INTEGER_H_INCLUDED

#include "common/JSONSerializable.hpp"
#include <sstream>
#include <string>

template<int N>
class INTEGER: public JSONSerializable
{
  public:
    INTEGER(int value = 0) { p_value = value; }
    virtual ~INTEGER() { }

    bool operator==(const INTEGER& other) { return other.p_value == p_value; }

    int toInt() const { return p_value; }
    std::string toString() const { return std::to_string(p_value); }
    virtual std::string toJSON(std::vector<std::string> wantedFields = std::vector<std::string>(0)) const { return toString(); }

  protected:
    virtual std::map<std::string, const JSONSerializable*> getSerializedData() const { return {}; }
  private:
    int p_value;
};

template<int N>
int& operator+=(int& container, const INTEGER<N>& value)
{
    container += value.toInt();
    return container;
}
template<int N>
std::ostream& operator<<(std::ostream& os, const INTEGER<N>& value)
{
    os << value.toInt();
    return os;
}

#endif // INTEGER_H_INCLUDED
