//
// Created by pvlrd on 10.06.2022.
//

#include "exceptions/RentExceptions.h"
//Konstruktor
RentExceptions::RentExceptions(const string &arg): logic_error(arg) {}
