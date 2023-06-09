//
// Created by pvlrd on 13.06.2022.
//

#include "managers/RentObjectManager.h"
#include "repositories/RentObjectRepository.h"
#include "Personal.h"
#include "Group.h"
#include "Hall.h"
#include "exceptions/ManagersExceptions.h"
//Konstruktor
RentObjectManager::RentObjectManager(const shared_ptr<RentObjectRepository> rep): repository(rep) {}
//Destruktor
RentObjectManager::~RentObjectManager() {}

//Gettery
const shared_ptr<RentObject> RentObjectManager::getRentObject(const int &id){
    return repository->getRentObject(id);
}

const vector<shared_ptr<RentObject>> *RentObjectManager::getAllRentObjects(){
    return repository->getAllRentObjects();
}

//Settery
const shared_ptr<Personal>
RentObjectManager::registerPersonalTable(const int &basePrice_,
                                         const int &objectID_, const int &capacity_, const int &numberOfTable_) {
    if (repository->getRentObject(objectID_) != nullptr)
        throw ManagersExceptions ("THIS PERSONAL TABLE IS ALREADY REGISTERED!");
    else {
        shared_ptr<Personal> personal = make_shared<Personal>(basePrice_, objectID_, capacity_, numberOfTable_);
        repository->addRentObject(personal);
        return personal;
    }
}

const shared_ptr<Group>
RentObjectManager::registerGroupTable(const int &basePrice_,
                                      const int &objectID_, const int &capacity_,
                                      const int &numberOfTable_, const double &sale_) {
    if (repository->getRentObject(objectID_) != nullptr)
        throw ManagersExceptions ("THIS GROUP TABLE IS ALREADY REGISTERED!");
    else {
        shared_ptr<Group> group = make_shared<Group>(basePrice_, objectID_, capacity_, numberOfTable_, sale_);
        repository->addRentObject(group);
        return group;
    }
}

const shared_ptr<Hall>
RentObjectManager::registerHall(const int &basePrice_, const int &objectID_,
                                const double &priceFactor_,
                                const string &name_) {
    if (repository->getRentObject(objectID_) != nullptr)
        throw ManagersExceptions ("THIS CLIENT IS ALREADY REGISTERED!");
    else {
        shared_ptr<Hall> hall = make_shared<Hall>(basePrice_, objectID_, priceFactor_, name_);
        repository->addRentObject(hall);
        return hall;
    }
}

const void RentObjectManager::unregisterRentObject(shared_ptr<RentObject> rentObject_) {
    if (repository->getRentObject(rentObject_->getObjectID()) == nullptr)
        throw ManagersExceptions ("RENT OBJEXT IS NOT REGISTERED!");
    else {
        rentObject_->setArchive(true);
    }
}

const void RentObjectManager::changeHall(shared_ptr<Hall> newHall, shared_ptr<Table> table) {
    if (newHall == nullptr)
        throw ManagersExceptions ("INVALID HALL IN FUCTION CHANGEHALL!");
    if (newHall == table->getHallPtr())
        throw ManagersExceptions ("THIS HALL IS ALREADY SET!");
    if (table->getHallPtr() != nullptr)
        table->getHallPtr()->removeTable(table);

    table->setHall(newHall);
    newHall->addTable(table);
}

