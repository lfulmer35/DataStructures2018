//Lucas Fulmer


#include "functions.h"
using namespace std;

void actorMenu(BSTree<Actor, string>* _actorTree)
{//Main driver function for the Actor-Actress database
	bool done = false, tempWinner;
	int choice, subchoice;
	char tempchoice;
	string tempstring;
	Actor tempActor;

	while (!done)
	{
		cout << "You are in the Actor/Actress database. " << endl;
		cout << "What would you like to do? " << endl;
		cout << "1. Add a record " << endl;
		cout << "2. Search for an actor/actress " << endl;
		cout << "3. Sort the database " << endl;
		cout << "4. Modify or delete a record " << endl;
		cout << "5. Print database to a file " << endl;
		cout << "6. Go back to main menu " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "What is the actor/actress name? " << endl;
			cin.ignore();
			getline(cin, tempstring);
			tempActor.setName(tempstring);
			
			cout << "What award was he/she nominated for?" << endl;
			//cin.ignore();
			getline(cin, tempstring);
			tempActor.setAward(tempstring);

			cout << "Did they win('Y' or 'N')?" << endl;
			cin >> tempchoice;
			if (toupper(tempchoice) == 'Y')
				tempActor.setWinner(1);
			else
				tempActor.setWinner(0);

			cout << "What the title of the film?" << endl;
			cin.ignore();
			getline(cin, tempstring);
			tempActor.setFilm(tempstring);

			cout << "What year was the nomination?" << endl;
			//cin.ignore();
			getline(cin, tempstring);
			tempActor.setYear(tempstring);

			_actorTree->addNode(tempActor.getYear(), tempActor);
			break;
		case 2:
			searchActor(_actorTree);
			break;

		case 3:
			sortActor(_actorTree);
			break;
		case 4:
			modifyOrRemoveActor(_actorTree);
			break;
		case 5:
			_actorTree->writeActorsToFile();
			break;
		case 6:
			done = true;
			break;
		default:
			cout << "Please enter a number from the menu." << endl;
			break;
		}
	}//while
}

void searchActor(BSTree<Actor, string>* _actorTree)
{//search function in actor database
	vector<Actor> searchVec;
	vector<Actor> foundVec;
	Actor tempActor;
	bool done = false;
	string tempname, tempyear, searchname, searchyear;
	char choice;
	int tempwinner, count =0, input, refineChoice;

	_actorTree->fillActorVector(searchVec);//putting into vector for the sake of search and sort. O(n) for vector. O(n^2) to resort BST
	while (!done)
	{
		cout << "a. Partial Search " << endl;
		cout << "b. Exact Search " << endl;
		cin >> choice;

		switch (toupper(choice))
		{
		case 'A':
			while (!done)
			{
				cout << "Choose a field to search by(note: fields are case sensitive). " << endl;
				cout << "1. Year " << endl << "2. Name " << endl << "3. Award Winners " << endl << "4. Refine a previous search" << endl << "5. Go back " << endl;
				cin >> input;
				switch (input)
				{
				case 1:
					cout << endl << "Enter the year you would like to search: " << endl;
					cin.ignore();
					getline(cin, tempyear);
					for (int i = 0; i < searchVec.size(); i++)
					{
						searchyear = searchVec[i].getYear();
						if (searchyear.find(tempyear) != string::npos)
							foundVec.push_back(searchVec[i]);
					}
					cout << "Here are the " << foundVec.size() << " thespians that matched your search" << endl;
					for (int i = 0; i < foundVec.size(); i++)
						cout << foundVec[i];
					break;
				case 2:
					cout << "Enter the name of the actor/actress you would like to search: " << endl;
					cin.ignore();
					getline(cin, tempname);
					for (int i = 0; i < searchVec.size(); i++)
					{
						searchname = searchVec[i].getName();
						if (searchname.find(tempname) != string::npos)
							foundVec.push_back(searchVec[i]);
					}
					cout << "Here are the " << foundVec.size() << " thespians that matched your search" << endl;
					for (int i = 0; i < foundVec.size(); i++)
						cout << foundVec[i];
					break;
				case 3:
					cout << "Here is the list of award winners: " << endl;
					for (int i = 0; i < searchVec.size(); i++)
						if (searchVec[i].getWinner() == true)
							foundVec.push_back(searchVec[i]);
					cout << "Here are the " << foundVec.size() << " award winners." << endl;
					for (int i = 0; i < foundVec.size(); i++)
						cout << foundVec[i];
					break;
				case 4:
					cout << endl << "Refine by:" << endl << "a. Year" << endl << "b. Name" << endl << "c. Winners" << endl << "d. Go back " << endl;
					cin >> refineChoice;
					switch (toupper(refineChoice))
					{
					case 'A':
						cout << endl << "What year would you like to search for? " << endl;
						cin >> tempyear;
						count = 0;
						for (int i = 0; i < foundVec.size(); i++)
						{
							searchyear = foundVec[i].getYear();
							if (searchyear == tempyear)
							{
								count++;
								cout << foundVec[i];
							}
						}
						if (count == 0)
							cout << "No records found." << endl;
						break;
					case 'B':
						cout << "What name would you like to search?" << endl;
						cin.ignore();
						getline(cin, tempname);
						count = 0;
						for (int i = 0; i < foundVec.size(); i++)
						{
							searchname = foundVec[i].getName();
							if (searchname == tempname)
							{
								count++;
								cout << foundVec[i];
							}
						}
						if (count == 0)
							cout << "No records found." << endl;
						break;

					case 'C':
						cout << endl << "Here are the winners: " << endl;
						count = 0;
						for (int i = 0; i < foundVec.size(); i++)
						{
							if (foundVec[i].getWinner() == true)
							{
								count++;
								cout << foundVec[i];
							}
						}//for
						if (count == 0)
							cout << "No records found." << endl;
						break;
					case 'D':
						done = true;
						break;
					}
					break;
				case 5:
					done = true;
					break;
				default:
					cout << "Please enter a valid choice." << endl;
					break;
				}//switch
			}//while
			break;
		case 'B':
			foundVec.clear();
			cout << endl << "Enter the year: " << endl;
			cin >> tempyear;
			cout << "Enter the name of the actor/actress: " << endl;
			cin.ignore();
			getline(cin, tempname);
			tempActor.setYear(tempyear);
			tempActor.setName(tempname);
			count = 0;
			for (int i = 0; i < searchVec.size(); i++)
			{
				if (tempActor.getName() == searchVec[i].getName() && tempActor.getYear() == searchVec[i].getYear())
				{
					count++;
					cout << searchVec[i];
				}
			}
			if (count == 0)
				cout << "No records match your search." << endl;
			break;
		}//switch
		done = true;
		break;
	}//while
	return;
}//function

void modifyOrRemoveActor(BSTree<Actor, string>* _actorTree)
{//modifying or removing entries in the actor category
	vector<Actor> sortVec;
	vector<Actor> foundVec;
	Actor delActor;
	int choice;
	char input;
	string tempstring;
	_actorTree->fillActorVector(sortVec);
	_actorTree->clearTree();
	_actorTree->setRoot(nullptr);
	//_actorTree = new BSTree<Actor, string>;
	for (int i = 0; i < sortVec.size(); i++)
		_actorTree->addNode(sortVec[i].getYear(), sortVec[i]);
	cout << "What year would you like to modify? " << endl;
	cin.ignore();
	getline(cin, tempstring);
	for (int i = 0; i < sortVec.size(); i++)
	{
		if (sortVec[i].getYear().find(tempstring) != string::npos)
		{
			foundVec.push_back(sortVec[i]);
			cout << sortVec[i] << endl;
		}
	}
	cout << "Enter the name of the actor whose entry you would like to modify or delete." << endl;
	cin.ignore();
	getline(cin, tempstring);
	cout << "Would you like to modify or delete this entry?" << endl << "1. Modify " << endl << "2. Delete" << endl;
	cin >> choice;

	//finding the matching entry

	for (int i = 0; i < foundVec.size(); i++)
	{
		if (foundVec[i].getName().find(tempstring) != string::npos)
			delActor = foundVec[i];
	}
	if (choice == 1)
		_actorTree->modifyActorNode(tempstring, delActor);
	else if (choice == 2)
		_actorTree->deleteNode(delActor.getYear());
	else
		cout << "Invalid choice." << endl;
	
}

void sortActor(BSTree<Actor, string>* _actorTree)
{//if the user wishes to sort, we move the tree to a vector, delete the tree, repopulate the tree from the vector using a new key
	vector<Actor> sortVec;
	int choice;
	_actorTree->fillActorVector(sortVec);
	bool done = false;
	while (!done)
	{
		cout << "How would you like to sort the database?" << endl;
		cout << "1. Year " << endl << "2. Film " << endl << "3. Actor Names" << "4. Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			_actorTree->clearTree();
			_actorTree->setRoot(nullptr);
			for (int i = 0; i < sortVec.size(); i++)
				_actorTree->addNode(sortVec[i].getYear(), sortVec[i]);
			cout << "The database is now sorted by year." << endl;
			break;
		case 2:
			_actorTree->clearTree();
			_actorTree->setRoot(nullptr);
			for (int i = 0; i < sortVec.size(); i++)
				_actorTree->addNode(sortVec[i].getFilm(), sortVec[i]);
			cout << "The database is now sorted by Film. " << endl;
			break;
		case 3:
			_actorTree->clearTree();
			_actorTree->setRoot(nullptr);
			for (int i = 0; i < sortVec.size(); i++)
				_actorTree->addNode(sortVec[i].getName(), sortVec[i]);
			cout << "The database is now sorted by Actor/Actress name. " << endl;
			break;
		case 4:
			done = true;
			break;
		default:
			cout << "Please enter a choice from the menu." << endl;
		}
	}
}


void pictureMenu(BSTree<Picture, string>* _pictureTree)
{//main driver function for the picture database
	BSTree<Picture, string> *pictureTree = new BSTree<Picture, string>;
	vector<Picture> pictureVector;
	int choice, tempduration, tempmeta, tempNom;
	double temprating;
	bool done = false;
	Picture tempPicture;
	string tempTitle, tempgenre, temprelease, tempsyn, tempyear;

	while (!done)
	{
		cout << "You are in the Movie database. " << endl;
		cout << "What would you like to do? " << endl;
		cout << "1. Add a record " << endl;
		cout << "2. Search for a film " << endl;
		cout << "3. Sort the database " << endl;
		cout << "4. Modify or delete a record " << endl;
		cout << "5. Print database to a file " << endl;
		cout << "6. Go back to main menu " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "What is the name of the film you would like to add: ";
			cin.ignore();
			getline(cin, tempTitle);
			tempPicture.setName(tempTitle);
			cout << endl << "What year did the film debut: ";
			cin >> tempyear;
			tempPicture.setYear(tempyear);
			cout << endl << "How many nominations did it receive: ";
			cin >> tempNom;
			tempPicture.setNominations(tempNom);
			cout << endl << "How was the film rated (0.0 to 10.0): ";
			cin >> temprating;
			tempPicture.setRating(temprating);
			cout << endl << "How long was the film (in minutes): ";
			cin >> tempduration;
			tempPicture.setDuration(tempduration);
			cout << endl << "What was the film's genre: ";
			cin.ignore();
			getline(cin, tempgenre);
			tempPicture.setGenre1(tempgenre);
			cout << endl << "What was its secondary genre: ";
			//cin.ignore();
			getline(cin, tempgenre);
			tempPicture.setGenre2(tempgenre);
			cout << endl << "What month was the film released: ";
			//cin.ignore();
			getline(cin, temprelease);
			tempPicture.setRelease(temprelease);
			cout << endl << "What metacritic score did the film receive (0 - 100): ";
			cin >> tempmeta;
			tempPicture.setMetacritic(tempmeta);
			cout << endl << "Please give a brief synopsis: ";
			cin.ignore();
			getline(cin, tempsyn);
			tempPicture.setSynopsis(tempsyn);
			_pictureTree->addNode(tempPicture.getName(), tempPicture);
			break;
		case 2:
			searchPicture(_pictureTree);
			break;

		case 3:
			sortPicture(_pictureTree);
			break;
		case 4:
			modifyOrRemovePic(_pictureTree);//returning here, i lose the tree
			break;
		case 5:
			_pictureTree->writePicturesToFile();
			break;
		case 6:
			done = true;
			break;
		default:
			cout << "Please enter a number from the menu." << endl;
			break;
		}
	}//while
}//function
void searchPicture(BSTree<Picture, string>* _pictureTree)
{//searching for a picture
	vector<Picture> searchVec;
	vector<Picture> foundVec;
	char choice, refineChoice;
	string tempname, tempgenre, searchName, searchgenre, tempyear, searchyear;
	int input, count = 0;
	bool done = false;
	_pictureTree->fillPicVector(searchVec);//putting into vector for the sake of search and sort. O(n) for vector. O(n^2) to resort BST
	while (!done)
	{
		cout << "a. Partial Search " << endl;
		cout << "b. Exact Search " << endl;
		cin >> choice;

		switch (toupper(choice))
		{
		case 'A':
			while (!done)
			{
				cout << "Choose a field to search by(note: case sensitive). " << endl;
				cout << "1. Title " << endl << "2. Year " << endl << "3. Genre " << endl << "4. Refine a previous search" << endl << "5. Go back " << endl;
				cin >> input;
				switch (input)
				{
				case 1:
					cout << endl << "Enter the search term for title: " << endl;
					cin.ignore();
					getline(cin, tempname);
					for (int i = 0; i < searchVec.size(); i++)
					{
						searchName = searchVec[i].getName();
						if (searchName.find(tempname) != string::npos)
							foundVec.push_back(searchVec[i]);
					}
					cout << "Here are the " << foundVec.size() << " films that matched your search" << endl;
					for (int i = 0; i < foundVec.size(); i++)
						cout << foundVec[i];
					break;
				case 2:
					cout << "Enter the film's debut year: " << endl;
					cin >> tempyear;
					for (int i = 0; i < searchVec.size(); i++)
					{
						searchyear = searchVec[i].getYear();
						if (searchyear.find(tempyear) != string::npos)
							foundVec.push_back(searchVec[i]);
					}
					cout << "Here are the " << foundVec.size() << " films that matched your search" << endl;
					for (int i = 0; i < foundVec.size(); i++)
						cout << foundVec[i];
					break;
				case 3:
					cout << "What genre would you like to search by? " << endl;
					cin.ignore();
					getline(cin, tempgenre);
					for (int i = 0; i < searchVec.size(); i++)
					{
						searchgenre = searchVec[i].getGenre1();
						if (searchyear.find(tempyear) != string::npos)
							foundVec.push_back(searchVec[i]);
						searchgenre = searchVec[i].getGenre2();
						if (searchgenre.find(tempgenre) != string::npos)
							foundVec.push_back(searchVec[i]);
					}
					cout << "Here are the " << foundVec.size() << " films that matched your search" << endl;
					for (int i = 0; i < foundVec.size(); i++)
						cout << foundVec[i];
					break;
				case 4:
					cout << endl << "Refine by:" << endl << "a. Title" << endl << "b. Year" << endl << "c. Genre" << endl << "d. Go back " << endl;
					cin >> refineChoice;
					switch (toupper(refineChoice))
					{
					case 'A':
						cout << endl << "What would you like to search for? " << endl;
						cin.ignore();
						getline(cin, tempname);
						for (int i = 0; i < foundVec.size(); i++)
						{
							searchName = foundVec[i].getName();
							if (searchName.find(tempname) != string::npos)
							{
								count++;
								cout << foundVec[i];
							}
						}
						if (count == 0)
							cout << "No records found." << endl;
						break;
					case 'B':
						cout << endl << "Enter the year: " << endl;
						cin >> tempyear;
						count = 0;
						for (int i = 0; i < foundVec.size(); i++)
						{
							searchyear = foundVec[i].getYear();
							if (searchyear == tempyear)
							{
								count++;
								cout << foundVec[i];
							}
						}
						if (count == 0)
							cout << "No records found." << endl;
						break;
					case 'C':
						cout << endl << "Enter the genre: " << endl;
						cin.ignore();
						getline(cin, tempgenre);
						for (int i = 0; i < foundVec.size(); i++)
						{
							searchgenre = foundVec[i].getGenre1();
							if (searchgenre == tempgenre)
							{
								count++;
								cout << foundVec[i];
							}
							searchgenre = foundVec[i].getGenre2();
							if (searchgenre == tempgenre)
							{
								count++;
								cout << foundVec[i];
							}
						}//for
						if (count == 0)
							cout << "No records found." << endl;
						break;
					case 'D':
						done = true;
						break;
					}
					break;
				case 5:
					done = true;
					break;
				default:
					cout << "Please enter a valid choice." << endl;
					break;
				}//switch
			}
			break;
		case 'B':
			foundVec.clear();
			cout << "What would you like to search for? " << endl;
			cout << "1. Title" << endl << "2. Year" << endl << "3. Genre" << endl;
			cin >> input;
			switch (input)
			{
			case 1:
				cout << "What title would you like to search?" << endl;
				cin.ignore();
				getline(cin, tempname);
				count = 0;
				for (int i = 0; i < searchVec.size(); i++)
				{
					if (tempname == searchVec[i].getName())
					{
						cout << searchVec[i];
						count++;
					}
				}
				if (count == 0)
					cout << "No title matches that search." << endl;
				break;
			case 2:
				cout << "What year would you like to search?" << endl;
				cin >> tempyear;
				count = 0;
				for (int i = 0; i < searchVec.size(); i++)
				{
					if (tempyear == searchVec[i].getYear())
					{
						cout << searchVec[i];
						count++;
					}
				}
				if (count == 0)
					cout << "There were no movies that year, apparently." << endl;
				break;
			case 3:
				cout << "What genre would you like to search?" << endl;
				cin.ignore();
				getline(cin, tempgenre);
				count = 0;
				for (int i = 0; i < foundVec.size(); i++)
				{
					if (tempgenre == searchVec[i].getGenre1())
					{
						count++;
						cout << foundVec[i];
					}
					if (tempgenre == searchVec[i].getGenre2())
					{
						count++;
						cout << foundVec[i];
					}
				}//for
				if (count == 0)
					cout << "No records found." << endl;
				break;
			}//switch
			break;
		}//switch
		break;
	}//while
	return;
}//function

void sortPicture(BSTree<Picture, string>* _pictureTree)
{//when sorting, we move the tree to a vector, delete the tree, repopulate the tree using the vector and new key
	vector<Picture> sortVec;
	int choice;
	_pictureTree->fillPicVector(sortVec);
	bool done = false;
	while (!done)
	{
		cout << "How would you like to sort the database?" << endl;
		cout << "1. Title " << endl << "2. Year " << endl << "3. Genre" << "4. Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			_pictureTree->clearTree();
			_pictureTree->setRoot(nullptr);
			for (int i = 0; i < sortVec.size(); i++)
				_pictureTree->addNode(sortVec[i].getName(), sortVec[i]);
			cout << "The database is now sorted by title." << endl;
			break;
		case 2:
			_pictureTree->clearTree();
			_pictureTree->setRoot(nullptr);
			for (int i = 0; i < sortVec.size(); i++)
				_pictureTree->addNode(sortVec[i].getYear(), sortVec[i]);
			cout << "The database is now sorted by year. " << endl;
			break;
		case 3:
			_pictureTree->clearTree();
			_pictureTree->setRoot(nullptr);
			for (int i = 0; i < sortVec.size(); i++)
				_pictureTree->addNode(sortVec[i].getGenre1(), sortVec[i]);
			cout << "The database is now sorted by the primary genre of each film. " << endl;
			break;
		case 4:
			done = true;
			break;
		default:
			cout << "Please enter a choice from the menu." << endl;
		}
	}
}
void modifyOrRemovePic(BSTree<Picture, string>* _pictureTree)
{//modifying or removing picture entries
	vector<Picture> sortVec;
	vector<Picture> foundVec;
	Picture delPic;
	int choice;
	char input;
	string tempname;
	_pictureTree->fillPicVector(sortVec);
	_pictureTree->clearTree();
	_pictureTree->setRoot(nullptr);
	//_pictureTree = new BSTree<Picture, string>;
	for (int i = 0; i < sortVec.size(); i++)
		_pictureTree->addNode(sortVec[i].getName(), sortVec[i]);
	cout << "What is the title of the film you would like to modify or delete? " << endl;
	cin.ignore();
	getline(cin, tempname);
	for (int i = 0; i < sortVec.size(); i++)
	{
		if (sortVec[i].getName().find(tempname) != string::npos)
		{
			foundVec.push_back(sortVec[i]);
			cout << sortVec[i] << endl;
		}
	}
	cout << "Would you like to modify or delete this title?" << endl << "1. Modify " << endl << "2. Delete" << endl;
	cin >> choice;
	for (int i = 0; i < sortVec.size(); i++)
	{
		if (sortVec[i].getName().find(tempname) != string::npos)
			delPic = sortVec[i];
	}
	if (choice == 1)
		_pictureTree->modifyPicNode(tempname, delPic);
	else if (choice == 2)
		_pictureTree->deleteNode(delPic.getName());
	else
		cout << "Invalid choice." << endl;
}
