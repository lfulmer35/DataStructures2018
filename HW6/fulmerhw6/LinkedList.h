//Lucas Fulmer
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
using namespace std;

template <typename DATATYPE>
struct Node
{
	DATATYPE data;
	Node<DATATYPE>* nextPtr;
};

template <typename DATATYPE>
class LinkedList
{
private:
	Node<DATATYPE> *headPtr;
public:
	LinkedList();//default constructor
	~LinkedList();//destructor
	LinkedList(const LinkedList<DATATYPE>& list);//copy constructor
	LinkedList& operator =(const LinkedList<DATATYPE>& list);//overloaded assignment operator
	bool push_front(DATATYPE value);
	bool insertBeforePosition(DATATYPE value, int index);
	bool push_back(DATATYPE value);
	bool pop_front() throw(int);
	bool deletePosition(int index);
	bool pop_back();
	void printList();
	void clear(); //frees memory for entire list
	//friend ostream& operator << (ostream &out, LinkedList<DATATYPE> const &list);
};
#endif // !LINKEDLIST_H
