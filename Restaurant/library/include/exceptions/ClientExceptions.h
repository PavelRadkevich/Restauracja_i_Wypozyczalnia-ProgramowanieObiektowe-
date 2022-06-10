//
// Created by pvlrd on 10.06.2022.
//

#ifndef RESTAURANT_CLIENTEXCEPTIONS_H
#define RESTAURANT_CLIENTEXCEPTIONS_H
#include "stdexcept"

using namespace std;

class ClientExceptions : public logic_error{
public:
    explicit ClientExceptions (const string&);

};


#endif //RESTAURANT_CLIENTEXCEPTIONS_H
