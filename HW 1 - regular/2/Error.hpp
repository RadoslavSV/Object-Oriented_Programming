///Radoslav Velkov, Software Engineering, 1st group, FN: 62528

#pragma once
#include <iostream>

/// ErrorType represents all the different types of errors one might have
/// including the `None` error, which signifies absence of an error.
enum class ErrorType {
    None,                            //=0
    BuildFailed,                     //=1
    Warning,                         //=2
    FailedAssertion,                 //=3
};

/// Error represents a potential test error
/// It has a type and an optional message
class Error {
    /// Feel free to add additional private/public methods/fields
    ErrorType type;
    char* message=nullptr;

   public:
    Error();
    Error(ErrorType type, const char* message);
    Error(const Error&);
    Error& operator=(const Error&);
    ~Error();

    /// Check if the error has a message
    bool hasMessage() const;

    /// Retrieve the message of an error if such exists,
    /// otherwise return the only "safe" invalid pointer :)
    const char* getMessage() const;

    /// Retrieve the type of the error
    ErrorType getType() const;

    void setType(ErrorType type);              //create setter for the type
    void setMessage(const char* newMessage);  //and one for the message

    /// We will be creating new Errors only via the 4 methods below
    /// Create a new error of type None with no message
    static Error newNone();

    /// Create a new error of type BuildFailed with a message
    static Error newBuildFailed(const char* message);

    /// Create a new error of type Warning with a message
    static Error newWarning(const char* message);

    /// Create a new error of type FailedAssertion with a message
    static Error newFailedAssertion(const char* message);
};
