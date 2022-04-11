//
// Created by student on 29.03.2022.
//
//
// Created by student on 18.03.2022.
//
#include "iostream"
#include "address.h"


using namespace std;

namespace wypozyczalnia {

    //konstruktor
    address::address(const string &icity, const string &istreet, const string &inumber) :
            city(icity), street(istreet), number(inumber) {
        //cout << "Konstruktor wywolany" << client::getClientinfo() << endl;
    }

    //destruktor
    address::~address() {
        //cout << "Destruktor wywolany" << " " << client::getClientinfo() <<  endl;
    }

    //gettery

    const string address::getAddressInfo() {
        return address::city + ", " + address::street + ", " + address::number;
    }

    const string &address::get_city() {
        return city;
    }

    const string &address::get_street() {
        return street;
    }

    const string &address::get_number() {
        return number;
    }

    //settery
    /*void address::set_city(std::string newcity) {
        if (newcity != "")
            city = newcity;
    }

    void address::set_street(std::string newstreet) {
        if (newstreet != "")
            street = newstreet;
    }

    void address::set_number(std::string newnumber) {
        if (newnumber != "")
            number = newnumber;
    }*/

}