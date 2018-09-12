//Lucas Fulmer
#ifndef PICTURE_H
#define PICTURE_H
#include <iostream>
#include <string>
using namespace std;

class Picture
{
private:
	string Name;
	string year;
	int nominations;
	double rating;
	int duration;
	string genre1;
	string genre2;
	string release;
	int metacritic;
	string synopsis;

public:
	Picture();
	void setName(string _name) { Name = _name; }
	string getName() { return Name; }
	void setYear(string _year) { year = _year; }
	string getYear() { return year; }
	void setNominations(int _nominations) { nominations = _nominations; }
	int getNominations() { return nominations; }
	void setRating(double _rating) { rating = _rating; }
	double getRating() { return rating; }
	void setDuration(int _duration) { duration = _duration; }
	int getDuration() { return duration; }
	void setGenre1(string _genre1) { genre1 = _genre1; }
	void setGenre2(string _genre2) { genre2 = _genre2; }
	string getGenre1() { return genre1; }
	string getGenre2() { return genre2; }
	void setRelease(string _release) { release = _release; }
	string getRelease() { return release; }
	void setMetacritic(int _meta) { metacritic = _meta; }
	int getMetacritic() { return metacritic; }
	void setSynopsis(string _synopsis) { synopsis = _synopsis; }
	string getSynopsis() { return synopsis; }
	friend ostream& operator <<(ostream& out, Picture _picture);

};
#endif // !PICTURE_H