//
// Created by pvlrd on 06.06.2022.
//

#include "repositories/AddressRepository.h"

//Konstruktor
AddressRepository::AddressRepository() {}

//Destruktor
AddressRepository::~AddressRepository() {}

//Gettery
const int AddressRepository::getAddressSize() {
    return vectorAddress.size();
}

const string AddressRepository::getAllAddresses() {
    string info = "";
    for (auto t = vectorAddress.begin(); t < vectorAddress.end(); t++)
    {
        info = info + (*t)->getAddressInfo() + "\n";
    }
    return info;
}


//Settery
void AddressRepository::addAddress(const shared_ptr<Address> ror){
    vectorAddress.push_back(ror);
}

void AddressRepository::removeAddress(const shared_ptr<Address> ror) {
    for (auto t = vectorAddress.begin(); t < vectorAddress.end(); t++){
        if ((*t) == ror )
            vectorAddress.erase(t);
    }
}



