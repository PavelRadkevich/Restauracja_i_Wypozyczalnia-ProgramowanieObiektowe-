//
// Created by student on 03.06.2022.
//

#ifndef RESTAURANT_TABLE_H
#define RESTAURANT_TABLE_H

#include "RentObject.h"
#include "typedefs.h"

class Table : public RentObject, enable_shared_from_this<Table> {
protected:
    int capacity;
    HallPtr hall;
    int numberOfTable;


public:
    //Konstruktor
    Table (const int& basePrice, const int& objectID_, const int& capacity_, const Hall& hall_, const int &numberOfTable_);
    Table(const int &basePrice, const int &objectID_, const int &capacity_, const int &numberOfTable_);

    //Destruktor
    ~Table();

    //Gettery
    virtual const string getObjectInfo ()const;
    virtual const double getActualPriceForHour () const;
    const shared_ptr<Hall> getTableHallPtr () const override;
    const shared_ptr<const Table> getTablePtr () const override;
    //const double getCost () const;

    //Settery
    void changeHall (HallPtr newHall);
    virtual void updatePrice ();
    void addToHall () override ;

};


#endif //RESTAURANT_TABLE_H
