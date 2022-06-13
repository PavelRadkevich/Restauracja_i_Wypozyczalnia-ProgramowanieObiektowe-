//
// Created by student on 13.06.2022.
//
#include "boost/test/unit_test.hpp"
#include "Personal.h"
#include "Group.h"
#include "Hall.h"
#include "exceptions/RentObjectExceptions.h"
#include "RentObject.h"
#include "managers/RentObjectManager.h"

struct RentObjectFixture {
    int basePrice1 = 10; int basePrice2 = 20; int basePrice3 = 30; int basePrice4 = 30;
    int objectID1 = 2; int objectID2 = 3; int objectID3 = 4; int objectID4 = 4;
    int capacity1 = 10; int capacity2 = 15;
    int numberOfTable1 = 5; int numberOfTable2 = 4;
    double sale = 0.2;
    double priceFactor1 = 0.5; double priceFactor2 = 0.4;
    const std::string name1 = "Kaczka"; const std::string name2 = "Uroda";

    RentObjectFixture() {};

    ~RentObjectFixture() {};
};

BOOST_FIXTURE_TEST_SUITE(RentObjectTest, RentObjectFixture)

    BOOST_AUTO_TEST_CASE(PersonalConstructor) {
        shared_ptr<Personal> p = make_shared<Personal>(basePrice1, objectID1, capacity1, numberOfTable1);
        BOOST_TEST (basePrice1 == p->getBasePrice());
        BOOST_TEST (objectID1 == p->getObjectID());
        BOOST_TEST (capacity1 == p->getCapacity());
        BOOST_TEST (numberOfTable1 == p->getTableNumber());
        BOOST_TEST (!p->isArchive());
        BOOST_TEST (!p->isRented());
        BOOST_CHECK_THROW(p->getCost(), RentObjectExceptions);
    }

    BOOST_AUTO_TEST_CASE(GroupConstructor) {
        shared_ptr<Group> g = make_shared<Group>(basePrice2, objectID2, capacity2, numberOfTable2, sale);
        BOOST_TEST (basePrice2 == g->getBasePrice());
        BOOST_TEST (objectID2 == g->getObjectID());
        BOOST_TEST (capacity2 == g->getCapacity());
        BOOST_TEST (numberOfTable2 == g->getTableNumber());
        BOOST_TEST (!g->isArchive());
        BOOST_TEST (!g->isRented());
        BOOST_CHECK_THROW(g->getCost(), RentObjectExceptions);
    }

    BOOST_AUTO_TEST_CASE(HallConstructor) {
        shared_ptr<Hall> h = make_shared<Hall>(basePrice3, objectID3, priceFactor1, name1);
        BOOST_TEST (basePrice3 == h->getBasePrice());
        BOOST_TEST (objectID3 == h->getObjectID());
        BOOST_TEST (priceFactor1 == h->getPriceFactor());
        BOOST_TEST (name1 == h->getName());
        BOOST_TEST (!h->isArchive());
        BOOST_TEST (!h->isRented());
        BOOST_TEST (0 == h->getHallSize());
    }

    BOOST_AUTO_TEST_CASE(HallSetters) {
        shared_ptr<Personal> p = make_shared<Personal>(basePrice1, objectID1, capacity1, numberOfTable1);
        shared_ptr<Group> g = make_shared<Group>(basePrice2, objectID2, capacity2, numberOfTable2, sale);
        shared_ptr<Hall> h = make_shared<Hall>(basePrice3, objectID3, priceFactor1, name1);
        RentObjectManager::changeHall(h, p);
        RentObjectManager::changeHall(h, g);
        BOOST_TEST (2 == h->getHallSize());
        BOOST_TEST (p->getCost() == basePrice1 * h->getPriceFactor() * capacity1);
        BOOST_TEST (g->getCost() == basePrice2 * h->getPriceFactor() * capacity2 * sale);
        BOOST_TEST (h->getCost() == (basePrice1 + basePrice2 + basePrice3) * priceFactor1 * 0.5);
        BOOST_TEST (h->getIDOfTablesOfHall() == to_string(objectID1) + ", " + to_string(objectID2) + ", ");
        h->setRentForTables(true);
        BOOST_TEST (p->isRented() == true);
        BOOST_TEST (g->isRented() == true);
        h->removeTable(p);
        BOOST_TEST (h->getHallSize() == 1);
    }

    BOOST_AUTO_TEST_CASE (HallChangesInTable) {
        shared_ptr<Personal> p = make_shared<Personal>(basePrice1, objectID1, capacity1, numberOfTable1);
        shared_ptr<Group> g = make_shared<Group>(basePrice2, objectID2, capacity2, numberOfTable2, sale);
        shared_ptr<Hall> h1 = make_shared<Hall>(basePrice3, objectID3, priceFactor1, name1);
        shared_ptr<Hall> h2 = make_shared<Hall>(basePrice4, objectID4, priceFactor2, name2);
        RentObjectManager::changeHall(h1, p);
        RentObjectManager::changeHall(h1, g);
        BOOST_TEST (p->getHallPtr() == h1);
        RentObjectManager::changeHall(h2, p);
        BOOST_TEST (h1->getHallSize() == 1);
        BOOST_TEST (h2->getHallSize() == 1);
        BOOST_TEST (p->getHallPtr() == h2);
        BOOST_TEST (p->getCost() == basePrice1 * h2->getPriceFactor() * capacity1);
        BOOST_CHECK_THROW(p->changeHall(nullptr, p), RentObjectExceptions);
        BOOST_CHECK_THROW(p->changeHall(h2, p), RentObjectExceptions);

    }

BOOST_AUTO_TEST_SUITE_END()
