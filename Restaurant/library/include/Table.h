//
// Created by student on 03.06.2022.
//

#ifndef RESTAURANT_TABLE_H
#define RESTAURANT_TABLE_H

#include "RentObject.h"
#include "typedefs.h"

class Table : public RentObject {
protected:
    int capacity;
    bool rented;
    HallPtr hall;
    int numberOfTable;

public:
    //Konstruktor
    Table (const int& basePrice, const int& objectID_, const int& capacity_, const Hall& hall_, const int &numberOfTable_);

    //Destruktor
    ~Table();

    //Gettery
    virtual const string getObjectInfo ()const;
    virtual const double getActualPriceForHour () const;

    //Settery
    void changeHall (HallPtr newHall);
};


#endif //RESTAURANT_TABLE_H
