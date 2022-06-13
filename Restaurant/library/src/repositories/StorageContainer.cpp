//
// Created by pvlrd on 06.06.2022.
//

#include "repositories/StorageContainer.h"

//Konstruktor
StorageContainer::StorageContainer(ClientRepository *cr,
RentObjectRepository *ror, RentRepository *rr) :clientRepository(cr),
rentObjectRepository(ror), rentRepository(rr){

}

//Destruktor
StorageContainer::~StorageContainer() {}


//Gettery
const ClientRepository* StorageContainer::getClientRepositry() const {
    return clientRepository;
}

const RentObjectRepository* StorageContainer::getRentObjectRepository() const {
    return rentObjectRepository;
}

const RentRepository* StorageContainer::getRentRepository() const {
    return rentRepository;
}
