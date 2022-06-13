//
// Created by pvlrd on 06.06.2022.
//

#include "repositories/RentObjectRepository.h"

//Konstruktor
RentObjectRepository::RentObjectRepository() {}

//Destruktor
RentObjectRepository::~RentObjectRepository() {}

//Gettery
const shared_ptr<RentObject> RentObjectRepository::getRentObject(const int ID) const {
    for (auto t = vectorRentObject.begin(); t < vectorRentObject.end(); t++){
        if ((*t)->getObjectID() == ID )
            return (*t);
    }
    return nullptr;
}


const int RentObjectRepository::getRepositorySize() const {
    return vectorRentObject.size();
}

const vector<shared_ptr<RentObject>> *RentObjectRepository::getAllTableInHall(const shared_ptr<Hall> hall, vector<shared_ptr<RentObject>> *tables) const {
    for (auto t = vectorRentObject.begin(); t < vectorRentObject.end(); t++){
        if ((*t)->getTableHallPtr() == hall)
        {
            tables->push_back((*t));
        }
    }

    return tables;
}

const vector<shared_ptr<RentObject>> *RentObjectRepository::getAllRentObjects() const{
    return &vectorRentObject;
}



//Settery
void RentObjectRepository::addRentObject(const shared_ptr<RentObject> ror){
    vectorRentObject.push_back(ror);
}

void RentObjectRepository::removeRentObject(const shared_ptr<RentObject> ror) {
    for (auto t = vectorRentObject.begin(); t < vectorRentObject.end(); t++){
        if ((*t) == ror )
            vectorRentObject.erase(t);
    }
}





