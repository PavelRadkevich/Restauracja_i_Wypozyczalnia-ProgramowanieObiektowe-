//
// Created by student on 05.04.2022.
//

#include "rent.h"
#include "iostream"
#include "model/client.h"
#include "vehicle.h"
#include "boost/lexical_cast.hpp"

namespace pt = boost::posix_time;

namespace wypozyczalnia{
    rent::rent(const unsigned int& id, client* client, vehicle* vehicle): id(id), client_rent(client), vehicle_rent(vehicle){
        vehicle_rent->set_rented(true);
        beginTime = pt::second_clock::local_time();
    }
    rent::~rent() {}

    //gettery
    std::string rent::getRentInfo() const {
        return "Client: " +  client_rent->getClientinfo() + ".\nID: " + boost::lexical_cast<std::string>(id) + ". \nVehicle info: "
        + vehicle_rent->getVehicleInfo() + "\nStart of renting: " + boost::lexical_cast<std::string>(beginTime) + "\nEnd of renting: "
        + boost::lexical_cast<std::string>(endTime);
        }
    const unsigned int &rent::getId () {
        return id;
    }
    const std::string &rent::getClient (){
        return client_rent->getClientinfo();
    }
    void rent::getVehichle (){
        vehicle_rent->getVehicleInfo();
    }
    const pt::ptime rent::getBeginTime() {
        return beginTime;
    }
    const pt::ptime rent::getEndTime (){
        return endTime;
    }
    const std::string rent::getRentDays(){
        pt::time_period period(endTime, beginTime);
        std::string periods = boost::lexical_cast<std::string>(period.length().)
        return period.length().
    }

    //settery
    void rent::endRent (boost::posix_time::ptime &time){
        if (endTime != pt::not_a_date_time) {
            std::cout << "The time has already been set!";
            return;
        }
        if (time == pt::not_a_date_time){
            endTime = pt::second_clock::local_time();
            return;
        }
        if (time < beginTime) {
            endTime = beginTime;
            return;
        }
        time = endTime;
    }
}