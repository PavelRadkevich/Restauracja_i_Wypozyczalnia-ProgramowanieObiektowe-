//
// Created by pvlrd on 06.06.2022.
//

#ifndef RESTAURANT_RENTREPOSITORY_H
#define RESTAURANT_RENTREPOSITORY_H

#include <vector>
#include <memory>
#include "typedefs.h"
using namespace std;


class Rent;
class Client;
class RentObject;
class RentRepository {
private:
    vector<RentPtr> vectorCurrentRents;
    vector<RentPtr> vectorArchiveRents;

public:
    //Konstruktor
    RentRepository ();

    //Destruktor
    ~RentRepository();

    //Gettery
    const RentPtr getRent (const int &ID) const;
    const vector<RentPtr> *getClientRents (const ClientPtr client_) const;
    const int getRepositorySize ()const;
    const vector<RentPtr> *getAllActualRents () const;
    const vector<RentPtr> *getAllArchiveRents () const;
    const RentPtr getRentObjectRent(const RentObjectPtr rentObject_) const;

    //Settery
    void addCurrentRent (const RentPtr);
    void archiveRent (const RentPtr);
    void removeRent (const RentPtr);

};


#endif //RESTAURANT_RENTREPOSITORY_H
