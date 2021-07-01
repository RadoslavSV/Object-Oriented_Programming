/// Radoslav Velkov, fn 62528, group 1

#pragma once
#include <string>
#include "Error.hpp"

Error::Error(const std::string& message)
{
	error_message = message;
}

std::string Error::get_message() const {
	return error_message;
}

