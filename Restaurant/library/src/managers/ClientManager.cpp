//
// Created by pvlrd on 13.06.2022.
//

#include "managers/ClientManager.h"
#include "repositories/ClientRepository.h"
#include "Client.h"
#include "exceptions/ManagersExceptions.h"

//Konstruktor
ClientManager::ClientManager(const shared_ptr<ClientRepository> cm): repository(cm) {}
//Destruktor
ClientManager::~ClientManager() {}

//Gettery
const shared_ptr<Client> ClientManager::getClient(const int &id){
    return repository->getClientByID(id);
}

const vector<shared_ptr<Client>> *ClientManager::getAllClients(){
    return repository->getAllClients();
}


//Settery
const shared_ptr<Client>
ClientManager::registerClient(const int &id, const string &firstName_, const string &lastName_, const int &phone_,
                              const shared_ptr<Address> &address_) {
    if (repository->getClientByID(id) != nullptr)
        return repository->getClientByID(id);
    else {
        shared_ptr<Client> client = make_shared<Client>(id, firstName_, lastName_, phone_, address_);
        repository->addClient(client);
        return client;
    }

    return shared_ptr<Client>();
}

const void ClientManager::unregisterClient(shared_ptr<Client> client_) {
    if (repository->getClientByID(client_->getId()) == nullptr)
        throw ManagersExceptions("CLIENT NOT REGISTERED!");
    else {
        client_->setArchive(true);
    }
}

