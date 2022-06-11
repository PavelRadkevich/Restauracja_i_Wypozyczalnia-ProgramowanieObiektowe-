//
// Created by student on 03.06.2022.
//

#include "RentObject.h"
#include "Table.h"
#include "Hall.h"
#include "exceptions/RentObjectExceptions.h"
using namespace std;

//Konstruktor
RentObject::RentObject(const int &basePrice_, const int &objectID): basePrice(basePrice_), objectID(objectID) {
    rented = false;
}



//Destruktor
RentObject::~RentObject() {}

//Gettery
const int &RentObject::getBasePrice() const {
    return basePrice;
}
const int &RentObject::getObjectID() const {
    return objectID;
}

const string RentObject::getObjectInfo() const {
    return "Object ID: " + to_string(objectID) + ". Base price: " + to_string(basePrice);
}

const double RentObject::getActualPriceForHour() const {
    return 0;
}

const shared_ptr<Hall> RentObject::getTableHallPtr() const {
    return nullptr;
}

shared_ptr<const Table> RentObject::getTablePtr() {
    return nullptr;
}


const vector<shared_ptr<Table>> *RentObject::getTablesOfHall() const {
    throw RentObjectExceptions ("CANNOT FIND A VECTOR WITH TABLES!");
}


const double RentObject::getCost() const {
    return cost;
}

const bool RentObject::isRented() const {
    return rented;
}


//Settery
void RentObject::updatePrice() {
    throw RentObjectExceptions("UNABLE TO UPDATE PRICE!");
}

void RentObject::setRented(const bool &arg){
    rented = arg;
}


void RentObject::setRentForTables(const bool &) {
    /*for (auto t = this->getTablesOfHall()->begin(); t < this->getTablesOfHall()->end(); t++)
    {
        (*t)->setRented(true);
    }*/
    throw RentObjectExceptions ("UNABLE TO SET RENT MODE TO TABLES IN THE HALL!");
}

