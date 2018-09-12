//Lucas Fulmer

#include "grid.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	Grid testGrid;
	int _rows = 0;
	int _cols = 0;
	vector<int>testVec;

	cout << "*****************************************************************************" << endl;
	cout << "This program compares two grids and displays the matching intergers" << endl;
	cout << "Enter the number of rows: " << endl;
	cin >> _rows;
	cout << "Enter the number of columns: " << endl;
	cin >> _cols;

	testGrid.setRows(_rows);
	testGrid.setCols(_cols);
	testGrid.setVec(_rows, _cols);
	testGrid.setRand(_rows, _cols, testGrid);
	testGrid.displayVec(testGrid);
	testGrid.compareGrid(_rows, _cols, testGrid);
	cout << "Have a nice day!!" << endl;
}
