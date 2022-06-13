//
// Created by student on 13.06.2022.
//
#include <boost/test/unit_test.hpp>
#include "Address.h"
#include "master.cpp"

struct AddressFixture {
    string city = "Homel";
    string street = "Ilicha";
    int number = 445312890;

    AddressFixture() {}

    ~AddressFixture() {}

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteAddress, AddressFixture)

    BOOST_AUTO_TEST_CASE(AddressConstructor) {
        shared_ptr<Address> a = make_shared<Address>(city, street, number);
        BOOST_TEST(city + ", " + street + ", " + std::to_string(number) == a->getAddressInfo());
    }
BOOST_AUTO_TEST_SUITE_END()

