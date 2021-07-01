/// Radoslav Velkov, fn 62528, group 1

#pragma once
#include <string>

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

template <typename T>
class Optional {
public:
    Optional();
    Optional(const T& value);

    bool is_none() const;
    T get_value() const;

private:
    T element;
    bool isDefined = true;
};

template<typename T>
Optional<T>::Optional()
{
	isDefined = false;
	//this->element = NULL;
}

template<>
Optional<int>::Optional()
{
	isDefined = false;
	this->element = NULL;
}

template<>
Optional<long>::Optional()
{
	isDefined = false;
	this->element = NULL;
}

template<>
Optional<double>::Optional()
{
	isDefined = false;
	this->element = NULL;
}

template<>
Optional<std::string>::Optional()
{
	isDefined = false;
	this->element = "";
}

template <>
Optional<Error>::Optional()
{
    isDefined = false;
    Error e1;
    this->element = e1;
}

template <typename T>
Optional<T>::Optional(const T& value)
{
	element = value;
}

template<typename T>
bool Optional<T>::is_none() const
{
	return isDefined ? false : true;
}

template<typename T>
T Optional<T>::get_value() const
{
	return this->element;
}



