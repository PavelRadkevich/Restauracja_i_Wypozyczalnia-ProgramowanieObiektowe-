//
// Created by student on 20.06.2022.
//
#include "Rent.h"
#include "boost/test/unit_test.hpp"
#include "Personal.h"
#include "Hall.h"
#include "Client.h"
#include "Address.h"
#include "typedefs.h"
#include "managers/RentObjectManager.h"
#include "repositories/RentObjectRepository.h"
#include "exceptions/RentExceptions.h"
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

struct RentFixture {
    int id = 1;
    AddressPtr address = make_shared<Address>("Homel", "Ilicha", 5312890);
    ClientPtr client = make_shared<Client>(1, "Jon", "Uick", 240365, address);
    pt::ptime beginTime = pt::ptime(gr::date(2022,8,15),pt::hours(10) + pt::minutes(0));
    pt::ptime after = pt::ptime(gr::date(2023,5,15),pt::hours(10) + pt::minutes(30));
    pt::ptime endTime = pt::ptime(gr::date(2022,8,15),pt::hours(15) + pt::minutes(30));
    HallPtr hall = make_shared<Hall>(50, 2, 0.2, "Krystian");
    PersonalPtr personal = make_shared<Personal>(10, 1, 13, 1);
    RentRepositoryPtr ror;
    RentObjectManagerPtr rom;

    RentFixture() {
        RentObjectRepositoryPtr ror = make_shared<RentObjectRepository>();
        RentObjectManagerPtr rom = make_shared<RentObjectManager>(ror);
    };

    ~RentFixture() {
        hall.reset();
        personal.reset();
        address.reset();
        client.reset();
        ror.reset();
        rom.reset();
    }
};

BOOST_FIXTURE_TEST_SUITE(RentTest, RentFixture)

BOOST_AUTO_TEST_CASE(RentConstructorTest){
    rom->changeHall(hall, personal);
    RentPtr rent = make_shared<Rent>(id, client, beginTime, endTime, personal, false);
        BOOST_TEST (rent->getID() == id);
        BOOST_TEST (rent->getClient() == client);
        BOOST_TEST (rent->getRentObject() == personal);
        BOOST_TEST (rent->isArchive() == false);
        BOOST_TEST (personal->isRented() == true);
}

    BOOST_AUTO_TEST_CASE(RentConstructorExceptionsTest){
        BOOST_CHECK_THROW(make_shared<Rent>(id, client, beginTime, endTime, personal, false), RentExceptions);
        rom->changeHall(hall, personal);
    }


BOOST_AUTO_TEST_SUITE_END()
