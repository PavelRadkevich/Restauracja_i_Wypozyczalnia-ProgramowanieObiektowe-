#include <iostream>
using namespace std;
#include "typedefs.h"
#include "Client.h"
#include "Personal.h"
#include "Hall.h"
#include "Group.h"
int main()
{
    Hall h1(20, 30, 0.90, "Emilia");
    Hall h2(5, 15, 0.50, "Agata");
    Personal p(20, 2, 60, h1, 15);
    Group g(100, 44, 20, h1, 12, 0.432678);
    Address *a = new Address("Gomel", "Ilicha", 161);
    Client c("Ivan", "Trump", 445312890, *a);

    cout << p.getObjectInfo() << endl;
    cout << h1.getObjectInfo() << endl;
    cout << g.getObjectInfo() << endl;

    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

    cout << p.getActualPriceForHour() << endl;
    cout << g.getActualPriceForHour() << endl;

    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

    p.changeHall(make_shared<Hall>(h2));

    cout << p.getObjectInfo();
    return 0;
}

