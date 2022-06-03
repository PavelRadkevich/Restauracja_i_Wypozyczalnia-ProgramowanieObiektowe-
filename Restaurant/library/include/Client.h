//
// Created by student on 03.06.2022.
//

#ifndef RESTAURANT_CLIENT_H
#define RESTAURANT_CLIENT_H

#include <string>
#include "typedefs.h"

using namespace std;

class Client {
private:
    string firstName;
    string lastName;
    int phone;
    AddressPtr address;

public:
    //Konstruktor
    Client(const string& firstName_, const string& lastName_, const int& phone_, const Address &address_);

    //Destruktor
    ~Client();

    //Gettery
    string getClientInfo () const;
    string getFullClientInfo () const;

};


#endif //RESTAURANT_CLIENT_H
