#include <iostream>
#include <math_helpers.h>
#include "model/client.h"
#include "address.h"
#include "vehicle.h"
#include "rent.h"
#include <boost/date_time.hpp>
using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
int main() {
    wypozyczalnia::address* a1 = new wypozyczalnia::address ("Lodz", "Piotrkowska", "277");
    wypozyczalnia::address* a2 = new wypozyczalnia::address ("Homel", "Ilicha", "261");
    wypozyczalnia::client* c1 = new wypozyczalnia::client ("Krystian", "Cichon", "3568", a1);
    wypozyczalnia::client* c2 = new wypozyczalnia::client ("Kianu", "Riwz", "5297", a2);
    wypozyczalnia::vehicle* v1 = new wypozyczalnia::vehicle ("1234567", 300);
    wypozyczalnia::rent* r1 = new wypozyczalnia::rent (1, c1, v1);

    //cout << r1->getRentDays();






    pt::ptime empty = pt::not_a_date_time;
    cout << empty << endl;
    pt::ptime now = pt::second_clock::local_time();
    cout << now << endl;
    pt::ptime then = pt::ptime(gr::date(2015,5,13),pt::hours(9)+pt::minutes(25));
    cout << then << endl;
    pt::time_period period(then, now);
    cout << period << endl;
    cout << period.length() << endl;
    cout << period.length().hours() << endl;
    cout << period.length().minutes() << endl;
    cout << (then>now) << endl;
    cout << (then<=now) << endl;

    // konwersja ptime na string z użyciem stringstream
    std::stringstream ss;
    ss << now;
    string s = ss.str();
    cout << s << endl;

    return 0;


}