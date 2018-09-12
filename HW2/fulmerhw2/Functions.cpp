#include "Functions.h"


using namespace std;

ArrayBag operator +(const ArrayBag& _bag1, const ArrayBag& _bag2)
//Overloading the + operator to create a Union
{
	ArrayBag tempBag;
	for (int i = 0; i < _bag1.getCurrentSize(); i++)
		tempBag.add(_bag1.items[i]);
	for (int i = 0; i < _bag2.getCurrentSize(); i++)
		tempBag.add(_bag2.items[i]);
	return tempBag;
}
ArrayBag operator -(const ArrayBag& _bag1, const ArrayBag& _bag2)
//Overloading the - operator to create difference bag
//Note - if there are a greater number of a particular item in bag1 than bag2, the difference will be moved to the difference bag
{
	ArrayBag tempBag;

	for (int i = 0; i < _bag1.getCurrentSize(); i++)
	{
		tempBag.add(_bag1.items[i]);
		for (int j = 0; j < _bag2.getCurrentSize(); j++)
			if ((_bag2.items[j] == _bag1.items[i]) && _bag1.getFrequencyOf(_bag1.items[i]) <= _bag2.getFrequencyOf(_bag2.items[j]))
				tempBag.remove(_bag1.items[i]);
	}
	return tempBag;

}
