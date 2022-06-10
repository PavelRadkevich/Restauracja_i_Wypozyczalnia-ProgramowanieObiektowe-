//
// Created by student on 03.06.2022.
//

#include "Table.h"
#include "exceptions/RentObjectExceptions.h"

//Konstruktor
Table::Table(const int &basePrice, const int &objectID_, const int &capacity_, const Hall &hall_, const int &numberOfTable_): capacity(capacity_),
hall(make_shared<Hall>(hall_)), numberOfTable(numberOfTable_), RentObject(basePrice, objectID_){
    cost = basePrice * hall->getPriceFactor() * capacity;
}

Table::Table(const int &basePrice, const int &objectID_, const int &capacity_, const int &numberOfTable_): capacity(capacity_), numberOfTable(numberOfTable_), RentObject(basePrice, objectID_){}
//Destruktor
Table::~Table(){}

//Gettery
const string Table::getObjectInfo() const {
    return "Stolik nie ma przypisanego typu!";
}

const double Table::getActualPriceForHour() const {
    return 0;
}

const shared_ptr<Hall> Table::getTableHallPtr() const {
    return hall;
}

const shared_ptr<const Table> Table::getTablePtr() const {
    return shared_from_this();
}

//const double Table::getCost() const {
    //return cost;
//}

//Settery
void Table::changeHall(HallPtr newHall) {
    //hall->removeTable(shared_from_this());
    hall = newHall;
    //hall->addTable(shared_from_this());
    this->updatePrice();
}

void Table::updatePrice() {
    throw RentObjectExceptions("IMPOSSIBLE UPDATE PRICE!");
}

void Table::addToHall() {
    hall->addTable(shared_from_this());
}



