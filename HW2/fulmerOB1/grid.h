//Lucas Fulmer

#ifndef GRID_H
#define GRID_H
#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

class Grid
{
private:
	vector< vector<int> >randVec1;
	vector< vector<int> >randVec2;
	vector< vector<int> >compareVec;
	int cols;
	int rows;
public:
	Grid(); //default constructor
	Grid(int _rows, int _cols);//constructor
	void setCols(int _cols) { cols = _cols; }
	int getCols() { return cols; }
	void setRows(int _rows) { rows = _rows; }
	int getRows() { return rows; }
	void setVec(int _rows, int _cols);//creates vectors filled with zeros
	void displayVec(Grid _grid);
	void setRand(int _rows, int _cols, Grid& _grid);//fills 1/3 of vectors with ones
	void compareGrid(int _rows, int _cols, Grid& _grid);
};
#endif // !GRID_H;
