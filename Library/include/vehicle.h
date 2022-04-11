//
// Created by student on 04.04.2022.
//

#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H
#include <string>

namespace wypozyczalnia {
    class vehicle {
    private:
        std::string plateNumber;
        unsigned int basePrice;

    public:
        vehicle(const std::string plateNumber, const unsigned  int basePrice);
        ~vehicle();

        //gettery
        const std::string getVenicleInfo ();
        const std::string &get_plateNumber ();
        const unsigned int &get_basePrice ();

        //settery
        void set_plateNumber (std::string&);
        void set_basePrice (unsigned int &);
    };


}

#endif CARRENTAL_VEHICLE_H
