/// Radoslav Velkov, 1 group, FN 62528

#include "LeavingRequest.hpp"

LeavingRequest::LeavingRequest(const std::string& sender)
{
    setMessage("I want to leave!");
    setSender(sender);
}
