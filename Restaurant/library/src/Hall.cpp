//
// Created by student on 03.06.2022.
//

#include "Hall.h"

//Konstruktor
Hall::Hall(const int &basePrice_, const int &objectID, const int &priceFactor_): priceFactor(priceFactor_),
RentObject(basePrice_, objectID){}

//Destruktor
Hall::~Hall(){}