//
// Created by pvlrd on 06.06.2022.
//

#ifndef RESTAURANT_RENTOBJECTREPOSITORY_H
#define RESTAURANT_RENTOBJECTREPOSITORY_H

#include "vector"
#include "typedefs.h"


class RentObjectRepository {
private:
    std::vector<RentObjectPtr> vectorRentObject;

public:
    //Konstruktor
    RentObjectRepository ();

    //Destruktor
    ~RentObjectRepository();

    //Gettery
    const RentObjectPtr getRentObject (const int ID) const;
    const int getRepositorySize ()const;
    const vector<RentObjectPtr> *getAllRentObjects () const;

    //Settery
    void addRentObject (const RentObjectPtr);
    void removeRentObject (const RentObjectPtr);
};


#endif //RESTAURANT_RENTOBJECTREPOSITORY_H
