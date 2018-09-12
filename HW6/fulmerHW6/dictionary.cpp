//Lucas Fulmer

#include "dictionary.h"

void Dictionary::readInDictionary()
{//Reads-in list of dictEntry into dictionary
	ifstream inFile;
	DictEntry tempDict;
	string tempWord, tempDef;

	inFile.open("dictionary.txt");

	if (!inFile.good())
		cout << "Error opening the file." << endl;
	else
	{
		while (inFile.good())
		{
			inFile >> tempWord;
			tempDict.setWord(tempWord);
			dictList.push_back(tempDict);
		}//while
		inFile.close();
		cout << endl << "dictionary.txt successfully read-in." << endl;
	}//else
}
void Dictionary::readInFindWords()
{//reads in the list of words that we will search for
	ifstream inFile;
	DictEntry tempDict;
	string tempWord, tempDef;

	inFile.open("findwords.txt");

	if (!inFile.good())
		cout << "Error opening the file." << endl;
	else
	{
		while (inFile.good())
		{
			inFile >> tempWord;
			tempDict.setWord(tempWord);
			dictList.push_back(tempDict);
		}//while
		inFile.close();
		cout << endl << "findwords.txt successfully read-in." << endl;
	}//else
}
void Dictionary::writeDictionarytoFile()
{//writes the Dictionary(list) to a .txt file in reverse order
	ofstream outfile;
	outfile.open("revsorted.txt");
	if (!outfile.good())
		cout << "Error writing to file.";
	else
	{//using a reversePtr to move through the list in descending order
		for (reversePtr = dictList.rbegin(); reversePtr != dictList.rend(); reversePtr++)
			outfile << *reversePtr << " ";
		outfile.close();
		cout << "List successfully written to file." << endl;
	}
}
void Dictionary::displayFromFront()
{//displays the dictEntry objects in our dictionary list in ascending order
	cout << "Displaying dictionary in ascending order. " << endl;
	for (dllPtr = dictList.begin(); dllPtr != dictList.end(); dllPtr++)
		cout << *dllPtr << endl;
}
void Dictionary::displayFromBack()
{//displays the dictEntry objects in our dictionary list in descending order
	cout << "Displaying dictionary in reverse order. " << endl;
	for (reversePtr = dictList.rbegin(); reversePtr != dictList.rend(); reversePtr++)
		cout << *reversePtr << endl;
}
void Dictionary::searchFromFront(Dictionary& _searchList)
{//searches the dictionary from front to back
	int total = 0;//variable to calculate the total number of searches to find all words
	cout << "Searching from the front. " << endl;
	for (_searchList.dllPtr = _searchList.dictList.begin(); _searchList.dllPtr != _searchList.dictList.end(); _searchList.dllPtr++)
	{
		int count = 1;//variable to save the number of searches conducted
		for (dllPtr = dictList.begin(); dllPtr != dictList.end(); dllPtr++)
		{

			if (*_searchList.dllPtr == *dllPtr)//if searched word is same as dictionary word, then print
			{
				cout << *dllPtr << " was found in " << count << " searches." << endl;
				total += count;
			}
			else
				count++;
		}
		count = 1;
	}
	cout << "Total number of searches: " << total << endl << endl;
}
void Dictionary::searchFromBack(Dictionary& _searchList)
{//searches dictionary from back to front
	int total = 0;//variable to calculate the total number of searches to find all words
	cout << "Searching from the back. " << endl;
	for (_searchList.dllPtr = _searchList.dictList.begin(); _searchList.dllPtr != _searchList.dictList.end(); _searchList.dllPtr++)
	{
		int count = 1;//variable to save the number of searches conducted
		for (reversePtr = dictList.rbegin(); reversePtr != dictList.rend(); reversePtr++)
		{

			if (*_searchList.dllPtr == *reversePtr)
			{
				cout << *reversePtr << " was found in " << count << " searches." << endl;
				total += count;
			}
			else
				count++;
		}
		count = 1;
	}
	cout << "Total number of searches: " << total << endl << endl;
}
