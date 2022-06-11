//
// Created by student on 03.06.2022.
//

#include "Group.h"
#include "exceptions/RentObjectExceptions.h"
//Konstruktor
Group::Group(const int &basePrice, const int &objectID_, const int &capacity_,const int &numberOfTable_, const double &sale_) :
sale(sale_) ,Table(basePrice, objectID_, capacity_, numberOfTable_){
    shared_ptr<Table> p = Table::create (basePrice, objectID_, capacity_, numberOfTable_);
    parent = p;
    I = p;
}

//Destruktor
Group::~Group(){}

//Gettery
const double Group::getActualPriceForHour() const {
    if (hall == nullptr)
        throw RentObjectExceptions("UNABLE TO CALCULATE PRICE, TABLE NOT HAVE A HALL!");
    else {
        if (basePrice * hall->getPriceFactor() * capacity * sale != cost)
            throw RentObjectExceptions("NOT ACTUAL PRICE!");
        return basePrice * hall->getPriceFactor() * capacity * sale;
    }
}

const string Group::getObjectInfo() const {
    string status, halls;
    if (!rented)
        status = "No";
    else
        status = "Yes";

    if (hall == nullptr)
        halls = "The table  is not located in the hall ";
        else
        halls = "Located in the Hall " + hall->getName();

        double sale_ = sale * 100;

        return "Table number: " + to_string(numberOfTable) + " (ID: " + to_string(objectID) +
               "). " + halls + ". Capacity: " + std::to_string(capacity) + ". Base price: " +
               std::to_string(basePrice) +
               ". Sale: " + to_string(sale_) + "%. Ordered: " + status;

}

void Group::updatePrice() {
    cost = basePrice * hall->getPriceFactor() * capacity * sale;
}
