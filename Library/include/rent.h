//
// Created by student on 05.04.2022.
//

#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include "model/client.h"
#include "venicle.h"

namespace wypozyczalnia {
    class rent {
    private:
        unsigned int id;
        client* client1;
        venicle* venicle1;
    public:
    rent(const unsigned int &, client* , venicle*);
    ~rent();

    //gettery
    void getRentInfo () const;
    const std::string getId ();
    const std::string getClient ();
    const std::string getVenichle ();
    };

    //
}

#endif //CARRENTAL_RENT_H
