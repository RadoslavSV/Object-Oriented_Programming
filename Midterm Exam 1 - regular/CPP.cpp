#include "HPP.hpp"
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

std::string Property::getAddress() const
{
    return this->address;
}

unsigned Property::getAreaInSquareKm() const
{
    return this->areaInSquareKm;
}

double Property::getPriceInEuro() const
{
    return this->priceInEuro;
}

double Property::getPriceInLeva() const
{
    double newPrice = getPriceInEuro()*1.95583;
    return newPrice;
}

std::string PropertyForRent::getLandlordName() const
{
    return this->landlordName;
}

double PropertyForSale::getDepositAmount() const
{
    return this->depositAmount;
}

PropertyForRent::PropertyForRent(std::string address, unsigned areaInSquareKm, double priceInEuro, std::string landlordName)
{
    setAddress(address);
    setAreaInSquareKm(areaInSquareKm);
    setPriceInEuro(priceInEuro);
    this->landlordName = landlordName;
    this->type = Type::Rent;
}

PropertyForSale::PropertyForSale(std::string address, unsigned areaInSquareKm, double priceInEuro, double depositAmount)
{
    setAddress(address);
    setAreaInSquareKm(areaInSquareKm);
    setPriceInEuro(priceInEuro);
    this->depositAmount = depositAmount;
    this->type = Type::Sale;
}

std::string Property::getType() const
{
//    PropertyForRent* ptr = dynamic_cast<PropertyForRent*>(this);
//    if(ptr) return "ForRent";
//    PropertyForSale* ptr = dynamic_cast<PropertyForSale*>(this);
//    if(ptr) return "ForSale";

}









