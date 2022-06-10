//
// Created by pvlrd on 10.06.2022.
//

#include "exceptions/RentObjectExceptions.h"
//Konstruktor
RentObjectExceptions::RentObjectExceptions(const string & arg): logic_error(arg) {}
