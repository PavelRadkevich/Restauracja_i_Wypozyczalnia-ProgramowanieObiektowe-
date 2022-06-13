//
// Created by pvlrd on 13.06.2022.
//

#ifndef RESTAURANT_RENTOBJECTMANAGER_H
#define RESTAURANT_RENTOBJECTMANAGER_H

#include <memory>
#include <vector>
using namespace std;

class RentObject;
class RentObjectRepository;
class RentObjectManager {
private:
    shared_ptr<RentObjectRepository> repository;

public:
    //Konstruktor

    //Destruktor

    //Gettery
    const shared_ptr<RentObject> getRentObject (const int &id) const;
    const vector<shared_ptr<RentObject>> *getAllRentObjects () const;

    //Settery
    const shared_ptr<RentObject> registerPersonalTable (const int& basePrice, const int& objectID_, const int& capacity_, const int& numberOfTable_);
    const shared_ptr<RentObject> registerGroupTable (const int& basePrice, const int& objectID_, const int& capacity_, const int& numberOfTable, const double& sale_);
    const shared_ptr<RentObject> registerHall (const int &basePrice_, const int &objectID, const double& priceFactor_, const string& name_);
    const void unregisterRentObject (shared_ptr<RentObject> rentObject_);
};


#endif //RESTAURANT_RENTOBJECTMANAGER_H
