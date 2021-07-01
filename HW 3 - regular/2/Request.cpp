/// Radoslav Velkov, 1 group, FN 62528

#include "Request.hpp"
int cnt = 0;

std::string Request::getMessage() const
{
    return this->message;
}

void Request::setMessage(const std::string& message)
{
    this->message = message;
}

std::string Request::getSender() const
{
    return this->sender;
}

void Request::setSender(const std::string& sender)
{
    this->sender = sender;
}

int Request::getCount() const
{
    return this->counter;
}

void Request::setCount(int counter)
{
    this->counter = counter;
}

int Request::getID() const
{
    return this->ID;
}

void Request::setID(int ID)
{
    this->ID = ID;
}

Request::Request()
{
    cnt++;
    setID(cnt);
    setMessage("");
    setSender("");
    setCount(cnt);
}

Request::Request(const std::string& message, const std::string& sender)
{
    cnt++;
    setID(cnt);
    setMessage(message);
    setSender(sender);
    setCount(cnt);
}

//void Request::printRequest()
//{
//    std::cout<<"Message:"<<getMessage()<<", Sender:"<<getSender()<<", ID:"<<getID()<<std::endl;
//}




















