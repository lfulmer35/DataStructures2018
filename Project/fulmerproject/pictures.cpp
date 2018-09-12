#include "picture.h"
using namespace std;

Picture::Picture()
{
	Name = "";
}
ostream& operator <<(ostream& out, Picture _picture)
{//for printing picture objects
	out << "Title: " << _picture.Name << endl << "Year: " << _picture.year << endl << "Nominations: " <<  _picture.nominations << endl << "Rating: " << _picture.rating << endl << "Duration: " << _picture.duration << endl 
		<< "Genre1: " << _picture.genre1 << endl << "Genre2: "<< _picture.genre2 << endl << "Released: " << _picture.release 
		<< endl << "Metacritic: " << _picture.metacritic << endl << "Synopsis: " << _picture.synopsis << endl << endl;
	return out;
}