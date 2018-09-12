//Lucas Fulmer
#ifndef WATERVEHICLE_H
#define WATERVEHICLE_H

#include <vector>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;
class Grid;
class WaterVehicle
{
private:
	string shipType;
	int shipLength;
	char startingX;
	int startingY;
	char orientation;
	char shipSymbol;//symbol displayed on game grid
	bool isSunk;

public:
	WaterVehicle();//default constructor
	void setShipType(string _ship) { shipType = _ship; }
	void buildShips(WaterVehicle& _carrier, WaterVehicle& _battleship, WaterVehicle& _cruiser, WaterVehicle& _submarine, WaterVehicle& _destroyer);
	void setShipLength(int _shipLength) { shipLength = _shipLength; }
	int getShipLength() { return shipLength; }
	void setStartLocation(Grid& _grid, WaterVehicle& _ship);
	void setOrientation(Grid& _grid, WaterVehicle& _ship);
	void setSunk(bool _sunk);
	void checkSunk(const Grid& _grid, WaterVehicle& _carrier, WaterVehicle& _battleship, WaterVehicle& _cruiser, WaterVehicle& _submarine, WaterVehicle& _destroyer);
	void userTorpedo();
	void randomTorpedo(Grid& _grid);
	void displayShips(WaterVehicle& _ship);
	
	friend ostream& operator <<(ostream& out, WaterVehicle _ship);
	friend class Grid;
};
class Grid
{
private:
	vector< vector<char> >userVec;
	vector< vector<char> >compVec;
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
	void displayVec(Grid _grid);
	void placeShip(Grid& _userGrid, WaterVehicle& _ship);
	friend class WaterVehicle;
};
#endif // !WATERVEHICLE_H
