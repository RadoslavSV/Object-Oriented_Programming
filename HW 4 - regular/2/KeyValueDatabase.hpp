#pragma once
#include <string>
#include "Object.hpp"

class KeyValueDatabase : public Object{
public:
    KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension);

    void add_entry(const std::pair<std::string, int>& entry);
    int get_value(const std::string& key) const;
};
