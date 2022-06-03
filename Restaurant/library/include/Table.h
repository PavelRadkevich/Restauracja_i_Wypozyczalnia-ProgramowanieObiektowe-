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

public:
    //Konstruktor
    Table (const int& basePrice, const int& objectID_, const int& capacity_, const Hall& hall_);

    //Destruktor
    ~Table();
};


#endif //RESTAURANT_TABLE_H
