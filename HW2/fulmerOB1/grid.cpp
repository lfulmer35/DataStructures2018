//Lucas Fulmer

#include "grid.h"
#include <iostream>

Grid::Grid()
{
	rows = 0;
	cols = 0;
	randVec1;//first grid
	randVec2;//second grid
	compareVec;//third grid for comparison
}

Grid::Grid(int _rows, int _cols)
{
	rows = _rows;
	cols = _cols;
}
void Grid::setVec(int _rows, int _cols)
{	//this function creates three grids with default values
	vector< vector<int> > tempVec(_rows, vector<int>(_cols));
	randVec1 = tempVec;
	randVec2 = tempVec;
	compareVec = tempVec;
}
void Grid::displayVec(Grid _grid)
{	//displays the grids
	cout << "Grid 1: " << endl;
	for (int i = 0; i < _grid.cols; i++)
	{
		for (int x = 0; x < _grid.rows; x++)
			cout << _grid.randVec1[x][i] << " ";
		cout << endl;
	}
	cout << endl;
	cout << "Grid 2: " << endl;
	for (int a = 0; a < _grid.cols; a++)
	{
		for (int b = 0; b < _grid.rows; b++)
			cout << _grid.randVec2[b][a] << " ";
		cout << endl;
	}
	cout << endl;
}
void Grid::setRand(int _rows, int _cols, Grid& _grid)
{
	int nums;// stores 1/3 of each grid
	srand(time(NULL));
	vector< vector<int> > tempVec(_rows, vector<int>(_cols));
	vector< vector<int> > tempVec2(_rows, vector<int>(_cols));
	nums = (_rows * _cols) / 3;
	for (int i = 0; i < nums; i++)
	{
		int randRow = rand() % _rows;
		int randCol = rand() % _cols;
		if (tempVec[randRow][randCol] == 0)//make sure that the same positions aren't used twice
			tempVec[randRow][randCol] = 1;
		else
			i -= 1; //if a 1 is already in the random position, it runs through the loop again
	}
	randVec1 = tempVec;
	//running the loop again for the second grid
	for (int i = 0; i < nums; i++)
	{
		int randRow = rand() % _rows;
		int randCol = rand() % _cols;
		if (tempVec2[randRow][randCol] == 0)
			tempVec2[randRow][randCol] = 1;
		else
			i -= 1;
	}
	randVec2 = tempVec2;
}
void Grid::compareGrid(int _rows, int _cols, Grid& _grid)
{
	for (int i = 0; i < _cols; i++)
		for (int x = 0; x < _rows; x++)
		{
			if (_grid.randVec1[x][i] == _grid.randVec2[x][i])
				_grid.compareVec[x][i] = _grid.randVec1[x][i];
			else
				_grid.compareVec[i][x] = 0;
		}
	cout << "I have compared the two grids." << endl;
	cout << "Here is the comparison: " << endl;
	for (int i = 0; i < _grid.cols; i++)
	{
		for (int x = 0; x < _grid.rows; x++)
			cout << _grid.compareVec[x][i] << " ";
		cout << endl;
	}
}