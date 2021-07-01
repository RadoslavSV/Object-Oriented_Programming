#pragma once
#include <string>

class Serializable {
public:
    virtual std::string to_string() = 0;
    virtual void from_string(std::string) = 0;
};
