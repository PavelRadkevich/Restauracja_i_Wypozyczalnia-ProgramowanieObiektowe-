//
// Created by student on 03.06.2022.
//

#ifndef RESTAURANT_TABLE_H
#define RESTAURANT_TABLE_H

#include "RentObject.h"
#include "typedefs.h"

class Table : public RentObject, public enable_shared_from_this<Table>{
protected:
    int capacity;
    HallPtr hall;
    int numberOfTable;
    shared_ptr<Table> I;

    void init();



public:
    //Konstruktor
    Table (const int& basePrice, const int& objectID_, const int& capacity_, const int &numberOfTable_);
    //Table(const int &basePrice, const int &objectID_, const int &capacity_, const int &numberOfTable_);
    static shared_ptr<Table> create (const int& basePrice, const int& objectID_, const int& capacity_, const int &numberOfTable_);

    //Destruktor
    ~Table();

    //Gettery
    virtual const string getObjectInfo ()const;
    const shared_ptr<Hall> getTableHallPtr () const override;
    shared_ptr<const Table> getTablePtr ();
    const shared_ptr<Hall> getHallPtr ()const;
    const int getCapacity () const;
    const int getTableNumber () const;

    //Settery
    void changeHall (HallPtr newHall, shared_ptr<Table> table1);
    virtual void updatePrice ();
    void setHall (shared_ptr<Hall> newHall);

};


#endif //RESTAURANT_TABLE_H
