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
const shared_ptr<Client> ClientRepository::getClient(const int phone) const {
    for (auto t = vectorClient.begin(); t < vectorClient.end(); t++)
    {
        if ((*t)->getClientPhone() == phone)
            return (*t);
    }
    return nullptr;
}

const int ClientRepository::getClientSize() {
    return vectorClient.size();
}

const string ClientRepository::getAllClients() {
    string info = "";
    for (auto t = vectorClient.begin(); t < vectorClient.end(); t++)
    {
        info = info + (*t)->getClientInfo() + "\n";
    }
    return info;
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

