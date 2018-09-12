#include "student.h"
#include "LinkedList.h"
#include "LinkedList.hpp"
#include <fstream>

using namespace std;

int main()
{

	LinkedList<int>* intList = new LinkedList<int>;
	
	cout << endl << endl <<  "********************************************************************" << endl << endl;
	cout << "List of int's is currently empty." << endl;
	intList->push_front(30);
	intList->push_front(20);
	intList->push_front(10);
	cout << "After push_front 30, 20, 10; here is our current list." << endl;
	intList->printList();
	cout << "Now a push_back of 40, 50." << endl;
	intList->push_back(40);
	intList->push_back(50);
	intList->printList();
	cout << "Now we'll pop_front" << endl;
	intList->pop_front();
	intList->printList();
	cout << "After a pop_back." << endl;
	intList->pop_back();
	intList->printList();
	LinkedList<int>* copyList(intList);
	cout << "After calling the copy constructor, here is the copied list." << endl;
	copyList->printList();
	LinkedList<int>* otherList = intList;
	cout << "After using the overloaded assignment operator on another new list, here is the new list." << endl;
	otherList->printList();
	cout << "To demonstrate exception handling, we will pop front until there is nothing remaining in the list, then do it one more time." << endl;
	try
	{
		cout << "One pop." << endl;
		otherList->pop_front();
		otherList->printList();
		cout << "Two pops." << endl;
		otherList->pop_front();
		otherList->printList();
		cout << "Three pops." << endl;
		otherList->pop_front();
		cout << "Four pops.....HERE IT COMES!!!!" << endl;
		otherList->pop_front();
	}
	catch (int e)
	{
		if (e == -1)
			cout << "I'm an exception! You popped too many times!." << endl;
	}
	otherList->clear();
	copyList->clear();
	intList->clear();

	cout << endl << endl << "Okay, now we'll read-in the student file and push_front into a List<Student>." << endl;
	LinkedList<Student>* studentList = new LinkedList<Student>;
	ifstream infile;
	Student tempStudent;
	infile.open("students.dat", ios::in | ios::binary);
	while (infile.read((char*)& tempStudent, sizeof(Student)))
	{
		studentList->push_front(tempStudent);
	}

	infile.close();
	cout << "Read-in complete. Now we'll print the List<Student>." << endl << endl;
	studentList->printList();

	return 0;

}
