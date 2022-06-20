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
        bool rented = false;

    public:
        vehicle(const std::string plateNumber, const unsigned  int basePrice);
        ~vehicle();

        //gettery
        std::string getVehicleInfo ();
        const std::string &get_plateNumber ();
        const unsigned int &get_basePrice ();
        const bool &is_rented ();

        //settery
        void set_plateNumber (std::string&);
        void set_basePrice (unsigned int &);
        void set_rented (bool);
    };


}

#endif //CARRENTAL_VEHICLE_H
