//
// Created by student on 03.06.2022.
//

#ifndef RESTAURANT_GROUP_H
#define RESTAURANT_GROUP_H

#include "Table.h"

class Group : public Table{
protected:
    double sale;

public:
    //Konstruktor
    Group (const int& basePrice, const int& objectID_, const int& capacity_, const int& numberOfTable, const double& sale_);

    //Destruktor
    ~Group();

    //Gettery
    const string getObjectInfo() const;
    const double getSale () const;

    //Settery
    void updatePrice ();
};


#endif //RESTAURANT_GROUP_H
