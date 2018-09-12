#ifndef WATERVEHICLE_H
#define WATERVEHICLE_H
#include <string>
#include <fstream>
#include "player.h"
#include "grid.h"
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
	void checkOrientation(Grid& _grid, WaterVehicle& _ship);
	void setSunk(bool _sunk);
	bool getSunk() { return isSunk; }
	void checkSunk(const Grid& _grid, WaterVehicle& _carrier, WaterVehicle& _battleship, WaterVehicle& _cruiser, WaterVehicle& _submarine, WaterVehicle& _destroyer);
	void setStartingX(int _startingX) { startingX = _startingX; }
	void setStartingY(int _startingY) { startingY = _startingY; }
	void setOrientation(char _orientation) { orientation = _orientation; }
	char getOrientation() { return orientation; }
	void displayShips(WaterVehicle& _ship);
	void checkValid();

	friend ostream& operator <<(ostream& out, WaterVehicle _ship);
	friend class Grid;
	friend class Player;
};
#endif // !WATERVEHICLE_H
