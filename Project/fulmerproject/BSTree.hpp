//Lucas Fulmer


//To be used in conjunction with BSTree.h and Node.h
//When you modify this, please add your name and list any changes that you made
//A few member functions have been left blank so you, the student can implemement

/*Template Directions: #include "BSTREEInt.hpp"
but do NOT compile it (or add it to the project)*/
#include "BSTree.h"
#include <sstream>												//added by Lucas Fulmer
#include <fstream>												//added by Lucas Fulmer

// Constructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::BSTree() {
	root = nullptr;
}

// Destructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::~BSTree() {
    if (root !=nullptr)
        freeNode(root);
}

// Free the node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::freeNode(Node<DATATYPE, KEYTYPE> * leaf)
{
	//This code added by Lucas Fulmer
	if (leaf == nullptr)
		delete leaf;

	else
	{
		freeNode(leaf->Left());
		freeNode(leaf->Right());
		delete leaf;
	}
}

// Add a node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, DATATYPE &data)
{
	if (Root() == nullptr)
	{
		Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
		newNodePtr->setKey(key);
		newNodePtr->setData(data);
		root = newNodePtr;
		root->setParent(root);

	}
	else
		addNode(key, root, data);
}

// Add a node (private)
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data) {
	//This code was developed by Lucas Fulmer
	if (Root() == nullptr)
	{
		Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
		newNodePtr->setKey(key);
		newNodePtr->setData(data);
		root = newNodePtr;
		root->setParent(root);
	}
	else
	{
		if (key < leaf->Key())
		{
			if (leaf->Left() == nullptr)
			{
				Node<DATATYPE, KEYTYPE>* newNodePtr = new Node<DATATYPE, KEYTYPE>;
				newNodePtr->setKey(key);
				newNodePtr->setData(data);
				newNodePtr->setParent(leaf);
				leaf->setLeft(newNodePtr);
			}
			else
				addNode(key, leaf->Left(), data);
		}
		else
		{
			if (leaf->Right() == nullptr)
			{
				Node<DATATYPE, KEYTYPE>* newNodePtr = new Node<DATATYPE, KEYTYPE>;
				newNodePtr->setKey(key);
				newNodePtr->setData(data);
				newNodePtr->setParent(leaf);
				leaf->setRight(newNodePtr);
			}
			else
				addNode(key, leaf->Right(), data);
		}
	}
}

template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key)
{
	return findNode(key, root);
}

// Find a node
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node)
{
	//This code developed by Lucas Fulmer
	if (node == nullptr)
		return Root();
	else if (node->Key() == key)
		return node;
	else if (node->Key() < key)
		return findNode(key, node->Right());
	else
		return findNode(key, node->Left());
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder()
{
	printInorder(root);
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder(Node<DATATYPE, KEYTYPE> * node)
{
	//This code developed by Lucas Fulmer
	if (node == nullptr)
		return;
	printInorder(node->Left());
	print(cout, node->Data());
	printInorder(node->Right());
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::print(ostream & out, const DATATYPE & data)
{
	out << data; // edited by Lucas Fulmer
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::deleteNode(KEYTYPE key)
{
	setRoot(deleteNode(Root(), key));
}

//deleteNode (Private)
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::deleteNode(Node<DATATYPE, KEYTYPE> * aRoot,KEYTYPE value)
{
   
	/* Given a binary search tree and a key, this function deletes the key
	and returns the new root */
	
	// base case
	if (aRoot == nullptr) return aRoot;

	// If the key to be deleted is smaller than the aRoot's key,
	// then it lies in left subtree
	if (value < aRoot->Key())
		aRoot->setLeft(deleteNode(aRoot->Left(), value));

	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if (value > aRoot->Key())
		aRoot->setRight(deleteNode(aRoot->Right(), value));

	// if key is same as root's key, then This is the node
	// to be deleted
	else
	{
		// node with only one child or no child
		if (aRoot->Left() == nullptr)
		{
			Node<DATATYPE, KEYTYPE> *temp = aRoot->Right();
			delete aRoot;	
			return temp;
		}
		else if (aRoot->Right() == nullptr)
		{
			Node<DATATYPE, KEYTYPE> *temp = aRoot->Left();
			delete aRoot;
			return temp;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		Node<DATATYPE, KEYTYPE> * temp = min(aRoot->Right());

		// Copy the inorder successor's content to this node
		aRoot->setKey(temp->Key());
		aRoot->setData(temp->Data());

		// Delete the inorder successor
		aRoot->setRight(deleteNode(aRoot->Right(), temp->Key()));
	}
	return aRoot;
}


// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::min(Node<DATATYPE, KEYTYPE> * node)
{
	Node<DATATYPE, KEYTYPE> * current = node;

	/* loop down to find the leftmost leaf */
	while (current->Left() != nullptr)
		current = current->Left();

	return current;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::max(Node<DATATYPE, KEYTYPE> * node)
{
	Node<DATATYPE, KEYTYPE> * tempNode = node;
	if (node == nullptr)
		tempNode = nullptr;
	else if (node->Right())
		tempNode = max(node->Right());
	else
		tempNode = node;

	return tempNode;
}
template<typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::readInActorfile()
{
	//This function developed by Lucas Fulmer
	string tempstring, streamyear, streamwinner, linestring;
	Actor tempActor;
	int tempyear;
	bool tempwinner;
	ifstream infile;

	infile.open("actor-actress.csv");

	if (!infile.good())
	cout << "Error opening actor file." << endl;
	else
	{
		getline(infile, linestring);
		while (getline(infile, linestring))
		{
			stringstream substring(linestring);
			
			getline(substring, tempstring, ',');
			tempActor.setYear(tempstring);

			getline(substring, tempstring, ',');
			tempActor.setAward(tempstring);

			getline(substring, tempstring, ',');
			stringstream streamwinner(tempstring);
			streamwinner >> tempwinner;
			tempActor.setWinner(tempwinner);

			getline(substring, tempstring, ',');
			tempActor.setName(tempstring);

			getline(substring, tempstring, ',');
			tempActor.setFilm(tempstring);

			addNode(tempActor.getName(), tempActor);
		}
		infile.close();
	}
}
template<typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::readInPicturefile()
{
	//This function developed by Lucas Fulmer
	string tempstring, linestring, streamyear, streamrating, streamduration, streamnominations, streammeta;
	Picture tempPicture;
	double tempRating;
	int tempyear, tempNominations, tempDuration, tempMeta;
	ifstream infile;
	infile.open("pictures.csv");

	if (!infile.good())
		cout << "Error opening picture.csv" << endl;
	else
	{
		getline(infile, linestring);
		while (getline(infile, linestring))
		{
			stringstream substring(linestring);

			getline(substring, tempstring, ',');
			tempPicture.setName(tempstring);

			getline(substring, tempstring, ',');
			tempPicture.setYear(tempstring);

			getline(substring, tempstring, ',');
			stringstream streamnominations(tempstring);
			streamnominations >> tempNominations;
			tempPicture.setNominations(tempNominations);

			getline(substring, tempstring, ',');
			stringstream streamrating(tempstring);
			streamrating >> tempRating;
			tempPicture.setRating(tempRating);

			getline(substring, tempstring, ',');
			stringstream streamduration(tempstring);
			streamduration >> tempDuration;
			tempPicture.setDuration(tempDuration);

			getline(substring, tempstring, ',');
			tempPicture.setGenre1(tempstring);

			getline(substring, tempstring, ',');
			tempPicture.setGenre2(tempstring);

			getline(substring, tempstring, ',');
			tempPicture.setRelease(tempstring);

			getline(substring, tempstring, ',');
			stringstream streammeta(tempstring);
			streammeta >> tempMeta;
			tempPicture.setMetacritic(tempMeta);

			getline(substring, tempstring, ',');
			tempPicture.setSynopsis(tempstring);

			addNode(tempPicture.getName(), tempPicture);
		}
		infile.close();
	}
}

template<typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::fillPicVector(vector<Picture>& _vec)
{
	fillPicVector(_vec, root);
}

template<typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::fillPicVector(vector<Picture>& _vec, Node<DATATYPE, KEYTYPE> * node)
{//This function allows us to move the tree to a vector
//It is used when we need to sort the tree or if the user is searching based on items other than the key
//By moving the tree to a vector we have complexity O(n) for sorting rather than O(n^2) to resort a tree
//Also, if the user narrows their search we can decrease the size of a vector so that n is smaller
	Picture tempPic;

	if (node == nullptr)
		return;
	tempPic = node->Data();
	_vec.push_back(tempPic);
	fillPicVector(_vec, node->Left());
	fillPicVector(_vec, node->Right());
}

template<typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::clearTree()
{
	if (root != nullptr)
		freeNode(root);
}

template<typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::writePicturesToFile()
{
	ofstream outfile;
	string filename;
	cout << "What would you like to name the file (use format yourfilename.csv)" << endl;
	cin.ignore();
	getline(cin, filename);
	outfile.open(filename);
	outfile << "Title, Year, Nominations, Rating, Duration, Genre1, Genre2, Release, Metacritic, Synopsis" << endl;
	if (root != nullptr)
		writePicturesToFile(root, outfile);
	outfile.close();
}
template<typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::writePicturesToFile(Node<DATATYPE, KEYTYPE> * node, ostream& _out)
{
	Picture tempPic;

	if (node == nullptr)
		return;

	writePicturesToFile(node->Left(), _out);
	tempPic = node->Data();
	_out << tempPic.getName() << ',' << tempPic.getYear() << ',' << tempPic.getNominations() << ',' << tempPic.getRating()
		<< ',' << tempPic.getDuration() << ',' << tempPic.getGenre1() << ',' << tempPic.getGenre2() << ','
		<< tempPic.getRelease() << ',' << tempPic.getMetacritic() << ',' << tempPic.getSynopsis() << endl;
	writePicturesToFile(node->Right(), _out);
}

template<typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::modifyPicNode(KEYTYPE key, Picture _picture)
{//This function is called when the user desires to modify a picture
	Picture modPicture;
	int choice, tempint;
	double temprating;
	string tempstring;
	bool done = false;

	modPicture = _picture;
	while (!done) 
	{
		cout << "What field would you like to modify?" << endl;
		cout << "1. Title" << endl << "2. Year" << endl << "3. Nominations" << endl << "4. Rating"
			<< endl << "5. Duration" << endl << "6. Primary genre" << endl << "7. Release" << endl
			<< "8. Metacritic score" << endl << "9. Synopsis" << endl << "10. Exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "What is the new title? " << endl;
			cin.ignore();
			getline(cin, tempstring);
			modPicture.setName(tempstring);
			break;
		case 2:
			cout << "What year was it made? " << endl;
			cin.ignore();
			getline(cin, tempstring);
			modPicture.setYear(tempstring);
			break;
		case 3:
			cout << "How many nominations? " << endl;
			cin >> tempint;
			modPicture.setNominations(tempint);
			break;
		case 4:
			cout << "What rating did it receive (0.0 to 10.0)?" << endl;
			cin >> temprating;
			modPicture.setRating(temprating);
			break;
		case 5:
			cout << "How long was the film (in minutes)?" << endl;
			cin >> tempint;
			modPicture.setDuration(tempint);
			break;
		case 6:
			cout << "What is the new genre?" << endl;
			cin.ignore();
			getline(cin, tempstring);
			modPicture.setGenre2(tempstring);
			break;
		case 7:
			cout << "What month was it released? " << endl;
			cin.ignore();
			getline(cin, tempstring);
			modPicture.setRelease(tempstring);
			break;
		case 8:
			cout << "What was the Metacritic score (0-100)? " << endl;
			cin >> tempint;
			modPicture.setMetacritic(tempint);
			break;
		case 9:
			cout << "What is the synopsis? " << endl;
			cin.ignore();
			getline(cin, tempstring);
			modPicture.setSynopsis(tempstring);
			break;
		case 10:
			deleteNode(key);
			addNode(modPicture.getName(), modPicture);
			cout << "The entry has been modified." << endl;
			done = true;
			break;
		}
	}
}

template<typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::writeActorsToFile()
{
	ofstream outfile;
	string filename;
	cout << "What would you like to name the file (use format yourfilename.csv)" << endl;
	cin.ignore();
	getline(cin, filename);
	outfile.open(filename);
	outfile << "Year, Award, Winner, Name, Film" << endl;
	if (root != nullptr)
		writeActorsToFile(root, outfile);
	outfile.close();
}

template<typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::writeActorsToFile(Node<DATATYPE, KEYTYPE> * node, ostream& _out)
{
	Actor tempActor;

	if (node == nullptr)
		return;

	writeActorsToFile(node->Left(), _out);
	tempActor = node->Data();
	_out << tempActor.getYear() << ',' << tempActor.getAward() << ',' << tempActor.getWinner() << ',' << tempActor.getName() << ',' << tempActor.getFilm() << endl;
	writeActorsToFile(node->Right(), _out);
}

template<typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::fillActorVector(vector<Actor>& _vec)
{
	fillActorVector(_vec, root);
}

template<typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::fillActorVector(vector<Actor>& _vec, Node<DATATYPE, KEYTYPE> * node)
{
	Actor tempActor;

	if (node == nullptr)
		return;
	tempActor = node->Data();
	_vec.push_back(tempActor);
	fillActorVector(_vec, node->Left());
	fillActorVector(_vec, node->Right());
}

template<typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::modifyActorNode(KEYTYPE key, Actor _actor)//work on this
{//This function is called when the user desires to modify an actor/actress entry
	Actor modActor;
	int choice;
	char tempwin;
	string tempstring;
	bool done = false;

	modActor = _actor;
	while (!done)
	{
		cout << "What field would you like to modify?" << endl;
		cout << "1. Year" << endl << "2. Award" << endl << "3. Winner" << endl << "4. Name"
			<< endl << "5. Film" << endl << "6. Exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "What is the new year? " << endl;
			cin.ignore();
			getline(cin, tempstring);
			modActor.setYear(tempstring);
			break;
		case 2:
			cout << "What was the award? " << endl;
			cin.ignore();
			getline(cin, tempstring);
			modActor.setAward(tempstring);
			break;
		case 3:
			cout << "Winner (Y or N)? " << endl;
			cin >> tempwin;
			if (toupper(tempwin) == 'Y')
				modActor.setWinner(1);
			else
				modActor.setWinner(0);
			break;
		case 4:
			cout << "What was the actor's/actress' name?" << endl;
			cin.ignore();
			getline(cin, tempstring);
			modActor.setName(tempstring);
			break;
		case 5:
			cout << "What was the title of the film?" << endl;
			cin.ignore();
			getline(cin, tempstring);
			modActor.setFilm(tempstring);
			break;
		case 6:
			deleteNode(key);
			addNode(modActor.getYear(), modActor);
			cout << "The entry has been modified." << endl;
			done = true;
			break;
		}
	}
}