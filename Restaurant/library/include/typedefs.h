//
// Created by student on 03.06.2022.
//

#ifndef RESTAURANT_TYPEDEFS_H
#define RESTAURANT_TYPEDEFS_H


#include "Address.h"
#include "Hall.h"
#include "memory"
#include "repositories/ClientRepository.h"
#include "repositories/RentObjectRepository.h"
#include "repositories/RentRepository.h"




typedef shared_ptr<Address> AddressPtr;
typedef shared_ptr<Hall> HallPtr;
//typedef shared_ptr<ClientRepository> ClientRepositoryPtr;
//typedef shared_ptr<ClientRepository> AddressRepositoryPtr;
//typedef shared_ptr<RentObjectRepository> RentObjectRepositoryPtr;
//typedef shared_ptr<RentRepository> RentRepositoryPtr;
typedef shared_ptr<RentObject> RentObjectPtr;


#endif //RESTAURANT_TYPEDEFS_H
