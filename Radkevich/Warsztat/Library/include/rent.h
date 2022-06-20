//
// Created by student on 05.04.2022.
//

#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H
#include "string"
#include "boost/date_time.hpp"

namespace wypozyczalnia {
    class vehicle;
    class client;

    class rent {
    private:
        unsigned int id;
        client* client_rent;
        vehicle* vehicle_rent;
        boost::posix_time::ptime beginTime;
        boost::posix_time::ptime endTime;

    public:
    rent(const unsigned int &, client* , vehicle*);
    ~rent();

    //gettery
    std::string getRentInfo () const;
    const unsigned int &getId ();
    const std::string &getClient ();
    void getVehichle ();
    const boost::posix_time::ptime getBeginTime ();
    const boost::posix_time::ptime getEndTime ();
    const std::string getRentDays();


    //settery
    void endRent (boost::posix_time::ptime &);
    };
}

#endif //CARRENTAL_RENT_H
