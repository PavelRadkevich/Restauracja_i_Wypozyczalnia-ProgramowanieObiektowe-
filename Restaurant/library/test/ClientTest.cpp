//
// Created by student on 13.06.2022.
//

#include "boost/test/unit_test.hpp"
#include "Client.h"
#include "Address.h"
#include "typedefs.h"
struct ClientFixture {
    int id = 1;
    string FirstName = "Jon";
    string LastName = "Arbuckle";
    int phone = 5312890;
    AddressPtr address;
    bool archive;

    ClientFixture() {
        address = make_shared<Address>("Homel", "Ilicha", 5312890);
    }

    ~ClientFixture() {
        //address.reset();
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, ClientFixture)

BOOST_AUTO_TEST_CASE(ClientConstrutor) {
        shared_ptr<Client> c = make_shared<Client>(id, FirstName, LastName, phone, address);
        BOOST_TEST(FirstName + " " + LastName == c->getNames());
        BOOST_TEST(phone == c->getClientPhone());
        BOOST_TEST(id == c->getId());
        BOOST_TEST(address == c->getAddress());
        BOOST_TEST(false == c->isArchive());
}

BOOST_AUTO_TEST_CASE(ClientSetters) {
        shared_ptr<Client> c = make_shared<Client>(id, FirstName, LastName, phone, address);
        c->setArchive(true);
        BOOST_TEST(true == c->isArchive());
}

BOOST_AUTO_TEST_SUITE_END()

