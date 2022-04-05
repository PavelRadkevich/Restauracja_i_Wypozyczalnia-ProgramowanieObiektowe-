//
// Created by student on 18.03.2022.
//
#include "iostream"
#include "model/client.h"

using namespace std;

namespace wypozyczalnia {

        //konstruktor
        client::client(string initial_firstName, string initial_lastName, string initial_personalID) :
        firstName(initial_firstName) , lastName(initial_lastName), personalID(initial_personalID)  {
            //cout << "Konstruktor wywolany" << client::getClientinfo() << endl;
        }

        //destruktor
        client::~client() {
            //cout << "Destruktor wywolany" << " " << client::getClientinfo() <<  endl;
        }

        string client::getClientinfo() {
        return  client::firstName + " " + client::lastName + " " + client::personalID;
        }

        //gettery
        string client::get_firstName() {
        return firstName;
        }
        string client::get_lastName() {
        return lastName;
        }
        string client::get_personalID() {
        return personalID;
        }

        //settery
        void client::set_firstName(string fname) {
            if (fname != "")
            firstName = fname;
        }
        void client::set_lastName(string lname) {
            if (lname != "")
            lastName = lname;
        }
        void client::set_personalID(string ID) {
            if (ID != "")
            personalID = ID;
        }

    //settery

}
