//
// Created by student on 03.06.2022.
//

#include "Client.h"

//Konstruktor
Client::Client(const string& firstName_, const string &lastName_, const int &phone_, const Address& address_): firstName(firstName_), lastName(lastName_),
phone(phone_), address(make_shared<Address>(address_)) {}

//Destruktor
Client::~Client() {}

//Gettery
string Client::getClientInfo() const {
    return firstName + " " + lastName + ", " + std::to_string(phone);
}

string Client::getFullClientInfo() const {
    return firstName + " " + lastName + ", " + std::to_string(phone) + ". Address:: " + address->getAddressInfo();
}