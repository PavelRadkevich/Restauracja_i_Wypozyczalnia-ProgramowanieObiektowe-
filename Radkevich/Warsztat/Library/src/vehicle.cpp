//
// Created by student on 04.04.2022.
//

#include "vehicle.h"
#include "iostream"
#include "boost/lexical_cast.hpp"
using namespace std;

namespace wypozyczalnia {


    vehicle::vehicle(const string plateNumber, const unsigned int basePrice) : plateNumber(plateNumber), basePrice (basePrice) {}
    vehicle::~vehicle() {}

    //gettery
    string vehicle::getVehicleInfo() {
        return "Registration number: " + plateNumber + " , price per day: " + boost::lexical_cast<string>(basePrice);
    }
    const string &vehicle::get_plateNumber() {
        return plateNumber;
    }
    const unsigned int &vehicle::get_basePrice() {
        return basePrice;
    }
    const bool &vehicle::is_rented() {
        return rented;
    }


    //settery
    void vehicle::set_basePrice(unsigned int &newPrice) {
            basePrice = newPrice;
    }
    void vehicle::set_plateNumber(std::string &newPlate) {
        if (newPlate != "")
            plateNumber = newPlate;
    }
    void vehicle::set_rented(bool rentednew) {
        rented = rentednew;
    }
    }
