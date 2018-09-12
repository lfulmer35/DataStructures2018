//Lucas Fulmer

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "DictEntry.h"
#include <list>
#include <fstream>
#include <iostream>
using namespace std;

class Dictionary
{
private:
	list<DictEntry> dictList;
	list<DictEntry>::iterator dllPtr;
	list<DictEntry>::reverse_iterator reversePtr;
public:
	void readInDictionary();
	void readInFindWords();
	void sortDictionary() { dictList.sort(); cout << "Dictionary Sorted" << endl; }
	void writeDictionarytoFile();
	void displayFromFront();
	void displayFromBack();
	void searchFromFront(Dictionary& _searchList);
	void searchFromBack(Dictionary& _searchList);
};

#endif // !DICTIONARY_H
