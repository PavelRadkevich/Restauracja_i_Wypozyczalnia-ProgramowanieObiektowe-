//
// Created by student on 03.06.2022.
//

#ifndef RESTAURANT_HALL_H
#define RESTAURANT_HALL_H

#include "RentObject.h"
#include <vector>

class Hall : public RentObject, enable_shared_from_this<Hall>{
protected:
    string name;
    double priceFactor;
    vector<shared_ptr<Table>> tables {};

public:
    //Konstruktor
    Hall(const int &basePrice_, const int &objectID, const double& priceFactor_, const string& name_);

    //Destruktor
    ~Hall();

    //Gettery
    const double  getPriceFactor () const;
    const string getName () const;
    const string getObjectInfo () const;
    const vector<shared_ptr<Table>> *getTablesOfHall () const ;

    //Settery
    void addTable (shared_ptr<Table>);
    void removeTable(shared_ptr<Table>);


};


#endif //RESTAURANT_HALL_H
