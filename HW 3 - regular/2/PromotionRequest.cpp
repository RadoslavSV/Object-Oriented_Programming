/// Radoslav Velkov, 1 group, FN 62528

#include "PromotionRequest.hpp"

double PromotionRequest::getAmount() const
{
    return this->amount;
}

void PromotionRequest::setAmount(double amount)
{
    this->amount = amount;
}

PromotionRequest::PromotionRequest(const std::string& sender, double amount)
{
    setMessage("I want a raise!");
    setSender(sender);
    setAmount(amount);
}

//void PromotionRequest::printRequest()
//{
//    std::cout<<"Message:"<<getMessage()<<", Sender:"<<getSender()<<", Amount:$"<<getAmount()<<", ID:"<<getID()<<std::endl;
//}











