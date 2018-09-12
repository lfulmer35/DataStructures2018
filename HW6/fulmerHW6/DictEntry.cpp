//Lucas Fulmer

#include "DictEntry.h"

std::ostream& operator <<(std::ostream& out, DictEntry& _dictEntry)
{//overloading the operator in order to print objects
	out << _dictEntry.getWord();
	return out;
}
