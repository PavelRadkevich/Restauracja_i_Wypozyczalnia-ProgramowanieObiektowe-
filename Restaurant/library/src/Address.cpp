//
// Created by student on 03.06.2022.
//

#include "Address.h"
//Konstruktor
Address::Address(string city_, string street_, int number_): city(city_), street(street_), number(number_) {}

//Destruktor
Address::~Address() {}


//gettery
string Address::getAddressInfo() const {
    return city + ", " + street + ", " + std::to_string(number);
}