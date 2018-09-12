//Lucas Fulmer

#include <iostream>
#include "guess.h"
using namespace std;


Guess::Guess()
{
	vector<int> randNums;
	vector<int> guessNums;
	int rangeNums = 0;
}

void Guess::setRandNums(int _range, int nums)
{
//this function creates our random numbers and stores them in a vector

	vector <int> tempvector;
	srand(time(NULL));

	for (int i = 0; i < nums; i++)
	{
		int b = (rand() % _range) + 1;
		tempvector.push_back(b);
	}
	randNums = tempvector;
	for (int i = 0; i < nums; i++)
		cout << endl << randNums[i] << endl; //this print statement is simply for ease of grading
}

int Guess::compareGuess(Guess _game, int nums)

//this function uses multiple loops to compare the random numbers to the guesses

{
	int count = 0;
	for (int x = 0; x < nums; x++)
		for (int g = 0; g < nums; g++)
			if (_game.getGuessNums()[x] == _game.getRandNums()[g])
				{
					count += 1;
					g = nums;
				}
	cout << "You got " << count << " out of " << nums << " numbers correct." << endl;
	if (count == nums)
	{
		cout << "You win!!" << endl;
		return 3;// this will end the while loop in main
	}
}

void Guess::setGuessNums(int nums)//this function records the user's guesses
{
	vector <int> tempvector;

	for (int i = 0; i < nums; i++)
	{
		int guesses;
		cout << "Please enter guess " << i + 1 << ": ";
		cin >> guesses;
		tempvector.push_back(guesses);
		cout << tempvector[i] << endl;
		
	}
	guessNums = tempvector;//assigning the temp vector to our object
}
