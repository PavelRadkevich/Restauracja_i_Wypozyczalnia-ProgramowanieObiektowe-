//
// Created by student on 03.06.2022.
//

#ifndef RESTAURANT_PERSONAL_H
#define RESTAURANT_PERSONAL_H

#include "Table.h"

class Personal : public Table{
private:

public:
    Personal (const int& basePrice, const int& objectID_, const int& capacity_, const Hall& hall_);
    ~Personal();
    const string getObjectInfo() const;
};


#endif //RESTAURANT_PERSONAL_H
