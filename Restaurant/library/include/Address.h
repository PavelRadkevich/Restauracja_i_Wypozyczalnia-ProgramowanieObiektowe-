//
// Created by student on 03.06.2022.
//

#ifndef RESTAURANT_ADDRESS_H
#define RESTAURANT_ADDRESS_H

#include "string"
#include <memory>
using namespace std;

class Address : enable_shared_from_this<Address> {
private:
    string city;
    string street;
    int number;

public:
    //Konstruktor
    Address (string city_, string street_, int number_);

    //Destruktor
    ~Address ();

    //Gettery
    string getAddressInfo () const;
};


#endif //RESTAURANT_ADDRESS_H
