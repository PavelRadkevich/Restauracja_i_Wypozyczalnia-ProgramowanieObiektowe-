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
    vectorRentObject[1]->getObjectInfo();
    for (auto t = vectorRentObject.begin(); t < vectorRentObject.end(); t++){
        if ((*t)->getObjectID() == ID )
            return (*t);
    }
    return nullptr;
}

//Settery
void RentObjectRepository::addRentObject(const shared_ptr<RentObject> ror){
    vectorRentObject.push_back(ror);
}

void RentObjectRepository::removeRentObject(const shared_ptr<RentObject> ror) {
    vectorRentObject[1]->getObjectInfo();
    for (auto t = vectorRentObject.begin(); t < vectorRentObject.end(); t++){
        if ((*t) == ror )
            vectorRentObject.erase(t);
    }
}




