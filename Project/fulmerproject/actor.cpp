//Lucas Fulmer
#include "actor.h"

using namespace std;
Actor::Actor()
{
	Name = "";
}
ostream& operator <<(ostream& out, Actor _actor)
{//for printing actor/actress objects
	out << "Year: " << _actor.year << endl << "Award: " << _actor.award << endl << "Name: " << _actor.Name << endl
		<< "Film: " << _actor.film << endl << endl;
	return out;
}