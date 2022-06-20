//
// Created by student on 03.06.2022.
//

#include "Table.h"
#include "exceptions/RentObjectExceptions.h"
#include <iostream>

//Konstruktor
Table::Table(const int &basePrice, const int &objectID_, const int &capacity_, const int &numberOfTable_): capacity(capacity_),
numberOfTable(numberOfTable_), RentObject(basePrice, objectID_){
    hall = nullptr;
}


shared_ptr<Table> Table::create(const int &basePrice, const int &objectID_, const int &capacity_,
                                const int &numberOfTable_) {
    shared_ptr<Table> t(new Table(basePrice, objectID_, capacity_, numberOfTable_));
    t->init();
    return t;
}


void Table::init() {
I = shared_from_this();
//std::cout << endl <<"Init()" << endl;
//std::cout << shared_from_this() << endl;

}
//Destruktor
Table::~Table(){}

//Gettery
const string Table::getObjectInfo() const {
    return "Stolik nie ma przypisanego typu!";
}

const shared_ptr<Hall> Table::getTableHallPtr() const {

    return hall;
}

shared_ptr<const Table> Table::getTablePtr(){
    return I;
}

const shared_ptr<Hall> Table::getHallPtr() const {
    return hall;
}


const int Table::getCapacity() const {
    return capacity;
}

const int Table::getTableNumber() const {
    return numberOfTable;
}

//Settery
void Table::updatePrice() {
    throw RentObjectExceptions("IMPOSSIBLE UPDATE PRICE!");
}

void Table::setHall(shared_ptr<Hall> newHall) {
    if (newHall == nullptr)
        throw RentObjectExceptions ("INVALID HALL IN FUCTION SETHALL!");
    hall = newHall;
    this->updatePrice();
}




