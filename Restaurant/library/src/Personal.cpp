//
// Created by student on 03.06.2022.
//

#include "Personal.h"
//Konstruktor
Personal::Personal(const int &basePrice, const int &objectID_, const int &capacity_, const Hall &hall_) :
Table(basePrice, objectID_, capacity_, hall_){}

//Destruktor
Personal::~Personal(){}

//Gettery
const string Personal::getObjectInfo() const {
    return "Capacity: " + std::to_string(capacity) + ". Base price: " + std::to_string(basePrice) +
    ". Object ID: " + std::to_string(objectID);
}