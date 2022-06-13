//
// Created by student on 29.03.2022.
//

#ifndef CARRENTAL_ADRESS_H
#define CARRENTAL_ADRESS_H
#include "string"
namespace wypozyczalnia {
    class address {
    private:
        std::string city;
        std::string street;
        std::string number;

    public:
        address(const std::string &icity, const std::string &istreet, const std::string &inumber);
        ~address();

        //gettery
        const std::string getAddressInfo ();
        const std::string &get_city ();
        const std::string &get_street ();
        const std::string &get_number ();

        //settery
        //void set_city (std::string);
        //void set_street (std::string);
        //void set_number (std::string);
    };
}
#endif //CARRENTAL_ADRESS_H
