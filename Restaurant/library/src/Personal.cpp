//
// Created by student on 03.06.2022.
//

#include "Personal.h"
#include "exceptions/RentObjectExceptions.h"
#include <iostream>
//Konstruktor
Personal::Personal(const int &basePrice, const int &objectID_, const int &capacity_, const int &numberOfTable_) :
Table(basePrice, objectID_, capacity_, numberOfTable_){
    shared_ptr<Table> p = Table::create (basePrice, objectID_, capacity_, numberOfTable_);
    parent = p;
    I = p;
}


/*shared_ptr<Personal> Personal::create(const int &basePrice, const int &objectID_, const int &capacity_, const Hall &hall_,
                                   const int &numberOfTable_) {
    shared_ptr<Personal> p (new Personal(basePrice, objectID_, capacity_, hall_, numberOfTable_));
    p->init();
    return p;
}
void Personal::init() {
    std::cout << "init()" << std::endl;
    std::cout << shared_from_this() << std::endl;
}
*/

//Destruktor
Personal::~Personal(){}

//Gettery
const double Personal::getActualPriceForHour() const {
    if (hall == nullptr)
        throw RentObjectExceptions("UNABLE TO CALCULATE PRICE, TABLE NOT HAVE A HALL!");
    else {
        if (basePrice * hall->getPriceFactor() * capacity != cost) throw RentObjectExceptions("NOT ACTUAL PRICE!");
        return basePrice * hall->getPriceFactor() * capacity;
    }
}

const string Personal::getObjectInfo() const {
    string status, halls;
    if (!rented)
        status = "No";
    else
        status = "Yes";
    if (hall == nullptr)
        halls = "The table  is not located in the hall ";
    else
        halls = "Located in the Hall " + hall->getName();

    return "Table number: " + to_string(numberOfTable) + " (ID: " + to_string(objectID)  +"). " + halls + ". Capacity: " +std::to_string(capacity) + ". Base price: " + std::to_string(basePrice) + ". Ordered: " + status;
}

//Settery
void Personal::updatePrice() {
    cost = basePrice * hall->getPriceFactor() * capacity;
}


const shared_ptr<const Table> Personal::getParent() const {
    return parent;
}

