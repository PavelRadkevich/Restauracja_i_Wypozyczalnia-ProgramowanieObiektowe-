#include <iostream>
using namespace std;
#include "typedefs.h"
#include "Client.h"
#include "Personal.h"
#include "Hall.h"
int main()
{
    Hall h(20, 30, 40);
    Personal p(20, 50, 60, h);
    Address *a = new Address("Gomel", "Ilicha", 161);
    Client c("Ivan", "Trump", 445312890, *a);

    cout << p.getObjectInfo();
    return 0;
}

