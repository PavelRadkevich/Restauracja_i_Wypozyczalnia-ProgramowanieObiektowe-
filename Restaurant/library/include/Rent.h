//
// Created by student on 03.06.2022.
//

#ifndef RESTAURANT_RENT_H
#define RESTAURANT_RENT_H

#include "boost/date_time.hpp"
#include <memory>
#include <string>

using namespace std;
namespace pt = boost::posix_time;
class RentObject;
class Client;

class Rent {
private:
    shared_ptr<Client> client;
    int id;
    pt::ptime beginTime;
    pt::ptime endTime;
    double rentCost;
    std::shared_ptr<RentObject> rentObject;
    bool active;

public:
    //Konstruktor
    Rent (const int id_, const shared_ptr<Client> client_, pt::ptime beginTime_, pt::ptime endTime_, shared_ptr<RentObject> rentObject_);

    //Destruktor
    ~Rent();

    //Gettery
    const string getRentInfo ();
    const double getRentCost ();
    const pt::time_period getRentPeriod ();
    const double getEndCost ();

    //Settery
    void endRent (pt::ptime);

};


#endif //RESTAURANT_RENT_H
