//Lucas Fulmer

#include "MyVector.h"

HW4::MyVector::MyVector()
{
	vec = new T[vsize];//f(1)
}
HW4::T HW4::MyVector:: operator[] (int index)
{
	T _indexValue;//f(1)
	_indexValue = vec[index];//f(1)
	return _indexValue;
}
void HW4::MyVector::pop_back()
{
	/*Overall complexity is :
	f(1) + f(1) + f(1) + f(1) + f(1) + f(1) + f(n) + f(n) = f(6) + f(2n)*/
	T* tempVec = nullptr;//f(1)
	tempVec = new T[vsize - 1];//f(1)
	for (int i = 0; i < vsize - 1; i++)//loop dependent on vsize (n), so f(n)
		tempVec[i] = vec[i];//f(1)

	vsize -= 1;//f(1)
	vec = new T[vsize];//f(1)
	for (int i = 0; i < vsize; i++)//f(n)
		vec[i] = tempVec[i];//f(1)

	//overall complexity is O(2n)
}
void HW4::MyVector::push_back(T value)
{
	/*f(1) * 7 + f(n) * 2 = f(2n) + f(7)*/

	T* tempVec = nullptr;//f(1)
	tempVec = new T[vsize];//f(1)
	for (int i = 0; i < vsize; i++)//function of vsize f(n)
		tempVec[i] = vec[i];//f(1)

	vsize += 1;//f(1)
	vec = new T[vsize];//f(1)
	vec[vsize - 1] = value;//f(1)
	for (int i = 0; i < vsize - 1; i++)//f(n)
		vec[i] = tempVec[i];//f(1)
	//overall complexity is O(2n)
}
int HW4::MyVector::size() //returns the vector size
{
	return vsize;
}
bool HW4::MyVector::empty()//determine if is empty
{
	if (vsize != 0)//f(1)
	{
		std::cout << "Vector contains " << vsize << " items." << std::endl;
		return false;
	}
	else//f(1)
	{
		std::cout << "Vector is empty" << std::endl;
		return true;
	}
}
int HW4::MyVector::search(T Value)
{
	int i = 0;
	while (vec[i] != Value && i < vsize)//f(n)
		i++;
	if (vec[i] == Value)//f(1)
		std::cout << "That number is in the vector at position: " << i << std::endl;
	else//f(1)
		std::cout << "That number is not in the vector." << std::endl;
	return 1;
	//overall complexity O(n)
}