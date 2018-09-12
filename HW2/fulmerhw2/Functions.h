#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "ArrayBag.h"
#include <vector>

ArrayBag operator +(const ArrayBag& _bag1, const ArrayBag& _bag2);
//overloading the + to form Union bag
ArrayBag operator -(const ArrayBag& _bag1, const ArrayBag& _bag2);
//overloading the - to form difference bag

#endif // !FUNCTIONS_H

