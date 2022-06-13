//
// Created by pvlrd on 13.06.2022.
//

#ifndef RESTAURANT_MANAGERSEXCEPTIONS_H
#define RESTAURANT_MANAGERSEXCEPTIONS_H

#include "stdexcept"

using namespace std;

class ManagersExceptions: public logic_error{
    public:
        explicit ManagersExceptions (const string &arg);
};


#endif //RESTAURANT_MANAGERSEXCEPTIONS_H
