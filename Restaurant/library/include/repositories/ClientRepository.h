//
// Created by pvlrd on 06.06.2022.
//

#ifndef RESTAURANT_CLIENTREPOSITORY_H
#define RESTAURANT_CLIENTREPOSITORY_H

//#include "Client.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;
class Client;
class ClientRepository {

private:
    vector<shared_ptr<Client>> vectorClient;

public:
    //Konstruktor
    ClientRepository ();

    //Destruktor
    ~ClientRepository();

    //Gettery
    const shared_ptr<Client> getClientByID (const int phone) const;
    const int getRepositorySize () const;
    const vector<shared_ptr<Client>>* getAllClients () const;

    //Settery
    void addClient (const shared_ptr<Client>);
    void removeClient (const shared_ptr<Client>);
};


#endif //RESTAURANT_CLIENTREPOSITORY_H
