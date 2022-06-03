//
// Created by student on 03.06.2022.
//

#ifndef RESTAURANT_RENT_H
#define RESTAURANT_RENT_H

#include "boost/date_time.hpp"
namespace pt = boost::posix_time;

class Rent {
private:
    int id;
    pt::ptime beginTime;
    pt::ptime endTIme;
    int rentCost;
    //RentObjectPtr rentObject;


};


#endif //RESTAURANT_RENT_H
