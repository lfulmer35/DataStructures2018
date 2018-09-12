//Lucas Fulmer

#include "functions.h"

using namespace std;
int main()
{
	BSTree<Actor, string> *actorTree = new BSTree<Actor, string>;
	BSTree<Picture, string> *pictureTree = new BSTree<Picture, string>;
	int choice;
	bool done = false;
	pictureTree->readInPicturefile();
	actorTree->readInActorfile();
	
	while (!done)
	{
		cout << "---------Welcome to the Academy Awards Database----------" << endl;
		cout << "Which database would you like to access?" << endl;
		cout << "1. Movie Database " << endl;
		cout << "2. Actors and Actress Database " << endl;
		cout << "3. Exit " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			pictureMenu(pictureTree);
			break;
		case 2: 
			actorMenu(actorTree);
			break;
		case 3: 
			cout << "Goodbye" << endl;
			done = true;
			break;
		default:
			cout << "Please enter a number from the menu." << endl;
			break;
		}
	}





	return 0;
}