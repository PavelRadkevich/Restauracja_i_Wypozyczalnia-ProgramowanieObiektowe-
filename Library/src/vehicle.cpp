//
// Created by student on 04.04.2022.
//

#include "vehicle.h"
#include "iostream"
using namespace std;

namespace wypozyczalnia {

    //konstruktor
    vehicle::vehicle(const std::string plateNumber, const unsigned int basePrice) : plateNumber(plateNumber), basePrice (basePrice) {
        //cout << "Konstruktor wywolany" << client::getClientinfo() << endl;
    }

    //destruktor
    vehicle::~vehicle() {
        //cout << "Destruktor wywolany" << " " << client::getClientinfo() <<  endl;
    }

    //gettery

    const string vehicle::getVenicleInfo() {
        cout << plateNumber << " ," << basePrice;
        return plateNumber;
    }

    const string &vehicle::get_plateNumber() {
        return plateNumber;
    }

    const unsigned int &vehicle::get_basePrice() {
        return basePrice;
    }


    //settery
    void vehicle::set_basePrice(unsigned int &newPrice) {
            basePrice = newPrice;
    }

    void vehicle::set_plateNumber(std::string &newPlate) {
        if (newPlate != "")
            plateNumber = newPlate;
    }

    }
