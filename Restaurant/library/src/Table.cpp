//
// Created by student on 03.06.2022.
//

#include "Table.h"

//Konstruktor
Table::Table(const int &basePrice, const int &objectID_, const int &capacity_, const Hall &hall_): capacity(capacity_),
hall(make_shared<Hall>(hall_)), RentObject(basePrice, objectID_){}

//Destruktor
Table::~Table(){}