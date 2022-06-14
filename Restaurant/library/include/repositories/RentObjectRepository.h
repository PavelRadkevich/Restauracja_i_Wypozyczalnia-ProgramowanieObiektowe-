//
// Created by pvlrd on 06.06.2022.
//

#ifndef RESTAURANT_RENTOBJECTREPOSITORY_H
#define RESTAURANT_RENTOBJECTREPOSITORY_H

#include "vector"
#include "typedefs.h"
#include "RentObject.h"

class RentObjectRepository {
private:
    std::vector<shared_ptr<RentObject>> vectorRentObject;

public:
    //Konstruktor
    RentObjectRepository ();

    //Destruktor
    ~RentObjectRepository();

    //Gettery
    const shared_ptr<RentObject> getRentObject (const int ID) const;
    const int getRepositorySize ()const;
    const vector<shared_ptr<RentObject>> *getAllRentObjects () const;

    //Settery
    void addRentObject (const shared_ptr<RentObject>);
    void removeRentObject (const shared_ptr<RentObject>);
};


#endif //RESTAURANT_RENTOBJECTREPOSITORY_H
