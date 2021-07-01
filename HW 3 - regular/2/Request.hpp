/// Radoslav Velkov, 1 group, FN 62528

#pragma once
#include <string>

class Request{
private:
    std::string message = "";
    std::string sender = "";
    int counter = 0;
    int ID = 0;

public:
    std::string getMessage() const;
    void setMessage(const std::string&);
    std::string getSender() const;
    void setSender(const std::string&);
    int getCount() const;
    void setCount(int);
    int getID() const;
    void setID(int);
    Request();
    Request(const std::string& message, const std::string& sender);

//    void printRequest();
};




