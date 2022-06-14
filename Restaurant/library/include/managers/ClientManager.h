//
// Created by pvlrd on 13.06.2022.
//

#ifndef RESTAURANT_CLIENTMANAGER_H
#define RESTAURANT_CLIENTMANAGER_H

#include <memory>
#include <vector>
using namespace std;

class Address;
class Client;
class ClientRepository;
class ClientManager {
private:
    shared_ptr<ClientRepository> repository;

public:
    //Konstruktor

    //Destruktor

    //Gettery
    static const shared_ptr<Client> getClient (const shared_ptr<ClientRepository> cr, const int &id);
    static const vector<shared_ptr<Client>> *getAllClients (const shared_ptr<ClientRepository> cr);

    //Settery
    static const shared_ptr<Client> registerClient (const shared_ptr<ClientRepository> cr, const int &id, const string& firstName_, const string& lastName_,
                                             const int& phone_, const shared_ptr<Address> &address_);
    static const void unregisterClient (const shared_ptr<ClientRepository> cr, shared_ptr<Client> client_);
};


#endif //RESTAURANT_CLIENTMANAGER_H
