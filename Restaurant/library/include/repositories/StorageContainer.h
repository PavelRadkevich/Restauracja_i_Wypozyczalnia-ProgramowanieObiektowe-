//
// Created by pvlrd on 06.06.2022.
//

#ifndef RESTAURANT_STORAGECONTAINER_H
#define RESTAURANT_STORAGECONTAINER_H

#include "typedefs.h"

class StorageContainer {
private:
    ClientRepository *clientRepository;
    RentObjectRepository *rentObjectRepository;
    RentRepository *rentRepository;

public:
    //Konstruktor
    StorageContainer(ClientRepository *cr, RentObjectRepository *ror,
                     RentRepository *rr);

    //Destruktor
    ~StorageContainer();

    //Gettery
    const ClientRepository* getClientRepositry () const;
    const RentObjectRepository* getRentObjectRepository () const;
    const RentRepository* getRentRepository () const;
};


#endif //RESTAURANT_STORAGECONTAINER_H
