///Radoslav Velkov, Software Engineering, 1st group, FN: 62528

#include "Error.hpp"
#include <cstring>

Error::Error()
{
    this->type = ErrorType::None;
    message=nullptr;
}

Error::Error(ErrorType type, const char* message)
{
    this->type = type;

    int messageCount = strlen(message);
    this->message = new char[messageCount + 1];
    strncpy(this->message, message, messageCount + 1);
}

Error::Error(const Error& other)
{
    delete[] message;
    int messageCount = strlen(other.message);
    this->message = new char[messageCount + 1];
    strncpy(this->message, message, messageCount + 1);
}

Error& Error::operator=(const Error& other)
{
    delete[] message;
    if(this!=&other)
    {
        delete[] message;
        int messageCount = strlen(other.message);
        this->message = new char[messageCount + 1];
        strncpy(this->message, message, messageCount + 1);
    }
    return *this;
}

Error::~Error()
{
    delete[] message;
}

bool Error::hasMessage() const
{
    if(message!=NULL) return 1;
    else return 0;
}

const char* Error::getMessage() const
{
    if( hasMessage() ) return message;
    else return nullptr;
}

ErrorType Error::getType() const
{
    return this->type;
}

void Error::setType(ErrorType type)
{
    this->type = type;
}

void Error::setMessage(const char* newMessage)
{
    delete[] message;
    int Count = strlen(newMessage);
    this->message = new char[Count + 1];
    strncpy(this->message, newMessage, Count + 1);
}

/*static*/ Error Error::newNone()
{
    Error e1(ErrorType::None, "");
    return e1;
}

/*static*/ Error Error::newBuildFailed(const char* message)
{
    Error e1(ErrorType::BuildFailed, message);
    return e1;
}

/*static*/ Error Error::newWarning(const char* message)
{
    Error e1(ErrorType::Warning, message);
    return e1;
}

/*static*/ Error Error::newFailedAssertion(const char* message)
{
    Error e1(ErrorType::FailedAssertion, message);
    return e1;
}
