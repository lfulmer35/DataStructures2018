//Lucas Fulmer

#ifndef GUESS_H
#define GUESS_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

class Guess
{
private:
	vector<int> randNums; //this stores the random generated numbers in our object
	vector<int> guessNums; //stores the user's guessed numbers in our object
	int rangeNums; //the range of numbers the user will guess from

public:
	Guess();//constructor
	
	//member functions
	void setRange(int _range) { rangeNums = _range; }
	int getRange() { return rangeNums; }

	void setRandNums(int _range, int nums);
	vector <int> getRandNums() { return randNums; }

	void setGuessNums(int nums);
	vector <int> getGuessNums() { return guessNums; }
	
	int compareGuess(Guess _game, int nums);
	
};

#endif
