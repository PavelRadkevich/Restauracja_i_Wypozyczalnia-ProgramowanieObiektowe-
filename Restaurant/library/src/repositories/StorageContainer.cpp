//
// Created by pvlrd on 06.06.2022.
//

#include "repositories/StorageContainer.h"
#include "repositories/ClientRepository.h"
#include "repositories/RentRepository.h"
#include "repositories/RentObjectRepository.h"

//Konstruktor
StorageContainer::StorageContainer(ClientRepositoryPtr cr,
RentObjectRepositoryPtr ror, RentRepositoryPtr rr) :clientRepository(cr),
rentObjectRepository(ror), rentRepository(rr){

}

//Destruktor
StorageContainer::~StorageContainer() {}


//Gettery
const ClientRepositoryPtr StorageContainer::getClientRepositry() const {
    return clientRepository;
}

const RentObjectRepositoryPtr StorageContainer::getRentObjectRepository() const {
    return rentObjectRepository;
}

const RentRepositoryPtr StorageContainer::getRentRepository() const {
    return rentRepository;
}
