#ifndef ACTOR_H
#define ACTOR_H
#include <iostream>
#include <string>
using namespace std;

class Actor
{
private:
	int year;
	string award;
	bool winner;
	string Name;
	string film;

public:
	void setYear(int _year) { year = _year; }
	int getYear() { return year; }
	void setAward(string _award) { award = _award; }
	string getAward() { return award; }
	void setWinner(bool didWin) { winner = didWin; }
	bool getWinner() { return winner; }
	void setName(string _name) { Name = _name; }
	string getName() { return Name; }
	void setFilm(string _film) { film = _film; }
	string getFilm() { return film; }
	friend ostream& operator <<(ostream& out, Actor _actor);
};
#endif // !ACTOR_H
#pragma once
