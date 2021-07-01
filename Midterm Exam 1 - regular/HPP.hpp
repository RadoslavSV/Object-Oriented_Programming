#pragma once
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

enum class Type{
    Sale,
    Rent
};

class Property{
private:
    std::string address;
    unsigned areaInSquareKm;
    double priceInEuro;
public:
    std::string getAddress() const;
    unsigned getAreaInSquareKm() const;
    double getPriceInEuro() const;
    void setAddress(std::string address) { this->address = address; }
    void setAreaInSquareKm(unsigned areaInSquareKm) { this->areaInSquareKm = areaInSquareKm; }
    void setPriceInEuro(double priceInEuro) { this->priceInEuro = priceInEuro; }

    double getPriceInLeva() const;
    std::string getType() const;
};

class PropertyForRent: public Property{
private:
    std::string landlordName;
    Type type;
public:
    std::string getLandlordName() const;
    void setLandlordName(std::string landlordName) { this->landlordName = landlordName; }
    PropertyForRent(std::string address="", unsigned areaInSquareKm=0, double priceInEuro=0, std::string landlordName="");

};

class PropertyForSale: public Property{
private:
    double depositAmount;
    Type type;
public:
    double getDepositAmount() const;
    PropertyForSale(std::string address="", unsigned areaInSquareKm=0, double priceInEuro=0, double depositAmount=0);
};



