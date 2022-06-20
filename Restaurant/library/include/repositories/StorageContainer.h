//
// Created by pvlrd on 06.06.2022.
//

#ifndef RESTAURANT_STORAGECONTAINER_H
#define RESTAURANT_STORAGECONTAINER_H

#include "typedefs.h"


class StorageContainer {
private:
    ClientRepositoryPtr clientRepository;
    RentObjectRepositoryPtr rentObjectRepository;
    RentRepositoryPtr rentRepository;

public:
    //Konstruktor
    StorageContainer(ClientRepositoryPtr cr, RentObjectRepositoryPtr ror,
                     RentRepositoryPtr rr);

    //Destruktor
    ~StorageContainer();

    //Gettery
    const ClientRepositoryPtr getClientRepositry () const;
    const RentObjectRepositoryPtr getRentObjectRepository () const;
    const RentRepositoryPtr getRentRepository () const;
};


#endif //RESTAURANT_STORAGECONTAINER_H
