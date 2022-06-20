//
// Created by pvlrd on 06.06.2022.
//

#ifndef RESTAURANT_CLIENTREPOSITORY_H
#define RESTAURANT_CLIENTREPOSITORY_H

#include <vector>
#include <memory>
#include <string>
#include "typedefs.h"

using namespace std;
class ClientRepository {

private:
    vector<ClientPtr> vectorClient;

public:
    //Konstruktor
    ClientRepository ();

    //Destruktor
    ~ClientRepository();

    //Gettery
    const ClientPtr getClientByID (const int id) const;
    const int getRepositorySize () const;
    const vector<ClientPtr>* getAllClients () const;

    //Settery
    void addClient (const ClientPtr);
    void removeClient (const ClientPtr);
};


#endif //RESTAURANT_CLIENTREPOSITORY_H
