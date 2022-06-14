//
// Created by pvlrd on 13.06.2022.
//

#include "managers/ClientManager.h"
#include "repositories/ClientRepository.h"
#include "Client.h"
#include "exceptions/ManagersExceptions.h"

//Konstruktor

//Destruktor


//Gettery
const shared_ptr<Client> ClientManager::getClient(const shared_ptr<ClientRepository> cr, const int &id){
    return cr->getClientByID(id);
}

const vector<shared_ptr<Client>> *ClientManager::getAllClients(const shared_ptr<ClientRepository> cr){
    return cr->getAllClients();
}


//Settery
const shared_ptr<Client>
ClientManager::registerClient(const shared_ptr<ClientRepository> cr, const int &id, const string &firstName_, const string &lastName_, const int &phone_,
                              const shared_ptr<Address> &address_) {
    if (cr->getClientByID(id) != nullptr)
        return cr->getClientByID(id);
    else {
        shared_ptr<Client> client = make_shared<Client>(id, firstName_, lastName_, phone_, address_);
        cr->addClient(client);
        return client;
    }

    return shared_ptr<Client>();
}

const void ClientManager::unregisterClient(const shared_ptr<ClientRepository> cr, shared_ptr<Client> client_) {
    if (cr->getClientByID(client_->getId()) == nullptr)
        throw ManagersExceptions("CLIENT NOT REGISTERED!");
    else {
        client_->setArchive(true);
    }
}

