//
// Created by student on 03.06.2022.
//

#ifndef RESTAURANT_RENTOBJECT_H
#define RESTAURANT_RENTOBJECT_H

#include <string>
#include <memory>
#include <vector>

using namespace std;
class Hall;
class Table;
class RentObject{

protected:
    int basePrice;
    int objectID;
    shared_ptr<Table> table;
    double cost;
    bool rented;
public:
    //Konstruktor
    RentObject (const int& basePrice_, const int &objectID);

    //Destruktor
    ~RentObject();

    //Gettery
    const int &getBasePrice () const;
    const int &getObjectID () const;
    virtual const string getObjectInfo () const;
    virtual const double getActualPriceForHour () const;
    virtual const shared_ptr<Hall> getTableHallPtr () const;
    virtual const shared_ptr<const Table> getTablePtr () const;
    virtual const vector<shared_ptr<Table>>* getTablesOfHall () const;
    const double getCost () const;
    const bool isRented () const;

    //Settery
    virtual void updatePrice ();
    virtual void addToHall ();
    virtual void setRented(const bool &arg);
};


#endif //RESTAURANT_RENTOBJECT_H
