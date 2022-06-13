//
// Created by pvlrd on 13.06.2022.
//

#ifndef RESTAURANT_RENTMANAGER_H
#define RESTAURANT_RENTMANAGER_H

#include "boost/date_time.hpp"
#include <memory>
#include <vector>
using namespace std;
namespace pt = boost::posix_time;

class RentRepository;
class Rent;
class Client;
class RentObject;
class RentManager {
private:
    shared_ptr<RentRepository> repository;

public:
    //Konstruktor

    //Destruktor

    //Gettery
    const vector<shared_ptr<Rent>> *getClientRents (const shared_ptr<Client> client) const;
    const shared_ptr<Rent> getRentObjectRent (const shared_ptr<RentObject> rentObject_) const;
    const vector<shared_ptr<Rent>> *getAllActualRents ();
    const double checkClientRentBalance (const shared_ptr<Client> client_) const;

    //Settery
    const shared_ptr<Rent> startRent (const int id_, const shared_ptr<Client> client_, pt::ptime beginTime_,
                                           pt::ptime endTime_, shared_ptr<RentObject> rentObject_, const bool &isHallRent_) const;
    void endRent (const shared_ptr<RentObject> rentObject_, const pt::ptime endRent_) const;

};


#endif //RESTAURANT_RENTMANAGER_H
