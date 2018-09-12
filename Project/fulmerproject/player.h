#ifndef PLAYER_H
#define PLAYER_H
#include "grid.h"
#include "watervehicle.h"
#include <iostream>

using namespace std;
class Grid;
class WaterVehicle;

class Player
{
private:
	string playerName;
	bool didWin;
public:
	Player();//default constructor
	void setName(string _name) { playerName = _name; }
	void setWin() { didWin = true; }
	void buildFleet();
	void playGame(WaterVehicle& _ship1, WaterVehicle& _ship2, WaterVehicle& _ship3, WaterVehicle& _ship4, WaterVehicle& _ship5);//driver function
	virtual void displayGrids();
	virtual void launchTorpedoes();//virtual because computer's shots are random and user's are (probably) not
	void displayShips();
	void readInShipLocations(WaterVehicle _shipArray[]);
	friend class Grid;
	friend class WaterVehicle;
};
class ComputerPlayer : public Player
{
public:
	void randomPlaceShips(Grid& _grid, WaterVehicle& eship1, WaterVehicle& eship2, WaterVehicle& eship3, WaterVehicle& eship4, WaterVehicle& eship5);
	void launchTorpedoes(Grid& _grid);
};
class HumanPlayer : public Player
{
public:
	void displayGrids(Grid& playerGrid, Grid& enemyGrid);
	void launchTorpedoes(Grid& _grid, Grid& _enemyGrid);
};
#endif // !PLAYER_H