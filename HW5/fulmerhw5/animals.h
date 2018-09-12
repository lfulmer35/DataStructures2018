#ifndef ANIMALS_H
#define ANIMALS_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Animal
{
private:
	string Name;
	string Color;
public:
	Animal();
	void setName(string _name) { Name = _name; }
	string getName() { return Name; }
	void setColor(string _color) { Color = _color; }
	string getColor() { return Color; }
	virtual void readInFiles() = 0;
	virtual void printAnimal();
};
class Dog : public Animal
{
private:
	string Breed;
	int age;
	double weight;
public:
	Dog();
	void setBreed(string _breed) { Breed = _breed; }
	string getBreed() { return Breed; }
	void setAge(int _age) { age = _age; }
	int getAge() { return age; }
	void setWeight(double _weight) { weight = _weight; }
	void subtract10() { weight -= 10; }
	void readInFiles();
	void printAnimal();
};
class Fish : public Animal
{
private:
	bool isFreshwater;
	string habitat;
	bool isPredator;
public:
	Fish();
	void setFreshwater(bool _isFresh) { isFreshwater = _isFresh; }
	bool getFreshwater() { return isFreshwater; }
	void setHabitat(string _habitat) { habitat = _habitat; }
	string getHabitat() { return habitat; }
	void setPredator(bool _predator) { isPredator = _predator; }
	bool getPredator() { return isPredator; }
	void readInFiles();
	void printAnimal();
};
class Horse : public Animal
{
private:
	string maneColor;
	int age;
	double height;
public:
	Horse();
	void setManeColor(string _maneColor) { maneColor = _maneColor; }
	string getManeColor() { return maneColor; }
	void setAge(int _age) { age = _age; }
	int getAge() { return age; }
	void setHeight(double _height) { height = _height; }
	double getHeight() { return height; }
	void add1() { height += 1; }
	void readInFiles();
	void printAnimal();
};
class Lizard : public Animal
{
private:
	string habitat;
	bool isProtected;
	double weight;
public:
	Lizard();
	void setHabitat(string _habitat) { habitat = _habitat; }
	string getHabitat() { return habitat; }
	void setProtected(bool _isProtected) { isProtected = _isProtected; }
	bool getProtected() { return isProtected; }
	void setWeight(double _weight) { weight = _weight; }
	double getWeight() { return weight; }
	void readInFiles();
	void printAnimal();
};
class Monkey : public Animal
{
private:
	int age;
	bool isWild;
	string home;
	bool isEndangered;
public:
	Monkey();
	void setAge(int _age) { age = _age; }
	int getAge() { return age; }
	void setWild(bool _isWild) { isWild = _isWild; }
	bool getWild() { return isWild; }
	void setHome(string _home) { home = _home; }
	string getHome() { return home; }
	void setEndangered(bool _isEndangered) { isEndangered = _isEndangered; }
	bool getEndangered() { return isEndangered; }
	void changeEndangered();
	void readInFiles();
	void printAnimal();
};
#endif // ANIMALS_H
