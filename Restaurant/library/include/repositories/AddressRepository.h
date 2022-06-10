//
// Created by pvlrd on 06.06.2022.
//

#ifndef RESTAURANT_ADDRESSREPOSITORY_H
#define RESTAURANT_ADDRESSREPOSITORY_H

#include "Address.h"
#include "typedefs.h"
#include <vector>

class AddressRepository {
private:
    std::vector<shared_ptr<Address>> vectorAddress;

public:
    //Konstruktor
    AddressRepository ();

    //Destruktor
    ~AddressRepository();

    //Gettery
    const int getAddressSize ();
    const string getAllAddresses ();

    //Settery
    void addAddress (const shared_ptr<Address>);
    void removeAddress (const shared_ptr<Address>);
};


#endif //RESTAURANT_ADDRESSREPOSITORY_H
