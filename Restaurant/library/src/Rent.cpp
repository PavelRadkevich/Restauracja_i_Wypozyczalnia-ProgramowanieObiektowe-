//
// Created by student on 03.06.2022.
//

#include "Rent.h"
#include "exceptions/RentExceptions.h"
#include "Client.h"
#include "RentObject.h"

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;


//Konstruktor
Rent::Rent(const int id_, const shared_ptr<Client> client_, pt::ptime beginTime_, pt::ptime endTime_, shared_ptr<RentObject> rentObject_):
id(id_), client(client_), beginTime(beginTime_), endTime(endTime_), rentObject(rentObject_) {
    if (beginTime < pt::second_clock::local_time() || beginTime == pt::not_a_date_time) throw RentExceptions("INVALID BEGIN TIME");
    if (endTime < beginTime || endTime == pt::not_a_date_time) throw RentExceptions("INVALID END TIME");
    if (client == nullptr) throw RentExceptions("INVALID CLIENT");
    if (rentObject == nullptr) throw RentExceptions("INVALID RENT OBJECT");
    active = true;

    if (!rentObject->isRented())
        rentObject->setRented(true);
    else
        throw RentExceptions("THE RENT OBJECT IS ALREADY RENTED!");

    /*if (rentObject->getTablePtr() == nullptr){
        for ( auto t = rentObject->getTablesOfHall()->begin(); t < rentObject->getTablesOfHall()->end(); t++)
           (*t)->setRented(true);

    }*/
}

//Destruktor
Rent::~Rent(){}


//Gettery
const string Rent::getRentInfo() {
    std::stringstream ss, ds;
    ss << beginTime;
    ds << endTime;
    string bt = ss.str(), et = ds.str();
    return "ID of rent: " + to_string(id) + ".\nClient: " + client->getNames() + ".\nRent from " + bt + ", to " + et + ".\nObject of rent: " + rentObject->getObjectInfo();
}

const double Rent::getRentCost() {
    if (rentObject->getTablePtr() != nullptr) {
        pt::time_period period(beginTime, endTime);
        return (rentObject->getCost() * period.length().hours()) + (rentObject->getCost() * period.length().minutes() / 60);
    }
}

const pt::time_period Rent::getRentPeriod() {

    pt::time_period period (beginTime, endTime);
    return period;
}

const double Rent::getEndCost() {
    if (!active)
    return rentCost;
    else throw RentExceptions("END COST BEFORE END OF RENT!");
}


//Settery
void Rent::endRent(pt::ptime end) {
    if (end == pt::not_a_date_time)
    {}
        else
    {
        if (end > beginTime || end < pt::second_clock::local_time())
            endTime = end;
        else
            throw RentExceptions("INVALID END TIME AT THE END OF RENT!");
    }
    pt::time_period period (beginTime, endTime);
    active = false;
    rentCost = (rentObject->getCost() * period.length().hours()) +(rentObject->getCost() * period.length().minutes() / 60);

}


