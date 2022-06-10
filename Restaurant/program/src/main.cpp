#include <iostream>
#include "typedefs.h"
#include "Client.h"
#include "Personal.h"
#include "Hall.h"
#include "Group.h"
#include "repositories/RentObjectRepository.h"
#include "Rent.h"

using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

int main()
{
    Hall h1(20, 30, 0.90, "Emilia");
    Hall h2(5, 15, 0.50, "Agata");
    Personal p(20, 2, 60, h1, 15);
    Group g(100, 44, 20, h1, 12, 0.432678);
    auto *a = new Address("Gomel", "Ilicha", 161);
    Client c("Ivan", "Trump", 445312890, *a);

    cout << p.getObjectInfo() << endl;
    cout << h1.getObjectInfo() << endl;
    cout << g.getObjectInfo() << endl;

    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

    cout << p.getActualPriceForHour() << endl;
    cout << g.getActualPriceForHour() << endl;

    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

    p.changeHall(make_shared<Hall>(h2));

    cout << p.getObjectInfo() << endl;
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    RentObjectRepository ror;
    ror.addRentObject(make_shared<RentObject>(p));
    ror.addRentObject(make_shared<RentObject>(h1));
    ror.addRentObject(make_shared<RentObject>(h2));
    cout << ror.getAllRentObjects() << endl;

    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

    pt::ptime then = pt::ptime(gr::date(2022,8,15),pt::hours(10) + pt::minutes(0));
    pt::ptime after = pt::ptime(gr::date(2023,5,15),pt::hours(10) + pt::minutes(30));
    pt::ptime before = pt::ptime(gr::date(2022,8,15),pt::hours(11) + pt::minutes(30));
    pt::time_period period (then, before);
    cout << "PERIOD :       " << period.length().hours()  << " " << period.length().minutes() << endl;
    cout <<  period.length().minutes()<< endl  << "!!!!!!!!!" << endl;
    Rent r (1, make_shared<Client>(c), then, after , make_shared<RentObject>(g));
    cout << r.getRentCost();
    r.endRent(before);
    cout << endl << r.getEndCost();


    if (p.getTablePtr() == nullptr)
        cout << "БЛЯЯЯЯЯЯТЬ!!!!!!!!1";
    return 0;
}

