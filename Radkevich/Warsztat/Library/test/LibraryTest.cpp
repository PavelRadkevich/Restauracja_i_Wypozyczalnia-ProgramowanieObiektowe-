//
// Created by student on 28.03.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/client.h"
using namespace wypozyczalnia;
BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    struct TestSuiteClientFixture {
        const std::string testFirstName = "Jon";
        const std::string testLastName = "Arbuckle";
        const std::string testPersonalID = "0123456789";
        address *testaddress1;
        address *testaddress2;

        TestSuiteClientFixture() {
            testaddress1 = new address("London", "Accacia Avenue", "22");
            testaddress2 = new address("London", "Rue Morgue", "13");
        }

        ~TestSuiteClientFixture() {
            delete testaddress1;
            delete testaddress2;
        }

    };

    BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

        BOOST_AUTO_TEST_CASE(ClientParameterConstrutorTest) {

            client c(testFirstName, testLastName, testPersonalID, testaddress1);
            BOOST_TEST(testFirstName == c.get_firstName());
            BOOST_TEST(testLastName == c.get_lastName());
            BOOST_TEST(testPersonalID == c.get_personalID());
            BOOST_TEST(testaddress1->getAddressInfo() == c.get_address());
        }

        BOOST_AUTO_TEST_CASE(ClientEmptySettersTest) {
            client c(testFirstName, testLastName, testPersonalID, testaddress1);
            c.set_firstName("");
            c.set_lastName("");
            c.set_personalID("");
            BOOST_TEST(testFirstName == c.get_firstName());
            BOOST_TEST(testLastName == c.get_lastName());
            BOOST_TEST(testPersonalID == c.get_personalID());
        }
        BOOST_AUTO_TEST_CASE(ClientSettersTest) {
            client c(testFirstName, testLastName, testPersonalID, testaddress1);
            c.set_firstName("Marek");
            c.set_lastName("Schod");
            c.set_personalID("240367");
            BOOST_TEST("Marek" == c.get_firstName());
            BOOST_TEST("Schod" == c.get_lastName());
            BOOST_TEST("240367" == c.get_personalID());
        }

        }
    BOOST_AUTO_TEST_SUITE_END()
