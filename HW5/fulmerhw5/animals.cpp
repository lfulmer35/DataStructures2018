#include "animals.h"
#include <string>
#include <cstring>
#include <sstream>
using namespace std;
//************************Animal Implementation*****************************
Animal::Animal()
{
	Name = " ";
	Color = " ";
}
void Animal::readInFiles()
{
	cout << "Cannot read-in information for this class." << endl;
}
void Animal::printAnimal()
{
	cout << "Animal: " << endl << "Name: " << Name << endl << "Color: " << Color << endl;
}
//*********************Dog Implementation************************
Dog::Dog()
{
	setName(" ");
	setColor(" ");
	Breed = " ";
	age = 0;
	weight = 0.0;
}
void Dog::readInFiles()
{
	ifstream infile;
	string tempDog;

	infile.open("Dog.csv");
	if (!infile.good())
		cout << "Error opening Dog.csv." << endl;
	else
		while (infile.good())
			getline(infile, tempDog);
	infile.close();
	istringstream ss(tempDog);
	string substring;
	getline(ss, substring, ',');
	setName(substring);
	getline(ss, substring, ',');
	Breed = substring;
	try
	{
		getline(ss, substring, ',');
		age = stoi(substring);
		if (age <= 0)
			throw age;
	}
	catch (int e)
	{
		cout << "The dog's age is invalid. What is its age? " << endl;
		cin >> e;
		age = e;
	}
	getline(ss, substring, ',');
	setColor(substring);
	try
	{
		getline(ss, substring, ',');
		weight = stoi(substring);
		if (weight <= 0)
			throw weight;
	}
	catch (int e)
	{
		cout << "The dog's weight is invalid. What should it be? " << endl;
		cin >> e;
		weight = e;
	}
}
void Dog::printAnimal()
{
	cout << "Dog: " << endl << "Name: " << getName() << endl << "Color: " << getColor() << endl <<
		"Breed: " << Breed << endl << "Age: " << age << endl << "Weight: " <<
		weight << endl << endl;
}
//**********************Fish Implementation************************
Fish::Fish()
{
	setName(" ");
	setColor(" ");
	isFreshwater = false;
	habitat = "Lakes and Rivers";
	isPredator = true;
}
void Fish::readInFiles()
{
	ifstream infile;
	string tempFish, tempBool;

	infile.open("Fish.csv");
	if (!infile.good())
		cout << "Error opening Fish.csv." << endl;
	else
		while (infile.good())
			getline(infile, tempFish);
	infile.close();
	istringstream ss(tempFish);
	string substring;
	getline(ss, substring, ',');
	setName(substring);
	getline(ss, substring, ',');
	setColor(substring);
	try
	{
		getline(ss, substring, ',');
		for (int i = 0; i < substring.length(); i++)
			substring[i] = toupper(substring[i]);
		if (substring == "TRUE")
			isFreshwater = true;
		else if (substring == "FALSE")
			isFreshwater = false;
		else
			throw substring;
	}
	catch (string e)
	{
		char answer;
		cout << "The fish's freshwater field was invalid. " << endl << "Is it a freshwater fish (Y or N): " << endl;
		cin >> answer;
		answer = toupper(answer);
		if (answer == 'Y')
			isFreshwater = true;
		else
			isFreshwater = false;
	}
	getline(ss, substring, ',');
	habitat = substring;
	try 
	{
		getline(ss, substring, ',');
		for (int i = 0; i < substring.length(); i++)
			substring[i] = toupper(substring[i]);
		if (substring == "TRUE")
			isPredator = true;
		else if (substring == "FALSE")
			isPredator = false;
		else
			throw substring;
	}
	catch (string e)
	{
		char answer;
		cout << "The fish's predator field was invalid. " << endl << "Is it a predator (Y or N): " << endl;
		cin >> answer;
		answer = toupper(answer);
		if (answer == 'Y')
			isPredator = true;
		else
			isPredator = false;
	}
}
void Fish::printAnimal()
{
	cout << "Fish: " << endl << "Name: " << getName() << endl << "Color: " << getColor() << endl;
	if (isFreshwater == true)
		cout << "Freshwater: Yes" << endl;
	else
		cout << "Freshwater: No" << endl;
	cout << "Habitat: " << habitat << endl;
	if (isPredator == true)
		cout << "Predator: Yes" << endl << endl;
	else
		cout << "Predator: No" << endl << endl;
}
//**********************Horse Implementation***********************
Horse::Horse()
{
	setName(" ");
	setColor(" ");
	maneColor = " ";
	age = 0;
	height = 0;
}
void Horse::readInFiles()
{
	ifstream infile;
	string tempHorse;

	infile.open("Horse.csv");
	if (!infile.good())
		cout << "Error opening Horse.csv." << endl;
	else
		while (infile.good())
			getline(infile, tempHorse);
	infile.close();
	istringstream ss(tempHorse);
	string substring;					
	getline(ss, substring, ',');
	setName(substring);
	getline(ss, substring, ',');
	setColor(substring);
	getline(ss, substring, ',');
	maneColor = substring;
	try
	{
		getline(ss, substring, ',');
		age = stoi(substring);
		if (age <= 0)
			throw age;
	}
	catch (int e)
	{
		cout << "Enter a different age for the horse. The one in the file was dumb." << endl;
		cout << "What's the correct age: " << endl;
		cin >> e;
		age = e;
	}
	try
	{
		getline(ss, substring, ',');
		height = stoi(substring);
		if (height <= 0)
			throw height;
	}
	catch (int e)
	{
		cout << "The horse's height is " << e << endl;
		cout << "What should it be? " << endl;
		cin >> e;
		height = e;
	}
}
void Horse::printAnimal()
{
	cout << "Horse: " << endl << "Name: " << getName() << endl << "Color: " << getColor() << endl
		<< "Mane Color: " << maneColor << endl << "Age: " << age << endl << "Height: " << height << endl << endl;
}
//**********************Lizard Implementation***********************
Lizard::Lizard()
{
	setName(" ");
	setColor(" ");
	habitat = "Equatorial Jungle";
	isProtected = false;
	weight = 0;
}
void Lizard::readInFiles()
{
	ifstream infile;
	string tempLizard;

	infile.open("Lizard.csv");
	if (!infile.good())
		cout << "Error opening Lizard.csv." << endl;
	else
		while (infile.good())
			getline(infile, tempLizard);
	infile.close();
	istringstream ss(tempLizard);
	string substring;
	try
	{
		getline(ss, substring, ',');
		setName(substring);
		getline(ss, substring, ',');
		setColor(substring);
		getline(ss, substring, ',');
		habitat = substring;
		getline(ss, substring, ',');
		for (int i = 0; i < substring.length(); i++)
			substring[i] = toupper(substring[i]);
		if (substring == "TRUE")
			isProtected = true;
		else if (substring == "FALSE")
			isProtected = false;
		else
			throw substring;
		getline(ss, substring, ',');
		weight = stoi(substring);
		if (weight <= 0)
			throw weight;
	}
	catch (string e)
	{
		char answer;
		cout << "There was an invalid entry for isProtected in the file." << endl;
		cout << "Is the lizard protected (Y or N): ";
		cin >> answer;
		answer = toupper(answer);
		if (answer == 'Y')
			isProtected = true;
		else
			isProtected = false;
	}
	catch (int e)
	{
		cout << "The weight entered was " << e << ". That doesn't make sense." << endl;
		cout << "What would you like the weight to be ----> ";
		cin >> e;
		weight = e;
	}
}
void Lizard::printAnimal()
{
	cout << "Lizard: " << endl << "Name: " << getName() << endl << "Color: " << getColor() << endl <<
		"Habitat: " << habitat << endl;
	if (isProtected == true)
		cout << "Protected: Yes" << endl;
	else
		cout << "Protected: No" << endl;
	cout << "Weight: " << weight << endl << endl;
}
//**********************Monkey Implementation************************
Monkey::Monkey()
{
	setName(" ");
	setColor(" ");
	age = 0;
	isWild = true;
	home = "Southeast Asia";
	isEndangered = true;
}
void Monkey::changeEndangered()
{
	if (isEndangered == true)
		isEndangered = false;
	else
		isEndangered = true;
}
void Monkey::readInFiles()
{
	ifstream infile;
	string tempHorse;

	infile.open("Monkey.csv");
	if (!infile.good())
		cout << "Error opening Monkey.csv." << endl;
	else
		while (infile.good())
			getline(infile, tempHorse);
	infile.close();
	istringstream ss(tempHorse);
	string substring;
	try
	{
		getline(ss, substring, ',');
		setName(substring);
		getline(ss, substring, ',');
		setColor(substring);
		getline(ss, substring, ',');
		age = stoi(substring);
		if (age <= 0)
			throw age;
		getline(ss, substring, ',');
		for (int i = 0; i < substring.length(); i++)
			substring[i] = toupper(substring[i]);
		if (substring == "TRUE")
			isWild = true;
		else if (substring == "FALSE")
			isWild = false;
		else
			throw substring;
	}
	catch (string e)
	{
		char answer;
		cout << "There was an invalid entry for isWild in the file." << endl;
		cout << "Is the monkey wild (Y or N): ";
		cin >> answer;
		answer = toupper(answer);
		if (answer == 'Y')
			isWild = true;
		else
			isWild = false;
	}
	try
	{
		getline(ss, substring, ',');
		home = substring;
		getline(ss, substring, ',');
		for (int i = 0; i < substring.length(); i++)
			substring[i] = toupper(substring[i]);
		if (substring == "TRUE")
			isEndangered = true;
		else if (substring == "FALSE")
			isEndangered = false;
		else
			throw substring;
	}
	catch (int e)
	{
		cout << "The monkey's age is " << e << ". That does make sense." << endl;
		cout << "Enter a new age ----> ";
		cin >> e;
		age = e;
	}
	catch (string e)
	{
		char answer;
		cout << "There was an invalid entry for isEndangered in the file." << endl;
		cout << "Is the monkey endangered (Y or N): ";
		cin >> answer;
		answer = toupper(answer);
		if (answer == 'Y')
			isEndangered = true;
		else
			isEndangered = false;
	}
}
void Monkey::printAnimal()
{
	cout << "Monkey: " << endl << "Name: " << getName() << endl << "Color: " << getColor() << endl <<
		"Age: " << age << endl;
	if (isWild == true)
		cout << "Wild: Yes" << endl;
	else
		cout << "Wild: No" << endl;
	cout << "Home: " << home << endl;
	if (isEndangered == true)
		cout << "Endangered: Yes" << endl << endl;
	else
		cout << "Endangered: No" << endl << endl;
}