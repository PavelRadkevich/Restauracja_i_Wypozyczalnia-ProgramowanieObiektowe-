//
// Created by student on 18.03.2022.
//
#include "iostream"
#include "model/client.h"
#include "boost/lexical_cast.hpp"


using namespace std;

namespace wypozyczalnia {

        //konstruktor
        client::client(const string initial_firstName, const string initial_lastName, const string initial_personalID, address* address) :
        firstName(initial_firstName) , lastName(initial_lastName), personalID(initial_personalID), CAddress(address)  {
            //cout << "Konstruktor wywolany" << client::getClientinfo() << endl;
        }

        //destruktor
        client::~client() {
            //cout << "Destruktor wywolany" << " " << client::getClientinfo() <<  endl;
            //delete CAddress;
        }

        //gettery
        string client::getClientinfo() {
            return  client::firstName + " " + client::lastName + " " + client::personalID + ". Address of client: " +
                    client::CAddress->getAddressInfo();
        }
        std::string client::getFullClientInfo() {
        return client::getClientinfo() + ". Actual number of rents: " + boost::lexical_cast<string>(numberRent);
        }
        const string &client::get_firstName() {
        return firstName;
        }
        const string &client::get_lastName() {
        return lastName;
        }
        const string &client::get_personalID() {
        return personalID;
        }
        const string client::get_address() {
            return CAddress->getAddressInfo();
        }
        const address* client::get_addresswsk() const{
        return CAddress ;
    }

        //settery
        void client::set_firstName(const string &fname) {
            if (fname != "")
            firstName = fname;
        }
        void client::set_lastName(const string &lname) {
            if (lname != "")
            lastName = lname;
        }
        void client::set_personalID(const string &ID) {
            if (ID != "")
            personalID = ID;
        }
        void client::set_address(address *newaddress) {
            CAddress = newaddress;
        }

    //settery

}
