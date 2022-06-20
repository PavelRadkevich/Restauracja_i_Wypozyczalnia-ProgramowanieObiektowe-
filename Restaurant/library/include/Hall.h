//
// Created by student on 03.06.2022.
//

#ifndef RESTAURANT_HALL_H
#define RESTAURANT_HALL_H

#include "RentObject.h"
#include <vector>
#include "typedefs.h"

class Hall : public RentObject{
protected:
    string name;
    double priceFactor;
    vector<TablePtr> tables;

public:
    //Konstruktor
    Hall(const int &basePrice_, const int &objectID, const double& priceFactor_, const string& name_);

    //Destruktor
    ~Hall();

    //Gettery
    const double  getPriceFactor () const;
    const string getName () const;
    const string getObjectInfo () const;
    const vector<TablePtr> *getTablesOfHall () const;
    const string getIDOfTablesOfHall () const;
    const int getHallSize ()const;

    //Settery
    void addTable (const TablePtr &);
    void removeTable(TablePtr);
    void setRentForTables (const bool&) override;
    void updatePrice ();


};


#endif //RESTAURANT_HALL_H
