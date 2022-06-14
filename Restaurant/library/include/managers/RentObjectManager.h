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
class Hall;
class Table;
class Personal;
class Group;
class RentObjectManager {
private:
    shared_ptr<RentObjectRepository> repository;

public:
    //Konstruktor

    //Destruktor

    //Gettery
    static const shared_ptr<RentObject> getRentObject (const shared_ptr<RentObjectRepository> ror, const int &id);
    static const vector<shared_ptr<RentObject>> *getAllRentObjects (const shared_ptr<RentObjectRepository> ror);

    //Settery
    static const shared_ptr<Personal> registerPersonalTable (const shared_ptr<RentObjectRepository> ror,
                                                               const int& basePrice, const int& objectID_,
                                                               const int& capacity_, const int& numberOfTable_);
    static const shared_ptr<Group> registerGroupTable (const shared_ptr<RentObjectRepository> ror,
                                                            const int& basePrice, const int& objectID_,
                                                            const int& capacity_, const int& numberOfTable,
                                                            const double& sale_);
    static const shared_ptr<Hall> registerHall (const shared_ptr<RentObjectRepository> ror, const int &basePrice_,
                                                      const int &objectID, const double& priceFactor_, const string& name_);
    static const void unregisterRentObject (const shared_ptr<RentObjectRepository> ror, shared_ptr<RentObject> rentObject_);
    static const void changeHall (const shared_ptr<RentObjectRepository> ror, shared_ptr<Hall> newHall_, shared_ptr<Table>);
};


#endif //RESTAURANT_RENTOBJECTMANAGER_H
