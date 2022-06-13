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

//Destruktor

//Gettery
const shared_ptr<RentObject> RentObjectManager::getRentObject(const int &id) const {
    return repository->getRentObject(id);
}

const vector<shared_ptr<RentObject>> *RentObjectManager::getAllRentObjects() const {
    return repository->getAllRentObjects();
}

//Settery
const shared_ptr<RentObject>
RentObjectManager::registerPersonalTable(const int &basePrice_, const int &objectID_, const int &capacity_,
                                         const int &numberOfTable_) {
    if (repository->getRentObject(objectID_) != nullptr)
        return repository->getRentObject(objectID_);
    else {
        shared_ptr<Personal> personal = make_shared<Personal>(basePrice_, objectID_, capacity_, numberOfTable_);
        repository->addRentObject(personal);
        return personal;
    }
}

const shared_ptr<RentObject>
RentObjectManager::registerGroupTable(const int &basePrice_, const int &objectID_, const int &capacity_,
                                      const int &numberOfTable_, const double &sale_) {
    if (repository->getRentObject(objectID_) != nullptr)
        return repository->getRentObject(objectID_);
    else {
        shared_ptr<Group> group = make_shared<Group>(basePrice_, objectID_, capacity_, numberOfTable_, sale_);
        repository->addRentObject(group);
        return group;
    }
}

const shared_ptr<RentObject>
RentObjectManager::registerHall(const int &basePrice_, const int &objectID_, const double &priceFactor_,
                                const string &name_) {
    if (repository->getRentObject(objectID_) != nullptr)
        return repository->getRentObject(objectID_);
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

