//
// Created by student on 03.06.2022.
//

#include "Table.h"

//Konstruktor
Table::Table(const int &basePrice, const int &objectID_, const int &capacity_, const Hall &hall_, const int &numberOfTable_): capacity(capacity_),
hall(make_shared<Hall>(hall_)), numberOfTable(numberOfTable_), RentObject(basePrice, objectID_){
    rented = false;
}

//Destruktor
Table::~Table(){}

//Gettery
const string Table::getObjectInfo() const {
    return "Stolik nie ma przpisanego typu!";
}

const double Table::getActualPriceForHour() const {
    return 0;
}

//Settery
void Table::changeHall(HallPtr newHall) {
    hall = newHall;
}
