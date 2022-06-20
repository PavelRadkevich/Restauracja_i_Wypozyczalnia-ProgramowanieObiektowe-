//
// Created by student on 18.03.2022.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H
#include "address.h"
#include "rent.h"
#include "vector"

namespace wypozyczalnia {
    class rent;
    class client {
    private:
        std::string firstName;
        std::string lastName;
        std::string personalID;
        address *CAddress;
        std::vector<rent> *numberRent;

    public:
        client(const std::string initial_firstName, const std::string initial_lastName, const std::string initial_personalID, address* address);
        ~client();



        //gettery
        std::string getClientinfo ();
        std::string getFullClientInfo ();
        const std::string &get_firstName ();
        const std::string &get_lastName ();
        const std::string &get_personalID ();
        const std::string get_address ();
        const address* get_addresswsk() const;

        //settery
        void set_firstName (const std::string&);
        void set_lastName (const std::string&);
        void set_personalID (const std::string&);
        void set_address (address*);
    };
}
#endif //CARRENTAL_CLIENT_H
