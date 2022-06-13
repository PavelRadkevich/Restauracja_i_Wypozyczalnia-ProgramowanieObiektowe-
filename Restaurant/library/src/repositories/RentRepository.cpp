//
// Created by pvlrd on 06.06.2022.
//

#include "repositories/RentRepository.h"
#include "Rent.h"

//Konstruktor
RentRepository::RentRepository() {}

//Destruktor
RentRepository::~RentRepository() {}

//Gettery

const shared_ptr<Rent> RentRepository::getRent(const int &ID) const {
    for (auto t = vectorCurrentRents.begin(); t < vectorCurrentRents.end(); t++){
        if ((*t)->getID() == ID)
            return (*t);
    }
    for (auto t = vectorArchiveRents.begin(); t < vectorArchiveRents.end(); t++){
        if ((*t)->getID() == ID)
            return (*t);
    }
        return nullptr;
}

const vector<shared_ptr<Rent>> *RentRepository::getClientRents(const shared_ptr<Client> client_) const {
    vector<shared_ptr<Rent>> actual;
    for (auto t = vectorCurrentRents.begin(); t < vectorCurrentRents.end(); t++){
        if((*t)->getClient() == client_)
            actual.push_back((*t));
    }
    return &actual;

}

const int RentRepository::getRepositorySize() const {
    return vectorCurrentRents.size() + vectorArchiveRents.size();
}

const vector<shared_ptr<Rent>> *RentRepository::getAllActualRents() const {
    return &vectorCurrentRents;
}

const vector<shared_ptr<Rent>> *RentRepository::getAllArchiveRents() const {
    return &vectorArchiveRents;
}

const shared_ptr<Rent> RentRepository::getRentObjectRent(const shared_ptr<RentObject> rentObject_) const {
    for (auto t = vectorCurrentRents.begin(); t < vectorCurrentRents.end(); t++){
        if ((*t)->getRentObject() == rentObject_)
            return (*t);
    }
    return nullptr;
}


//Settery

void RentRepository::addCurrentRent(const shared_ptr<Rent> arg) {
    vectorCurrentRents.push_back(arg);
}

void RentRepository::archiveRent(const shared_ptr<Rent> arg) {
    for (auto t = vectorCurrentRents.begin(); t < vectorCurrentRents.end(); t++){
        if ((*t) == arg)
            vectorCurrentRents.erase(t);
    }
    vectorArchiveRents.push_back(arg);
}

void RentRepository::removeRent(const shared_ptr<Rent> arg) {
    for (auto t = vectorCurrentRents.begin(); t < vectorCurrentRents.end(); t++){
        if ((*t) == arg)
            vectorCurrentRents.erase(t);
    }
}
