//
// Created by student on 03.06.2022.
//

#ifndef RESTAURANT_RENTOBJECT_H
#define RESTAURANT_RENTOBJECT_H

#include <string>
using namespace std;

class RentObject {

protected:
    int basePrice;
    int objectID;

public:
    //Konstruktor
    RentObject (const int& basePrice_, const int &objectID);

    //Destruktor
    ~RentObject();

    //Gettery
    const int &getBasePrice () const;
    const int &getObjectID () const;
    virtual const string getObjectInfo () const;

};


#endif //RESTAURANT_RENTOBJECT_H
