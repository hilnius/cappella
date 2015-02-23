#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "common/JSONSerializable.hpp"
#include <string>

template<int T>
class STRING: public JSONSerializable
{
  public:
    STRING(std::string value = "") { p_value = value; }
    virtual ~STRING() {}

    virtual std::string toJSON(std::vector<std::string> wantedFields = std::vector<std::string>(0)) const { return '"' + p_value + '"'; }

  protected:
    virtual std::map<std::string, const JSONSerializable*> getSerializedData() const { return {}; }

  private:
    std::string p_value;

};

#endif // STRING_H_INCLUDED
