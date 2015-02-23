#ifndef JSON_SERIALIZABLE_H_INCLUDED
#define JSON_SERIALIZABLE_H_INCLUDED

#include <map>
#include <string>
#include <vector>

class JSONSerializable
{
  public:
    JSONSerializable() {}
    virtual ~JSONSerializable() {}

    virtual std::string toJSON(std::vector<std::string> wantedFields = std::vector<std::string>(0)) const
    {
      std::map<std::string, const JSONSerializable*> data = getSerializedData();
      std::string json = "{";
      if (wantedFields.size() == 0)
      {
        for (auto it = data.begin(); it != data.end(); it++)
        {
          if (it != data.begin())
          {
            json += ',';
          }
          json += "\"" + it->first + "\":" + it->second->toJSON();
        }
      }
      json += "}";
      return json;
    }

  protected:
    virtual std::map<std::string, const JSONSerializable*> getSerializedData() const = 0;

};

#endif // JSON_SERIALIZABLE_H_INCLUDED
