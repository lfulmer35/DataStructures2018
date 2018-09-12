//Lucas Fulmer
#include "LinkedList.h"

LinkedList::LinkedList()//default constructor
{
	headPtr = nullptr;
}
LinkedList::~LinkedList()//destructor
{
	clear();
}
bool LinkedList::insertAtFront(char value)//inserts a Node at the beginning of list
{//overall complexity is f(2)+f(5)+f(5) = f(12), O(1)
	Node* currentPtr = headPtr;
	Node* tempPtr = headPtr;
	
	if (currentPtr == nullptr)//In case there are no other Nodes in list
	{//f(5)
		currentPtr = new Node;
		currentPtr->nextPtr = nullptr;
		currentPtr->data = value;
		headPtr = currentPtr;
		return true;
	}
	else
	{//f(5)
		tempPtr = new Node;
		tempPtr->data = value;
		tempPtr->nextPtr = headPtr;
		headPtr = tempPtr;
		return true;
	}
}
bool LinkedList::insertBeforePosition(char value, int index)//inserts a node prior to the user's index
{//overall complexity: f(n) + f(10), O(n)
	//first Node after headptr is 1
	//false if pos zero or out of range
	Node* currentPtr = headPtr;//f(1)
	Node* tempPtr = headPtr;//f(1)

	if (index == 0)//f(1)
		return false;
	else if (index == 1)//if user chooses position 1, we'll just call the insertAtFront function
	{//f(1)
		insertAtFront(value);
		return true;
	}
	else
	{//f(n) + f(1) + f(1) + f(5) = f(n) + f(7)
		for (int i = 0; i < index - 2; i++)
		{
			if (currentPtr->nextPtr == nullptr)//In case user's enters an index outside of the linked list
				return false;
			else
				currentPtr = currentPtr->nextPtr;
		}
		tempPtr = new Node;
		tempPtr->data = value;
		tempPtr->nextPtr = currentPtr->nextPtr;
		currentPtr->nextPtr = tempPtr;
		return true;
	}
}
bool LinkedList::insertAtBack(char value)
{//overall complexity f(n) + f(1) + f(1) + f(5) + f(5) = f(n) + f(12), O(n)
	Node* currentPtr;//f(1)
	currentPtr = headPtr;//f(1)
	if (currentPtr == nullptr)//in case the list is empty
	{//f(5)
		currentPtr = new Node;
		currentPtr->data = value;
		currentPtr->nextPtr = nullptr;
		headPtr = currentPtr;
		return true;
	}
	else
	{//f(n) + f(5)
		while (currentPtr->nextPtr != nullptr)
			currentPtr = currentPtr->nextPtr;
		currentPtr->nextPtr = new Node;
		currentPtr = currentPtr->nextPtr;
		currentPtr->data = value;
		currentPtr->nextPtr = nullptr;
		return true;
	}
}
bool LinkedList::deleteAtFront()//deleting the first Node
{//f(1)+f(1)+f(1)+f(5)+f(3) = f(11), O(1)
	Node* tempPtr;//f(1)
	tempPtr = headPtr;//f(1)
	if (tempPtr == nullptr)//f(1)
		return false;
	else if (tempPtr->nextPtr == nullptr)
	{//f(5)
		tempPtr = tempPtr->nextPtr;
		delete tempPtr;
		headPtr = nullptr;
		return true;
	}
	else
	{//f(3)
		headPtr = tempPtr->nextPtr;
		delete tempPtr;
		return true;
	}
}
bool LinkedList::deletePosition(int index)//deleting a Node at the user's index
{//f(1)+f(1)+f(1)+f(3)+f(3)+f(n) = f(n) + f(9), O(n)
	//first Node after headptr is 1
	//false if pos zero or out of range
	Node* tempPtr = headPtr;//f(1)
	Node* currentPtr = headPtr;//f(1)
	
	if (index == 0)//don't want to delete the headPtr
		return false;//f(1)
	else if (index == 1)
	{//f(3)
		headPtr = tempPtr->nextPtr;
		delete tempPtr;
		return true;
	}
	else
		while (currentPtr->nextPtr != nullptr)
		{//f(3)
			for (int i = 1; i < index; i++)
			{//f(n)
				tempPtr = currentPtr;
				currentPtr = currentPtr->nextPtr;
			}
			tempPtr->nextPtr = currentPtr->nextPtr;
			delete currentPtr;
			return true;
		}
}
bool LinkedList::deleteAtBack()//deleting the last Node
{//f(n+2)+f(5) = f(n) + f(7), O(n)
	//false if empty
	Node* tempPtr = headPtr;//f(1)
	Node* removePtr = headPtr;//f(1)

	if (removePtr == nullptr)//f(1)
		return false;
	else
	{
		while (removePtr->nextPtr != nullptr)
		{//f(n+2)
			tempPtr = removePtr;
			removePtr = removePtr->nextPtr;
		}
		delete removePtr;//f(1)
		tempPtr->nextPtr = nullptr;//f(1)
	}
	return true;
}
void LinkedList::clear()//emptying our list and deleting all Nodes while setting headPtr to nullptr
{//f(1)+f(1)+f(1)+f(n+3)+f(1)+f(1) = f(n) + f(8), O(n)
	Node* delPtr;//f(1)
	delPtr = headPtr;//f(1)
	if (delPtr == nullptr)//f(1)
		delete headPtr;
	else
	{//f(n+3)
		while (delPtr != nullptr)
		{
			delPtr = delPtr->nextPtr;
			delete headPtr;
			headPtr = delPtr;
		}
		delete headPtr;//f(1)
	}
	headPtr = nullptr;//f(1)
}
ostream& operator << (ostream &out, LinkedList const &list)//overloading the << operator so we can print our list to console
{//f(1)+f(1)+f(n+3) = f(n) + f(5), O(n)
	Node* currentPtr = list.headPtr;//f(1)
	int num = 1;//f(1)
	while (currentPtr != nullptr)//f(n+3)
	{
		out << "Node " << num << " is " << currentPtr->data << endl;
		currentPtr = currentPtr->nextPtr;
		num++;
	}
	return out;
}