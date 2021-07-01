/// Radoslav Velkov, fn 62528, group 1

#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

#include "Error.hpp"
#include "Optional.hpp"

template<typename T>

class Result {
public:
    Result();
    Result(const T& result);
    Result(const std::string& error_message);

    Optional<T> get_result() const;
    Optional<Error> get_error() const;

    bool operator==(const Error& right) const;
    bool operator==(const T& right) const;

private:
    T result_info;
    Error error_info;
    bool is_error;
};

template<typename T>
inline Result<T>::Result()
{
	// result_info = ;
	// error_info = "";

}

template<typename T>
Result<T>::Result(const T& result)
{
	result_info = result;
	is_error = false;
}

template<typename T>
Result<T>::Result(const std::string& error_message)
{
	error_info = error_message;
	is_error = true;
}

template<typename T>
Optional<T> Result<T>::get_result() const
{
	return result_info;
}

template<typename T>
Optional<Error> Result<T>::get_error() const
{
	return error_info;
}

template<typename T>
bool Result<T>::operator==(const Error& right) const
{
	return this->is_error ? true : false;
}

template<typename T>
bool Result<T>::operator==(const T& right) const
{
	return this->is_error ? false : true;
}



