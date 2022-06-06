//
// Created by student on 03.06.2022.
//

#include "RentObject.h"
using namespace std;

//Konstruktor
RentObject::RentObject(const int &basePrice_, const int &objectID): basePrice(basePrice_), objectID(objectID) {}

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
    return "Jestem w klasie RentObject, coś nie tak";
}

const double RentObject::getActualPriceForHour() const {
    return 0;
}