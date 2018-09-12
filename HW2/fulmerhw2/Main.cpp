//Lucas Fulmer

#include "ArrayBag.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	ifstream setInput;
	string string1, string2;
	ArrayBag bag1, bag2, unionBag, differenceBag;
	//READING IN FILE
	setInput.open("setInput.txt");//opening our input file
	
	if (!setInput.good())
		cout << "Error opening the file." << endl;
	else
		while (setInput.good())
		{
			getline(setInput, string1);
			getline(setInput, string2);
		}
	setInput.close(); //closing the file

	//calling the function to fill our bags with intergers
	bag1.streamFillBag(bag1, string1);
	bag2.streamFillBag(bag2, string2);

	cout << endl << "Bag 1 contains the following numbers: " << endl;
	bag1.displayItems(bag1);
	
	cout << endl << endl << "Bag 2 contains the following numbers: " << endl;
	bag2.displayItems(bag2);

	//creating a union by adding the two bags together
	unionBag = bag1 + bag2;

	//printing contents and sizes
	cout << endl << endl << "The union bag contains the following numbers before removing duplicates: " << endl;
	unionBag.displayItems(unionBag);
	//removing duplicates from union

	unionBag.removeDuplicate(unionBag);
	cout << endl <<  "After removing duplicates, it contains: " << endl;
	unionBag.displayItems(unionBag);

	//creating difference bag by subtracting two bags
	differenceBag = bag1 - bag2;
	//removing duplicates
	differenceBag.removeDuplicate(differenceBag);
	cout << endl << endl << "The difference bag (Bag 1 - Bag 2) contains: " << endl;
	differenceBag.displayItems(differenceBag);
	cout << endl << endl;
	
	cout << "Note: Difference bag accounts for the quanitity of items in each bag." << endl;
	cout << "If there is a greater quantity of a particular item in bag1 than bag2, the difference" << endl;
	cout << "will be stored in difference bag." << endl;

	return 0;

}
