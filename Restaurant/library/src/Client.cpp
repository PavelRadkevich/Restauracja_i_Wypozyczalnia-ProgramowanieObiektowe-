//
// Created by student on 03.06.2022.
//

#include "Client.h"
#include "exceptions/ClientExceptions.h"

//Konstruktor
Client::Client(const string& firstName_, const string &lastName_, const int &phone_, const Address& address_): firstName(firstName_), lastName(lastName_),
phone(phone_), address(make_shared<Address>(address_)) {
    if (firstName.empty()) throw ClientExceptions("INVALID FIRST NAME");
    if (lastName.empty()) throw ClientExceptions("INVALID LAST NAME");
    if (phone < 1) throw ClientExceptions ("INVALID PHONE");
    if (address->getAddressInfo().empty() or address == nullptr) throw ClientExceptions ("INVALID ADDRESS!");
}

//Destruktor
Client::~Client() {}

//Gettery
const string Client::getClientInfo() const {
    return firstName + " " + lastName + ", " + std::to_string(phone);
}

const string Client::getFullClientInfo() const {
    return firstName + " " + lastName + ", " + std::to_string(phone) + ". Address:: " + address->getAddressInfo();
}

const int Client::getClientPhone() const {
    return phone;
}

const string Client::getNames() {
    return firstName + " " + lastName;
}
