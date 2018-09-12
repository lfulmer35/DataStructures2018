#ifndef GRID_H
#define GRID_H
#include <vector>
#include <ctime>
#include <iostream>
#include "watervehicle.h"

using namespace std;
class WaterVehicle;
class Grid
{
private:
	vector< vector<char> > playerVec; //the grid where the user's ships are visible
	vector< vector<char> > torpedoVec; //empty grid showing hits and misses
	int cols;
	int rows;
public:
	Grid(); //default constructor
	Grid(int _rows, int _cols);//constructor
	void setCols(int _cols) { cols = _cols; }
	int getCols() { return cols; }
	void setRows(int _rows) { rows = _rows; }
	int getRows() { return rows; }
	void setVec(Grid _userGrid);//creates vectors filled with zeros
	void displayGrid(Grid _grid);
	void placeShip(Grid& _userGrid, WaterVehicle& _ship);
	friend class ComputerPlayer;
	friend class HumanPlayer;
	friend class WaterVehicle;
	friend class Player;
};
#endif // !GRID_H