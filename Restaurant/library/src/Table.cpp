//
// Created by student on 03.06.2022.
//

#include "Table.h"
#include "exceptions/RentObjectExceptions.h"
#include <iostream>

//Konstruktor
Table::Table(const int &basePrice, const int &objectID_, const int &capacity_, const int &numberOfTable_): capacity(capacity_),
numberOfTable(numberOfTable_), RentObject(basePrice, objectID_){
    hall == nullptr;
}


shared_ptr<Table> Table::create(const int &basePrice, const int &objectID_, const int &capacity_,
                                const int &numberOfTable_) {
    shared_ptr<Table> t(new Table(basePrice, objectID_, capacity_, numberOfTable_));
    t->init();
    return t;
}


void Table::init() {
I = shared_from_this();
std::cout << endl <<"Init()" << endl;
std::cout << shared_from_this() << endl;
I = shared_from_this();

}

//Table::Table(const int &basePrice, const int &objectID_, const int &capacity_, const int &numberOfTable_): capacity(capacity_), numberOfTable(numberOfTable_), RentObject(basePrice, objectID_){}
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

shared_ptr<const Table> Table::getTablePtr(){
    return I;
}

const shared_ptr<Hall> Table::getHallPtr() const {
    if (hall == nullptr)
        throw RentObjectExceptions("TABLE NOT HAVE A HALL!");
    else
    return hall;
}



//Settery
void Table::changeHall(HallPtr newHall, shared_ptr<Table> table1) {
    if (newHall == nullptr)
    throw RentObjectExceptions ("INVALID HALL IN FUCTION CHANGEHALL!");
    if (hall != nullptr)
    hall->removeTable(table1);

    hall = newHall;
    newHall->addTable(table1);

    table1->updatePrice();
}

void Table::updatePrice() {
    throw RentObjectExceptions("IMPOSSIBLE UPDATE PRICE!");
}

void Table::setHall(shared_ptr<Hall> newHall, shared_ptr<Table> table1) {
    if (newHall == nullptr)
        throw RentObjectExceptions ("INVALID HALL IN FUCTION CHANGEHALL!");
    hall = newHall;
    hall->addTable(table1);

    this->updatePrice();
}



