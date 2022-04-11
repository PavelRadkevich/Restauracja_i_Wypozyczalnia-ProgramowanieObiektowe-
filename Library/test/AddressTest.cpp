//
// Created by student on 29.03.2022.
//

#include <boost/test/unit_test.hpp>
#include "address.h"
using namespace wypozyczalnia;

BOOST_AUTO_TEST_SUITE(TestSuiteAddress)

    struct TestSuiteAddressFixture {
        const std::string testcity = "Homel";
        const std::string teststreet = "Ilicha";
        const std::string testnumber = "161";

        TestSuiteAddressFixture() {
        }

        ~TestSuiteAddressFixture() {
        }

    };
    BOOST_FIXTURE_TEST_SUITE(TestSuiteAddress, TestSuiteAddressFixture)

    BOOST_AUTO_TEST_CASE(AddressConstruktor) {
        address c (testcity, teststreet, testnumber);
        BOOST_TEST(testcity == c.get_city());
        BOOST_TEST(teststreet == c.get_street());
        BOOST_TEST(testnumber == c.get_number());
    }


BOOST_AUTO_TEST_SUITE_END()
}