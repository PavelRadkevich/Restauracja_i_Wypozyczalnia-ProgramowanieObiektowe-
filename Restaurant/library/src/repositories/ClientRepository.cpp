//
// Created by pvlrd on 06.06.2022.
//

#include "repositories/ClientRepository.h"
#include "Client.h"
//Konstruktor
ClientRepository::ClientRepository() {}

//Destruktor
ClientRepository::~ClientRepository() {}

//Gettery
const shared_ptr<Client> ClientRepository::getClientByID(const int id) const {
    for (auto t = vectorClient.begin(); t < vectorClient.end(); t++)
    {
        if ((*t)->getClientPhone() == id)
            return (*t);
    }
    return nullptr;
}

const int ClientRepository::getRepositorySize() const {
    return vectorClient.size();
}

const vector<shared_ptr<Client>>* ClientRepository::getAllClients() const {
    return &vectorClient;
}

//Settery
void ClientRepository::addClient(const shared_ptr<Client> ror) {
    vectorClient.push_back(ror);
}

void ClientRepository::removeClient(const shared_ptr<Client> ror) {
    for (auto t = vectorClient.begin(); t < vectorClient.end(); t++){
        if ((*t) == ror )
            vectorClient.erase(t);
    }
}
