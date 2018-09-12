//Lucas Fulmer
#include "MyVector.h"

using namespace std;

int main()
{
	HW4::MyVector vector;
	int _size, _index, num1, num2, num3, searchNum;
	vector.empty();
	cout << "Enter three numbers for pushback: " << endl;
	cin >> num1;
	cin >> num2;
	cin >> num3;
	vector.push_back(num1);
	vector.push_back(num2);
	vector.push_back(num3);
	cout << "Here are the numbers in the vector: " << endl;
	for (int i = 0; i < 3; i++)
		cout << vector[i] << endl;
	cout << "Vector size is: " << vector.size() << endl;
	vector.pop_back();
	cout << "After pop_back, here's what's in the vector: " << endl;
	for (int i = 0; i < vector.size(); i++)
		cout << vector[i] << endl;
	cout << "Vector size is: " << vector.size() << endl;
	cout << "Enter a number to search for: " << endl;
	cin >> searchNum;
	vector.search(searchNum);
	return 0;
}
