#pragma once
#include <string>
#include "Comparable.hpp"
#include "Debug.hpp"
#include "Serializable.hpp"

class Object : public Comparable, public Debug, public Serializable{
private:
    std::string name;
    std::string location;
    std::string extension;
public:
    Object(const std::string& name="", const std::string& location="", const std::string& extension="");
    Object(const Object& other);
    Object& operator=(const Object& other);
    ~Object();

    Object* clone();
    std::string get_name() const;
    std::string get_location() const;
    std::string get_extension() const;
    std::string get_fullpath() const;
};
