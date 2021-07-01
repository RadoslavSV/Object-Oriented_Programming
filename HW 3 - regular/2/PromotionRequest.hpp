/// Radoslav Velkov, 1 group, FN 62528

#pragma once
#include "Request.hpp"

class PromotionRequest: public Request{
private:
    double amount = 0;
public:
    double getAmount() const;
    void setAmount(double);
    PromotionRequest(const std::string& sender="", double amount=0);

//    void printRequest();
};
