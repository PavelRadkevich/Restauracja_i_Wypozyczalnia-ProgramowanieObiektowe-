//
// Created by student on 03.06.2022.
//

#ifndef RESTAURANT_PERSONAL_H
#define RESTAURANT_PERSONAL_H

#include "Table.h"
#include <memory>

class Personal : public Table{
protected:

public:
    //Konstruktor
    Personal (const int& basePrice, const int& objectID_, const int& capacity_, const int& numberOfTable_);

    //Destruktor
    ~Personal();

    //Gettery
    const string getObjectInfo() const;

    //Settery
    void updatePrice ();
};


#endif //RESTAURANT_PERSONAL_H
