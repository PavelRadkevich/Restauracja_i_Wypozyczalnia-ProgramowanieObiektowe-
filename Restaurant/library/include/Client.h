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
    int id;
    string firstName;
    string lastName;
    int phone;
    shared_ptr<Address> address;
    bool archive;

public:
    //Konstruktor
    Client(const int &id, const string& firstName_, const string& lastName_, const int& phone_, const shared_ptr<Address> &address_);

    //Destruktor
    ~Client();

    //Gettery
    const string getClientInfo () const;
    const string getFullClientInfo () const;
    const int getClientPhone () const;
    const string getNames ();
    const int getId ();
    const bool isArchive () const;
    const shared_ptr<Address> getAddress () const;

    //Settery
    const void setArchive (const bool &archive_);
};


#endif //RESTAURANT_CLIENT_H
