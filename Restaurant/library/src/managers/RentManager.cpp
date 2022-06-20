//
// Created by pvlrd on 13.06.2022.
//

#include "managers/RentManager.h"
#include "repositories/RentRepository.h"
#include "Rent.h"
#include "Client.h"
#include "RentObject.h"
#include "exceptions/ManagersExceptions.h"

//Konstruktor
RentManager::RentManager(const RentRepositoryPtr rr): repository(rr){}

//Destruktor
RentManager::~RentManager() {}
//Gettery
const vector<shared_ptr<Rent>> *RentManager::getClientRents (const shared_ptr<Client> client_){
    return repository->getClientRents(client_);
}

const shared_ptr<Rent> RentManager::getRentObjectRent(const shared_ptr<RentObject> rentObject_){
    return repository->getRentObjectRent(rentObject_);
}

const vector<shared_ptr<Rent>> *RentManager::getAllActualRents() {
    return repository->getAllActualRents();
}

const double RentManager::checkClientRentBalance(shared_ptr<Client> client_){
    double sum;
    for (auto t = repository->getAllArchiveRents()->begin(); t < repository->getAllArchiveRents()->end(); t++){
        if ((*t)->getClient() == client_)
            sum += (*t)->getEndCost();
    }
    return sum;
}

const shared_ptr<Rent>
RentManager::startRent(const int id_, const shared_ptr<Client> client_,
                       pt::ptime beginTime_, pt::ptime endTime_, shared_ptr<RentObject> rentObject_, const bool &isHallRent_){
    if (client_->isArchive() || rentObject_->isArchive())
        throw ManagersExceptions("CLIENT OR RENTOBJECT IS ARCHIVE!");

    if (rentObject_->isRented())
        throw ManagersExceptions("RENT OBJECT IS ALREADY RENTED!");

    shared_ptr<Rent> rent_ = make_shared<Rent>(id_, client_, beginTime_, endTime_, rentObject_, isHallRent_);
    repository->addCurrentRent(rent_);
    return rent_;
}

void RentManager::endRent(const shared_ptr<RentObject> rentObject_, const pt::ptime endRent_){
    shared_ptr<Rent> rent_ = repository->getRentObjectRent(rentObject_);
    rent_->endRent(endRent_);
    rent_->setArchive(true);
    repository->archiveRent(rent_);
}

//Settery
