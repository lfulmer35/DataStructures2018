#include "animals.h"
using namespace std;

int main()
{
	Dog dog1;
	Fish fish1;
	Horse horse1;
	Lizard lizard1;
	Monkey monkey1;

	dog1.readInFiles();
	fish1.readInFiles();
	horse1.readInFiles();
	lizard1.readInFiles();
	monkey1.readInFiles();
	cout << "Here are the animals I have read-in." << endl;
	dog1.printAnimal();
	fish1.printAnimal();
	horse1.printAnimal();
	lizard1.printAnimal();
	monkey1.printAnimal();
	cout << endl << "Here is the dog after he exercised for a few weeks: " << endl;
	dog1.subtract10();
	dog1.printAnimal();
	cout << endl << "Here is the horse after living in low gravity for a few years: " << endl;
	horse1.add1();
	horse1.printAnimal();
	cout << endl << "Here is the monkey on Opposite Day: " << endl;
	monkey1.changeEndangered();
	monkey1.printAnimal();
	return 0;
}