#pragma once
#include "Message.hpp"
#include <string>
#include <vector>

//abstract base class
class Subscriber{
public:
    // id is a unique identifier for a Subscriber
    // Should never be changed once initialized
    std::string id;
    std::vector<Message> vec;

    Subscriber(std::string id="") : id(id) {}
    virtual ~Subscriber() {}

    // signal adds a new data point
    void signal(Message message)
    {
        vec.push_back(message);
    }

    //pure virtual method (it's going to be overridden)
    virtual int read() const = 0;
};
