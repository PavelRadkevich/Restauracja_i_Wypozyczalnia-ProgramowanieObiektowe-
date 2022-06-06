//
// Created by student on 03.06.2022.
//

#ifndef RESTAURANT_HALL_H
#define RESTAURANT_HALL_H

#include "RentObject.h"

class Hall : public RentObject{
protected:
    string name;
    double priceFactor;

public:
    //Konstruktor
    Hall(const int &basePrice_, const int &objectID, const double& priceFactor_, const string& name_);

    //Destruktor
    ~Hall();

    //Gettery
    const double  getPriceFactor () const;
    const string getName () const;

    const string getObjectInfo () const;

};


#endif //RESTAURANT_HALL_H
