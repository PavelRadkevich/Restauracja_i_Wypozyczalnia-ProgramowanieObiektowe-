//
// Created by student on 03.06.2022.
//

#ifndef RESTAURANT_CLIENT_H
#define RESTAURANT_CLIENT_H

#include <string>
#include "typedefs.h"

using namespace std;

class Client : enable_shared_from_this<Client> {
private:
    string firstName;
    string lastName;
    int phone;
    shared_ptr<Address> address;

public:
    //Konstruktor
    Client(const string& firstName_, const string& lastName_, const int& phone_, const Address &address_);

    //Destruktor
    ~Client();

    //Gettery
    const string getClientInfo () const;
    const string getFullClientInfo () const;
    const int getClientPhone () const;
    const string getNames ();

};


#endif //RESTAURANT_CLIENT_H
