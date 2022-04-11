//
// Created by student on 05.04.2022.
//

#include "rent.h"
namespace wypozyczalnia{
    rent::rent(const unsigned int& id, client* client, venicle* venicle) : id(id), client1(client), venicle1(venicle)
    ~rent();

    //gettery
    void getRentInfo () const{
        return client::getClientinfo() + ". ID: " + id + ". Pojazd: " + venicle::getVenichleInfo();
    }
    const std::string getId ();
    const std::string getClient ();
    const std::string getVenichle ();


}