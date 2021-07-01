/// Radoslav Velkov, fn 62528, group 1

#pragma once
#include <string>

class Error {
public:
    Error(const std::string& message = "");
    std::string get_message() const;
private:
    std::string error_message;
};
