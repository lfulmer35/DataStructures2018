//Lucas Fulmer
#include <list>
#include "DictEntry.h"
#include "dictionary.h"

using namespace std;

int main()
{
	Dictionary dictionary, searchDictionary;//declaring to objects of type dictionary
	dictionary.readInDictionary();//reading in .txt file
	dictionary.sortDictionary();//sorting the dictionary into alphabetical order
	dictionary.displayFromFront();//displays the dictionary in alphabetical order
	searchDictionary.readInFindWords();//reads in list of words to search for
	dictionary.searchFromFront(searchDictionary);
	dictionary.searchFromBack(searchDictionary);
	dictionary.writeDictionarytoFile();
	
return 0;
}
