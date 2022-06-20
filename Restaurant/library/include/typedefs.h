//
// Created by student on 03.06.2022.
//

#ifndef RESTAURANT_TYPEDEFS_H
#define RESTAURANT_TYPEDEFS_H

#include "memory"
using namespace std;
class Address;
class Hall;
class Table;
class RentObject;
class ClientRepository;
class AddressRepository;
class RentObjectRepository;
class RentRepository;
class Client;
class Rent;
class Personal;
class RentObjectManager;


typedef shared_ptr<Address> AddressPtr;
typedef shared_ptr<Hall> HallPtr;
typedef shared_ptr<Table> TablePtr;
typedef shared_ptr<RentObject> RentObjectPtr;
typedef shared_ptr<ClientRepository> ClientRepositoryPtr;
typedef shared_ptr<AddressRepository> AddressRepositoryPtr;
typedef shared_ptr<RentObjectRepository> RentObjectRepositoryPtr;
typedef shared_ptr<RentRepository> RentRepositoryPtr;
typedef shared_ptr<Client> ClientPtr;
typedef shared_ptr<Rent> RentPtr;
typedef shared_ptr<Personal> PersonalPtr;
typedef shared_ptr<RentObjectManager> RentObjectManagerPtr;


#endif //RESTAURANT_TYPEDEFS_H
