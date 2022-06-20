#include <iostream>
#include "typedefs.h"
#include "Client.h"
#include "Personal.h"
#include "Hall.h"
#include "Group.h"
#include "Address.h"
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
    shared_ptr<RentObjectManager> rom = make_shared<RentObjectManager>(ror);
    shared_ptr<ClientManager> cm = make_shared<ClientManager>(cr);
    shared_ptr<RentManager> rm = make_shared<RentManager>(rr);
    shared_ptr<Hall> h1 = rom->registerHall(20, 30, 0.90, "Emilia");
    shared_ptr<Hall> h2 = rom->registerHall(5, 15, 0.50, "Agata");
    shared_ptr<Personal> p = rom->registerPersonalTable(20, 2, 60, 15);
    shared_ptr<Group> g = rom->registerGroupTable(100, 44, 20, 12, 0.432678);
    shared_ptr<Address> a (new Address("Gomel", "Ilicha", 161));
    shared_ptr<Client> c = cm->registerClient(1, "Ivan", "Trump", 445312890, a);

    cout << "STWORZONE 6 OBJEKTOW: " << endl;
    cout << "PIERWSZA SALA: " <<  h1->getObjectInfo() << endl;
    cout << "DRUGA SALA: " << h2->getObjectInfo() << endl;
    cout << "PRYWATNY STOLIK: " << p->getObjectInfo() << endl;
    cout << "GRUPOWY STOLIK: " << g->getObjectInfo() << endl;
    cout << "ADRES: " << a->getAddressInfo() << endl;
    cout << "KLIENT: " << c->getClientInfo() << endl;

    cout << "///////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    rom->changeHall(h1, g);
    cout << "USTAWIAMY SALE DLA STOLIKA: " << g->getObjectInfo() << endl;

    cout << "///////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    pt::ptime then = pt::ptime(gr::date(2022,8,15),pt::hours(10) + pt::minutes(0));
    pt::ptime before = pt::ptime(gr::date(2022,8,15),pt::hours(11) + pt::minutes(30));
    pt::ptime before2 = pt::ptime(gr::date(2022,8,15),pt::hours(12) + pt::minutes(30));
    pt::time_period period (then, before);
    cout << "WYNAJMUJEMY STOLIK NA PERIOD: " << period.length().hours()  << " godzina, " << period.length().minutes() << " minut" << endl;
    auto r = rm->startRent(1, c, then, before , g, false);
    cout << "INFO O WYNAJMU: " << endl << r->getRentInfo() << endl;
    cout << "///////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    rm->endRent(g, before2);
    cout << "KONCZYMY WYNAJEM Z INNYM CZASEM" << endl;
    cout << "KONCOWA CENA: " << r->getEndCost() << endl;
    cout << "INFO O WYNAJMU: " << endl <<  r->getRentInfo() << endl;
}

