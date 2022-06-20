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
    RentObjectManager(const shared_ptr<RentObjectRepository> rep);
    //Destruktor
    ~RentObjectManager();

    //Gettery
    const shared_ptr<RentObject> getRentObject (const int &id);
    const vector<shared_ptr<RentObject>> *getAllRentObjects ();

    //Settery
    const shared_ptr<Personal> registerPersonalTable (const int& basePrice, const int& objectID_,
                                                               const int& capacity_, const int& numberOfTable_);
    const shared_ptr<Group> registerGroupTable (const int& basePrice, const int& objectID_,
                                                            const int& capacity_, const int& numberOfTable,
                                                            const double& sale_);
    const shared_ptr<Hall> registerHall (const int &basePrice_,
                                                      const int &objectID, const double& priceFactor_, const string& name_);
    const void unregisterRentObject (shared_ptr<RentObject> rentObject_);
    const void changeHall (shared_ptr<Hall> newHall_, shared_ptr<Table>);
};


#endif //RESTAURANT_RENTOBJECTMANAGER_H
