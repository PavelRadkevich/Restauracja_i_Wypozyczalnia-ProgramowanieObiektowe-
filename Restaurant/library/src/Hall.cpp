//
// Created by student on 03.06.2022.
//

#include "Hall.h"
#include "Table.h"
#include "exceptions/RentObjectExceptions.h"

//Konstruktor
Hall::Hall(const int &basePrice_, const int &objectID, const double &priceFactor_, const string &name_): priceFactor(priceFactor_)
, name(name_), RentObject(basePrice_, objectID){

}

//Destruktor
Hall::~Hall(){}

//Gettery
const double  Hall::getPriceFactor() const {
    return priceFactor;
}
const string Hall::getName() const {
    return name;
}

const string Hall::getObjectInfo() const {
    return "Sala " + name  + " (ID: " + to_string(objectID) + ")" +  ". Licznik ceny: " + to_string(priceFactor);
}

    const vector<shared_ptr<Table>> *Hall::getTablesOfHall() const {
    return &tables;
}

const int Hall::getHallSize() const {
    return tables.size();
}

//Settery
void Hall::addTable(const shared_ptr<Table>& arg) {
    for (auto t = tables.begin(); t < tables.end(); t++){
        if ((*t) == arg )
            throw RentObjectExceptions ("THE TABLE IS ALREADY IN THE HALL!");
    }
    tables.push_back(arg);

    this->updatePrice();
}

void Hall::removeTable(shared_ptr<Table> table_) {
    int p = 0;
    for (auto t = tables.begin(); t < tables.end(); t++){
        if ((*t) == table_) {
            tables.erase(t);
            p = 1;
        }
    }
    if (p == 0) throw RentObjectExceptions ("HALL IS NOT HAVE REMOTE TABLE!");

    this->updatePrice();
}

void Hall::setRentForTables(const bool & arg) {
    for (auto t = tables.begin(); t < tables.end(); t++) {
        if ((*t)->isRented() == arg)
            throw RentObjectExceptions("NOT ALL TABLES IN THE HALL ARE FREE!");
        (*t)->setRented(arg);
    }
}

const string Hall::getIDOfTablesOfHall() const {
    string info = "";
    for (auto t = tables.begin(); t < tables.end(); t++)
    {
        info += to_string((*t)->getObjectID()) + ", ";
    }
    return info;
}

void Hall::updatePrice() {
    cost = basePrice;
    for (auto t = tables.begin(); t < tables.end(); t++)
        cost += (*t)->getBasePrice();
    cost = cost * priceFactor * 0.5;
}


