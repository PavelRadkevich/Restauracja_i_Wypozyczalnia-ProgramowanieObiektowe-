//
// Created by student on 03.06.2022.
//

#include "Personal.h"
#include "exceptions/RentObjectExceptions.h"
//Konstruktor
Personal::Personal(const int &basePrice, const int &objectID_, const int &capacity_, const Hall &hall_, const int &numberOfTable_) :
Table(basePrice, objectID_, capacity_, hall_, numberOfTable_){
}

//Destruktor
Personal::~Personal(){}

//Gettery
const double Personal::getActualPriceForHour() const {
    if (basePrice * hall->getPriceFactor() * capacity != cost) throw RentObjectExceptions("NOT ACTUAL PRICE!");
    return basePrice * hall->getPriceFactor() * capacity;

}

const string Personal::getObjectInfo() const {
    string status;
    if (!rented)
        status = "No";
    else
        status = "Yes";

    return "Table number: " + to_string(numberOfTable) + " (ID: " + to_string(objectID)  +"). Located in the Hall " +
    hall->getName() + ". Capacity: " +std::to_string(capacity) + ". Base price: " + std::to_string(basePrice) + ". Ordered: " + status;
}

//Settery
void Personal::updatePrice() {
    cost = basePrice * hall->getPriceFactor() * capacity;
}

