//
// Created by pvlrd on 10.06.2022.
//

#ifndef RESTAURANT_RENTEXCEPTIONS_H
#define RESTAURANT_RENTEXCEPTIONS_H

#include "stdexcept"

using namespace std;

class RentExceptions: public logic_error {
public:
    explicit RentExceptions (const string&);
};


#endif //RESTAURANT_RENTEXCEPTIONS_H
