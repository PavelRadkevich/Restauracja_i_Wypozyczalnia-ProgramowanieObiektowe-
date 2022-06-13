//
// Created by student on 03.06.2022.
//

#include "Client.h"
#include "exceptions/ClientExceptions.h"

//Konstruktor
Client::Client(const int &id, const string& firstName_, const string &lastName_, const int &phone_, const shared_ptr<Address>& address_):
id(id), firstName(firstName_), lastName(lastName_),phone(phone_), address(address_) {
    if (id < 1) throw ClientExceptions("INVALID ID");
    if (firstName.empty()) throw ClientExceptions("INVALID FIRST NAME");
    if (lastName.empty()) throw ClientExceptions("INVALID LAST NAME");
    if (phone < 1) throw ClientExceptions ("INVALID PHONE");
    if (address->getAddressInfo().empty() or address == nullptr) throw ClientExceptions ("INVALID ADDRESS!");
    archive = false;
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

const int Client::getId() {
    return id;
}

const bool Client::isArchive() const {
    return archive;
}

const void Client::setArchive(const bool &archive_) {
    archive = archive_;
}


//Settery
