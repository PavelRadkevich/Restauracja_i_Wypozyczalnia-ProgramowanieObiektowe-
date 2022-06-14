#include <iostream>
#include "typedefs.h"
#include "Client.h"
#include "Personal.h"
#include "Hall.h"
#include "Group.h"
#include "repositories/RentObjectRepository.h"
#include "repositories/ClientRepository.h"
#include "repositories/RentRepository.h"
#include "Rent.h"
#include "managers/ClientManager.h"
#include "managers/RentManager.h"
#include "managers/RentObjectManager.h"

using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

int main()
{
    shared_ptr<ClientRepository> cr = make_shared<ClientRepository>();
    shared_ptr<RentObjectRepository> ror = make_shared<RentObjectRepository>();
    shared_ptr<RentRepository> rr = make_shared<RentRepository>();
    shared_ptr<Hall> h1 = RentObjectManager::registerHall(ror, 20, 30, 0.90, "Emilia");
    shared_ptr<Hall> h2 = RentObjectManager::registerHall(ror, 5, 15, 0.50, "Agata");
    shared_ptr<Personal> p = RentObjectManager::registerPersonalTable(ror, 20, 2, 60, 15);
    shared_ptr<Group> g = RentObjectManager::registerGroupTable(ror, 100, 44, 20, 12, 0.432678);
    shared_ptr<Address> a (new Address("Gomel", "Ilicha", 161));
    shared_ptr<Client> c = ClientManager::registerClient(cr, 1, "Ivan", "Trump", 445312890, a);

    cout << "STWORZONE 6 OBJEKTÓW: " << endl;
    cout << "PIERWSZA SALA: " <<  h1->getObjectInfo() << endl;
    cout << "DRUGA SALA: " << h2->getObjectInfo() << endl;
    cout << "PRYWATNY STOLIK: " << p->getObjectInfo() << endl;
    cout << "GRUPOWY STOLIK: " << g->getObjectInfo() << endl;
    cout << "ADRES: " << a->getAddressInfo() << endl;
    cout << "KLIENT: " << c->getClientInfo() << endl;

    cout << "///////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;


    cout << h2->getHallSize() << endl;
    cout << h1->getHallSize() << endl;

    //p->changeHall(h1, p);
    cout << h2->getHallSize() << endl;
    cout << h1->getHallSize() << endl;
    //p->changeHall(h1, p);
    cout << h2->getHallSize() << endl;
    cout << h1->getHallSize() << endl;

    cout << p->getObjectInfo() << endl;


    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;


    //cout << p->getActualPriceForHour() << endl;
    //cout << g->getActualPriceForHour() << endl;

    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    ror->addRentObject(p);
    ror->addRentObject(h1);
    ror->addRentObject(h2);
    cout << ror->getAllRentObjects() << endl;

    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

    pt::ptime then = pt::ptime(gr::date(2022,8,15),pt::hours(10) + pt::minutes(0));
    pt::ptime after = pt::ptime(gr::date(2023,5,15),pt::hours(10) + pt::minutes(30));
    pt::ptime before = pt::ptime(gr::date(2022,8,15),pt::hours(11) + pt::minutes(30));
    pt::time_period period (then, before);
    cout << "PERIOD :       " << period.length().hours()  << " " << period.length().minutes() << endl;
    cout <<  period.length().minutes()<< endl  << "!!!!!!!!!" << endl;
    auto r = new Rent(1, c, then, after , g, 0);
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    cout << r->getRentInfo() << endl;
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    cout << r->getRentCost();
    r->endRent(before);
    cout << endl << r->getEndCost();
    cout << endl << p->getTablePtr() << endl;

    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

    cout << h2->getIDOfTablesOfHall() << "      " << h2->getHallSize() << endl;
    cout << h1->getIDOfTablesOfHall() << "      " << h1->getHallSize() << endl;

    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

    auto rH = new Rent(2, c, then, before, h1, 1);
    cout << rH->getRentInfo() << "\n\n" << rH->getRentCost();

}

