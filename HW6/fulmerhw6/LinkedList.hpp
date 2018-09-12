#include "LinkedList.h"

template <typename DATATYPE>
LinkedList<DATATYPE>::LinkedList()//default constructor
{
	headPtr = nullptr;
}
template <typename DATATYPE>
LinkedList<DATATYPE>::~LinkedList()//destructor
{
	clear();
}

template <typename DATATYPE>
LinkedList<DATATYPE>::LinkedList(const LinkedList<DATATYPE>& list)
{
	if (list.headPtr != nullptr)
	{
		Node<DATATYPE>* currentPtr = list.headPtr;
		headPtr = new Node<DATATYPE>;
		while (currentPtr != nullptr)
		{
			push_back(currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
	}
}

template <typename DATATYPE>
LinkedList<DATATYPE>& LinkedList<DATATYPE>::operator = (const LinkedList<DATATYPE>& list)
{
	Node<DATATYPE>* currentPtr = list.headPtr;
	if (headPtr != nullptr)
		delete headPtr;


	headPtr = new Node<DATATYPE>;
	Node<DATATYPE>* copyPtr = headPtr;
	while (list.headPtr != nullptr)
	{
		copyPtr = currentPtr;
		currentPtr = currentPtr->nextPtr;
		copyPtr = copyPtr->nextPtr;
	}
	return *this;
}


template <typename DATATYPE>
bool LinkedList<DATATYPE>::push_front(DATATYPE value)//inserts a Node at the beginning of list
{
	Node<DATATYPE>* currentPtr = headPtr;
	Node<DATATYPE>* tempPtr = headPtr;

	if (currentPtr == nullptr)//In case there are no other Nodes in list
	{
		currentPtr = new Node<DATATYPE>;
		currentPtr->nextPtr = nullptr;
		currentPtr->data = value;
		headPtr = currentPtr;
		return true;
	}
	else
	{
		tempPtr = new Node<DATATYPE>;
		tempPtr->data = value;
		tempPtr->nextPtr = headPtr;
		headPtr = tempPtr;
		return true;
	}
}

template <typename DATATYPE>
bool LinkedList<DATATYPE>::insertBeforePosition(DATATYPE value, int index)//inserts a node prior to the user's index
{
 //first Node after headptr is 1
 //false if pos zero or out of range
	Node<DATATYPE>* currentPtr = headPtr;
	Node<DATATYPE>* tempPtr = headPtr;

	if (index == 0)
		return false;
	else if (index == 1)//if user chooses position 1, we'll just call the insertAtFront function
	{
		insertAtFront(value);
		return true;
	}
	else
	{
		for (int i = 0; i < index - 2; i++)
		{
			if (currentPtr->nextPtr == nullptr)//In case user's enters an index outside of the linked list
				return false;
			else
				currentPtr = currentPtr->nextPtr;
		}
		tempPtr = new Node<DATATYPE>;
		tempPtr->data = value;
		tempPtr->nextPtr = currentPtr->nextPtr;
		currentPtr->nextPtr = tempPtr;
		return true;
	}
}

template <typename DATATYPE>
bool LinkedList<DATATYPE>::push_back(DATATYPE value)
{
	Node<DATATYPE>* currentPtr;
	currentPtr = headPtr;
	if (currentPtr == nullptr)//in case the list is empty
	{
		currentPtr = new Node<DATATYPE>;
		currentPtr->data = value;
		currentPtr->nextPtr = nullptr;
		headPtr = currentPtr;
		return true;
	}
	else
	{
		while (currentPtr->nextPtr != nullptr)
			currentPtr = currentPtr->nextPtr;
		currentPtr->nextPtr = new Node<DATATYPE>;
		currentPtr = currentPtr->nextPtr;
		currentPtr->data = value;
		currentPtr->nextPtr = nullptr;
		return true;
	}
}

template <typename DATATYPE>
bool LinkedList<DATATYPE>::pop_front() throw(int)//deleting the first Node
{
	Node<DATATYPE>* tempPtr;
	tempPtr = headPtr;
	if (tempPtr == nullptr)
		throw -1;
	else if (tempPtr->nextPtr == nullptr)
	{
		tempPtr = tempPtr->nextPtr;
		delete tempPtr;
		headPtr = nullptr;
		return true;
	}
	else
	{
		headPtr = tempPtr->nextPtr;
		delete tempPtr;
		return true;
	}
}

template <typename DATATYPE>
bool LinkedList<DATATYPE>::deletePosition(int index)//deleting a Node at the user's index
{
 //first Node after headptr is 1
 //false if pos zero or out of range
	Node<DATATYPE>* tempPtr = headPtr;
	Node<DATATYPE>* currentPtr = headPtr;

	if (index == 0)//don't want to delete the headPtr
		return false;
	else if (index == 1)
	{
		headPtr = tempPtr->nextPtr;
		delete tempPtr;
		return true;
	}
	else
		while (currentPtr->nextPtr != nullptr)
		{
			for (int i = 1; i < index; i++)
			{
				tempPtr = currentPtr;
				currentPtr = currentPtr->nextPtr;
			}
			tempPtr->nextPtr = currentPtr->nextPtr;
			delete currentPtr;
			return true;
		}
}

template <typename DATATYPE>
bool LinkedList<DATATYPE>::pop_back()//deleting the last Node
{
 //false if empty
	Node<DATATYPE>* tempPtr = headPtr;
	Node<DATATYPE>* removePtr = headPtr;

	if (removePtr == nullptr)
		return false;
	else
	{
		while (removePtr->nextPtr != nullptr)
		{
			tempPtr = removePtr;
			removePtr = removePtr->nextPtr;
		}
		delete removePtr;
		tempPtr->nextPtr = nullptr;
	}
	return true;
}

template <typename DATATYPE>
void LinkedList<DATATYPE>::printList()
{
	Node<DATATYPE>* currentPtr = headPtr;
	int num = 1;
	while (currentPtr != nullptr)
	{
		cout << "Node " << num << " is " << currentPtr->data << endl;
		currentPtr = currentPtr->nextPtr;
		num++;
	}
}


template <typename DATATYPE>
void LinkedList<DATATYPE>::clear()//emptying our list and deleting all Nodes while setting headPtr to nullptr
{
	Node<DATATYPE>* delPtr;
	delPtr = headPtr;
	if (delPtr == nullptr)
		delete headPtr;
	else
	{
		while (delPtr != nullptr)
		{
			delPtr = delPtr->nextPtr;
			delete headPtr;
			headPtr = delPtr;
		}
		delete headPtr;
	}
	headPtr = nullptr;
}

/*template <typename DATATYPE>
ostream& operator << (ostream &out, LinkedList<DATATYPE> const &list)//overloading the << operator so we can print our list to console
{
	Node<DATATYPE>* currentPtr = list.headPtr;
	int num = 1;
	while (currentPtr != nullptr)
	{
		out << "Node " << num << " is " << currentPtr->data << endl;
		currentPtr = currentPtr->nextPtr;
		num++;
	}
	return out;
}*/