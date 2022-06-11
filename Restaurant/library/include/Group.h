//
// Created by student on 03.06.2022.
//

#ifndef RESTAURANT_GROUP_H
#define RESTAURANT_GROUP_H

#include "Table.h"

class Group : public Table{
protected:
    double sale;
    shared_ptr<Table> parent;

public:
    //Konstruktor
    Group (const int& basePrice, const int& objectID_, const int& capacity_, const int& numberOfTable, const double& sale_);

    //Destruktor
    ~Group();

    //Gettery
    const double getActualPriceForHour () const;
    const string getObjectInfo() const;

    //Settery
    void updatePrice ();
};


#endif //RESTAURANT_GROUP_H
