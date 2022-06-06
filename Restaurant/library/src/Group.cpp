//
// Created by student on 03.06.2022.
//

#include "Group.h"
//Konstruktor
Group::Group(const int &basePrice, const int &objectID_, const int &capacity_, const Hall &hall_, const int &numberOfTable_, const double &sale_) :
sale(sale_) ,Table(basePrice, objectID_, capacity_, hall_, numberOfTable_){}

//Destruktor
Group::~Group(){}

//Gettery
const double Group::getActualPriceForHour() const {
    return basePrice * hall->getPriceFactor() * capacity * sale;
}

const string Group::getObjectInfo() const {
    string status;
    if (!rented)
        status = "No";
    else
        status = "Yes";
    double sale_ = sale * 100;

    return "Table number: " + to_string(numberOfTable) + " (ID: " + to_string(objectID) + "). Located in the Hall " +
            hall->getName() + ". Capacity: " + std::to_string(capacity) + ". Base price: " + std::to_string(basePrice) +
            ". Sale: " + to_string(sale_) + "%. Ordered: " + status;
}