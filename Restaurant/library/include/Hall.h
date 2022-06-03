//
// Created by student on 03.06.2022.
//

#ifndef RESTAURANT_HALL_H
#define RESTAURANT_HALL_H

#include "RentObject.h"

class Hall : public RentObject{
protected:
    int priceFactor;

public:
    //Konstruktor
    Hall(const int &basePrice_, const int &objectID, const int& priceFactor_);

    //Destruktor
    ~Hall();

    //Gettery
};


#endif //RESTAURANT_HALL_H
