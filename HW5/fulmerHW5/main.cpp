//Lucas Fulmer
#include "LinkedList.h"

int main()
{
	LinkedList list;
	int index;
	char _data, _data2, _data3, _data4, prompt;
	
	//This main calls each function and displays the effects
	cout << "Enter a character for the first Node: " << endl;
	cin >> _data;
	list.insertAtFront(_data);
	cout << list << endl;
	cout << "Enter another character to insert in the front of the list: " << endl;
	cin >> _data2;
	list.insertAtFront(_data2);
	cout << list << endl;
	cout << "Enter another character and I'll add it to the back of the list: " << endl;
	cin >> _data3;
	list.insertAtBack(_data3);
	cout << list << endl;
	cout << "Enter a final character to insert: " << endl;
	cin >> _data4;
	cout << "At what index would you like to place this node:(1-3) " << endl;
	cin >> index;
	list.insertBeforePosition(_data4, index);
	cout << list << endl;
	cout << "Now we'll delete a node. What position would you like deleted? " << endl;
	cin >> index;
	list.deletePosition(index);
	cout << list << endl;
	cout << "Now deleting from the back: " << endl;
	list.deleteAtBack();
	cout << list << endl;
	cout << "Now deleting from the front: " << endl;
	list.deleteAtFront();
	cout << list << endl;
	cout << "I've refilled the list and will now call the clear function: " << endl;
	list.insertAtBack(_data);
	list.insertAtBack(_data2);
	list.insertAtBack(_data3);
	list.insertAtBack(_data4);
	cout << "Here is the list before calling clear: " << endl << list << endl << endl;
	list.clear();
	cout << "Here is the list after calling clear: " << endl << list << endl;

	//all lines are f(1), overall complexity of main is O(1)
	return 0;
}