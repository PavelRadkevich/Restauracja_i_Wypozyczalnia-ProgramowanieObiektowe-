//
// Created by pvlrd on 06.06.2022.
//

#ifndef RESTAURANT_RENTREPOSITORY_H
#define RESTAURANT_RENTREPOSITORY_H

#include <vector>
#include <memory>
using namespace std;


class Rent;
class Client;
class RentObject;
class RentRepository {
private:
    vector<shared_ptr<Rent>> vectorCurrentRents;
    vector<shared_ptr<Rent>> vectorArchiveRents;

public:
    //Konstruktor
    RentRepository ();

    //Destruktor
    ~RentRepository();

    //Gettery
    const shared_ptr<Rent> getRent (const int &ID) const;
    const vector<shared_ptr<Rent>> *getClientRents (const shared_ptr<Client> client_) const;
    const int getRepositorySize ()const;
    const vector<shared_ptr<Rent>> *getAllActualRents () const;
    const vector<shared_ptr<Rent>> *getAllArchiveRents () const;
    const shared_ptr<Rent> getRentObjectRent(const shared_ptr<RentObject> rentObject_) const;

    //Settery
    void addCurrentRent (const shared_ptr<Rent>);
    void archiveRent (const shared_ptr<Rent>);
    void removeRent (const shared_ptr<Rent>);

};


#endif //RESTAURANT_RENTREPOSITORY_H
