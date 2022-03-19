#include <iostream>
#include <math_helpers.h>
#include "model/client.h"
using namespace std;
int main() {
cout << "Hello World!"  << endl << factorial(5) << endl;
wypozyczalnia::client h1 ("Leon", "Nowak", "1234");
wypozyczalnia::client *h2 = new wypozyczalnia::client("Now", "LOt", "4567");


cout << h1.getClientinfo() << endl;
h1.set_firstName("");
cout << h1.getClientinfo() << endl;
//cout << h2->getClientinfo() << endl;
delete h2;

}
