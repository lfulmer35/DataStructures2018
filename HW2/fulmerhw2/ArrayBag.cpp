//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.
//Modified by TAA to remove Template and Inheritance

/** @file ArrayBag.cpp */

#include "ArrayBag.h"

ArrayBag::ArrayBag() : itemCount(0), maxItems(DEFAULT_BAG_SIZE)
{
}  // end default constructor


int ArrayBag::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize


bool ArrayBag::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty


bool ArrayBag::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add


bool ArrayBag::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove


void ArrayBag::clear()
{
	itemCount = 0;
}  // end clear


int ArrayBag::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int searchIndex = 0;
   while (searchIndex < itemCount)
   {
      if (items[searchIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      searchIndex++;
   }  // end while
   
   return frequency;
}  // end getFrequencyOf


bool ArrayBag::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

// private

int ArrayBag::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   // if the ArrayBag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf


//************All functions below this comment were developed by Lucas Fulmer**************


void ArrayBag::streamFillBag(ArrayBag& _bag, string _stringToArray)
//This function takes the string that was read in and breaks it into smaller strings.
//It then changes them to intergers and adds them to the ArrayBag
{
	istringstream ss(_stringToArray);
	string subString;
	vector<string>tempVector;
	while (getline(ss, subString, ' '))
		tempVector.push_back(subString);
	for (int i = 0; i < tempVector.size(); i++)
	{
		signed int tempInt = stoi(tempVector[i]);
		_bag.add(tempInt);
	}
}

void ArrayBag::removeDuplicate(ArrayBag& _bag)
//This function searches the Union Bag and removes duplicate numbers.
//It uses the syntax from existing .remove() function to accomplish this.
{
	int num;
	for (int i = 0; i < _bag.getCurrentSize(); i++)
	{
		num = _bag.items[i];
		for (int x = i + 1; x < _bag.getCurrentSize(); x++)
			if (num == _bag.items[x])
			{
				itemCount--;	//from the .remove() function above
				_bag.items[x] = _bag.items[itemCount];
				x--;
			}
	}
}

void ArrayBag::displayItems(ArrayBag _bag)
{
	for (int i = 0; i < itemCount; i++)
		{
			cout << _bag.items[i] << ", ";
		}
}
