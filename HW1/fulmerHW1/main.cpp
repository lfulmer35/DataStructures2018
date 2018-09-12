//Lucas Fulmer

#include <iostream>
#include "guess.h"
using namespace std;

int main()
{
	Guess game;
	int _range, done = 0, numofnums;
	cout << "How many guesses would you like? " << endl;
	cin >> numofnums;
	cout << "What range of numbers would you like to use? 1 to:" << endl;
	cin >> _range;
	game.setRange(_range);
	game.setRandNums(_range, numofnums);

	while (done < 3)
	{
		game.setGuessNums(numofnums);
		done = game.compareGuess(game, numofnums);
		done++;
	}
	return 0;
}
