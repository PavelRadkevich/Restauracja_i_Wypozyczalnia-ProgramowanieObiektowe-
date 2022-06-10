//
// Created by pvlrd on 10.06.2022.
//

#ifndef RESTAURANT_RENTOBJECTEXCEPTIONS_H
#define RESTAURANT_RENTOBJECTEXCEPTIONS_H

#include "stdexcept"

using namespace std;

class RentObjectExceptions: public logic_error {
public:
    explicit RentObjectExceptions (const string&);
};

#endif //RESTAURANT_RENTOBJECTEXCEPTIONS_H
