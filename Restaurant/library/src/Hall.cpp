//
// Created by student on 03.06.2022.
//

#include "Hall.h"

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

//Settery
void Hall::addTable(shared_ptr<Table> arg) {
    tables.push_back(arg);
}

void Hall::removeTable(shared_ptr<Table> table_) {
    for (auto t = tables.begin(); t < tables.end(); t++){
        if ((*t) == table_ )
            tables.erase(t);
    }
}
