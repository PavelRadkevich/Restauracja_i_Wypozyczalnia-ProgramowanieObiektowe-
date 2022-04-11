//
// Created by student on 04.04.2022.
//
#include <boost/test/unit_test.hpp>
#include "vehicle.h"
using namespace wypozyczalnia;

BOOST_AUTO_TEST_SUITE(TestSuiteVehicle)

    struct TestSuiteVehicleFixture {
        const std::string testplateNumber = "Homel";
        const unsigned int testbasePrice = 2;
        const bool testrented = true;

        TestSuiteVehicleFixture() {
        }

        ~TestSuiteVehicleFixture() {
        }

    };
    BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicle, TestSuiteVehicleFixture)

        BOOST_AUTO_TEST_CASE(VehicleConstruktor) {
            vehicle v (testplateNumber, testbasePrice);
            BOOST_TEST(testplateNumber == v.get_plateNumber());
            BOOST_TEST(testbasePrice == v.get_basePrice());
            BOOST_TEST(testrented == false);
        }


    BOOST_AUTO_TEST_SUITE_END()
}
