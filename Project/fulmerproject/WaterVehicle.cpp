#include "watervehicle.h"

WaterVehicle::WaterVehicle()
{
	//default constructor
	shipType = " ";
	shipLength = 1;
	startingX = 0;
	startingY = 0;
	shipSymbol = 'O';
	orientation = 'V';
	isSunk = false;
}
void WaterVehicle::buildShips(WaterVehicle& _carrier, WaterVehicle& _battleship, WaterVehicle& _cruiser, WaterVehicle& _submarine, WaterVehicle& _destroyer)
{
	//This function sets up each individual ship for use in the game.
	string carrier = "Carrier   ", battleship = "Battlship", cruiser = "Cruiser   ", submarine = "Submarine", destroyer = "Destroyer";
	_carrier.setShipLength(5);
	_carrier.setShipType(carrier);
	_carrier.shipSymbol = 'C';
	_battleship.setShipLength(4);
	_battleship.setShipType(battleship);
	_battleship.shipSymbol = 'B';
	_cruiser.setShipLength(3);
	_cruiser.setShipType(cruiser);
	_cruiser.shipSymbol = 'c';
	_submarine.setShipLength(3);
	_submarine.setShipType(submarine);
	_submarine.shipSymbol = 'S';
	_destroyer.setShipLength(2);
	_destroyer.setShipType(destroyer);
	_destroyer.shipSymbol = 'D';
}
void WaterVehicle::setStartLocation(Grid& _grid, WaterVehicle& _ship)
{
	//This function is a major driving function of the program
	//It takes the user's input to place each ship and calls other functions
	int _startingX, _startingY;
	char tempX;
	int xchar[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	bool check = false;

	while (!check)
	{
		_grid.displayGrid(_grid);
		_ship.displayShips(_ship);
		cout << endl << "Starting 'x' coordinate: (Enter 'A' through 'J')" << endl;
		cin >> tempX;
		_startingX = tempX;
		_startingX = toupper(_startingX);
		if (_startingX >= 'A' && _startingX <= 'J')//Checking for proper input
		{
			startingX = _startingX;
			check = true;
		}
		else
			cout << "Please enter a letter 'A' through 'J': " << endl;
	}
	while (check)
	{
		cout << "Starting 'y' coordinate: (Enter 1 - 10)" << endl;
		cin >> _startingY;
		if (_startingY >= 1 && _startingY <= 10)//Checking for proper input
			check = false;
		else
			cout << "You are limited to integers from 1 to 10." << endl;
	}
	//startingX = _startingX;
	startingY = _startingY;
	_ship.checkOrientation(_grid, _ship);
}
void WaterVehicle::checkOrientation(Grid& _grid, WaterVehicle& _ship)
{
	char _orientation;
	bool check = false;
	int yIndex, xIndex, stopY, stopX;
	yIndex = _ship.startingY - 1;
	xIndex = (_ship.startingX - 5)% 10;
	stopY = yIndex + _ship.shipLength;
	stopX = xIndex + _ship.shipLength;

	while (!check)
	{
		cout << "Would you like to orient the ship vertically or horizontally? (Enter 'V' or 'H') " << endl;
		cin >> _orientation;
		cout << endl << endl << endl;
		_orientation = toupper(_orientation);
		if (_orientation == 'V' || _orientation == 'H')//checking for proper input
		{
			orientation = _orientation;
			check = true;
		}
	}

//Checking to make sure that the ship's entire location is valid for horizontal placement
	if (_ship.orientation == 'H')
	{
		if ((xIndex + _ship.shipLength) > 10)
		{
			cout << "This ship will exceed the board's bounderies. Try again." << endl;
			_ship.setStartLocation(_grid, _ship);
		}
		for (int x = xIndex; x < stopX; x++)
			if (_grid.playerVec[yIndex][x] != 'O')
			{
				cout << "This ship will run into another ship. Try again.";
				_ship.setStartLocation(_grid, _ship);
			}
	}
//Checking to make sure that vertical placement is valid
	else if (_ship.orientation == 'V')
	{
		if (((_ship.startingY - 1) + _ship.shipLength) > 10)
		{
			cout << "This ship will exceed the board's bounderies. Try again." << endl;
			_ship.setStartLocation(_grid, _ship);
		}
		for (int y = yIndex; y < stopY; y++)
			if (_grid.playerVec[y][xIndex] != 'O')
			{
				cout << "This ship will run into another ship. Try again.";
				_ship.setStartLocation(_grid, _ship);
			}
	}
	_grid.placeShip(_grid, _ship);
}
void WaterVehicle::setSunk(bool _sunk)
{
	isSunk = true;
}
void WaterVehicle::checkSunk(const Grid& _grid, WaterVehicle& _carrier, WaterVehicle& _battleship, WaterVehicle& _cruiser, WaterVehicle& _submarine, WaterVehicle& _destroyer)
{
	//this function checks to see if any ships were completely destroyed by torpedoes
	_carrier.isSunk = true;
	_battleship.isSunk = true;
	_cruiser.isSunk = true;
	_submarine.isSunk = true;
	_destroyer.isSunk = true;

	for (int i = 0; i < _grid.cols; i++)
	{
		for (int x = 0; x < _grid.rows; x++)
		{
			if (_grid.playerVec[i][x] == 'C')
				_carrier.isSunk = false;
			else if (_grid.playerVec[i][x] == 'B')
				_battleship.isSunk = false;
			else if (_grid.playerVec[i][x] == 'c')
				_cruiser.isSunk = false;
			else if (_grid.playerVec[i][x] == 'S')
				_submarine.isSunk = false;
			else if (_grid.playerVec[i][x] == 'D')
				_destroyer.isSunk = false;
		}
	}
	if (_carrier.isSunk == true)
		cout << "Carrier has been sunk." << endl;
	else if (_battleship.isSunk == true)
		cout << "Battleship has been sunk." << endl;
	else if (_cruiser.isSunk == true)
		cout << "Cruiser has been sunk." << endl;
	else if (_submarine.isSunk == true)
		cout << "Submarine has been sunk." << endl;
	else if (_destroyer.isSunk == true)
		cout << "Destroyer has been sunk." << endl;
	else
		cout << "No ships were sunk." << endl;
}
void WaterVehicle::displayShips(WaterVehicle& _ship)
{
	//This function displays a WaterVehicle object and is called during placement of ships
	cout << "Ship Type	Ship Length" << endl;
	cout << _ship.shipType << "	" << _ship.shipLength << endl;
}
void WaterVehicle::checkValid()
{
	char tempX, tempOrientation;
	int tempY;
	int xchar[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	bool check = false;
	while (!check)
	{
		if (startingX >= 'A' && startingX <= 'J')//Checking for proper input
			check = true;
		else
		{
			cout << "The " << shipType << " does not have valid X coordinate." << endl;
			cout << "Please enter a valid X coordinate: ";
			cin >> tempX;
			startingX = toupper(tempX);
		}
	}
	while (check)
	{
		if (startingY >= 1 && startingY <= 10)//Checking for proper input
			check = false;
		else
		{
			cout << "The " << shipType << " does not have a valid Y coordinate." << endl;
			cout << "Please enter a valid Y coordinate: ";
			cin >> tempY;
			startingY = tempY;
		}
	}
	while (!check)
	{
		if (orientation == 'V' || orientation == 'H')
			check = true;
		else
		{
			cout << "The orientation for " << shipType << " is invalid." << endl;
			cout << "Please enter valid orientation: ";
			cin >> tempOrientation;
			orientation = toupper(tempOrientation);
		}
	}
}
ostream& operator <<(ostream& out, WaterVehicle _ship)
{
	string sunk;
	if (_ship.isSunk == true)
		sunk = "True";
	else
		sunk = "False";
	//overloading the operator in order to use cout statements
	out << "Ship		Length	xy	V or H	Sunk" << endl 
		<< _ship.shipType << "	" << _ship.shipLength << "	" << _ship.startingX << _ship.startingY << "	" << _ship.orientation << "	  " << sunk << endl;
	return out;
}