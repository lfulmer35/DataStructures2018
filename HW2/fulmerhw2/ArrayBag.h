//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.
//Modified by TAA to remove templates and Inheritance

/** ADT bag: Array-based implementation.
 @file ArrayBag.h */


#ifndef BAG_
#define BAG_
using namespace std;//Added by Lucas Fulmer
#include <vector>
#include <string> //Added by Lucas Fulmer
#include <iostream>//Added by Lucas Fulmer
#include <sstream>//Added by Lucas Fulmer

typedef int ItemType;
class ArrayBag
{
private:
	static const int DEFAULT_BAG_SIZE = 100;
	ItemType items[DEFAULT_BAG_SIZE]; // array of bag items
   int itemCount;                    // current count of bag items 
   int maxItems;                     // max capacity of the bag
   
   // Returns either the index of the element in the array items that
   // contains the given target or -1, if the array does not contain 
   // the target.
   int getIndexOf(const ItemType& target) const;   

public:
	ArrayBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	void streamFillBag(ArrayBag& _bag, string _stringToArray);//Added by Lucas Fulmer
	//This function breaks the strings that were read in and turns them into 
	//intergers and then adds them to ArrayBag object.
	void removeDuplicate(ArrayBag& _bag);//Added by Lucas Fulmer
	//this function will remove duplicates from the Union bag
	void displayItems(ArrayBag _bag);//Added by Lucas Fulmer
	
	//FRIENDZONE
	friend ArrayBag operator +(const ArrayBag& _bag1, const ArrayBag& _bag2);
	//overloading the + to form Union bag
	friend ArrayBag operator -(const ArrayBag& _bag1, const ArrayBag& _bag2);
	//overloading the - to form difference bag

};  // end Bag


#endif
