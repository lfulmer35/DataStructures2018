#include "player.h"
#include <sstream>
#include <cstring>
#include <cstdlib>

Player::Player()
{
	playerName = " ";
	didWin = false;
}
void Player::buildFleet()
{

}
void Player::playGame(WaterVehicle& _ship1, WaterVehicle& _ship2, WaterVehicle& _ship3, WaterVehicle& _ship4, WaterVehicle& _ship5)
{ //driver function
	HumanPlayer human;
	WaterVehicle eship1, eship2, eship3, eship4, eship5;
	ComputerPlayer computer;
	Grid userGrid, computerGrid;
	userGrid.setVec(userGrid);
	computerGrid.setVec(computerGrid);
	computer.randomPlaceShips(computerGrid, eship1, eship2, eship3, eship4, eship5);
	
	_ship1.checkValid();					//checking for valid ship placement from the read-in file
	userGrid.placeShip(userGrid, _ship1);
	_ship2.checkValid();
	userGrid.placeShip(userGrid, _ship2);
	_ship3.checkValid();
	userGrid.placeShip(userGrid, _ship3);
	_ship4.checkValid();
	userGrid.placeShip(userGrid, _ship4);
	_ship5.checkValid();
	userGrid.placeShip(userGrid, _ship5);
	
	bool gameOn = true;
	int turn = 1;
	while (gameOn)
	{
		if (turn == 1)
		{
			//human player's turn...
			userGrid.displayGrid(userGrid);
			cout << "Press Q at any time to quit the game. " << endl;
			human.launchTorpedoes(userGrid, computerGrid);
			eship1.checkSunk(computerGrid, eship1, eship2, eship3, eship4, eship5);
			if (eship1.getSunk() == true && eship2.getSunk() == true && eship3.getSunk() == true && eship4.getSunk() == true && eship5.getSunk() == true)
			{
				turn = 5;
				cout << endl << "All enemy ships sunk. YOU WIN!!!" << endl;
			}
			turn += 1;
			cout << endl;
		}
		else if (turn == 2)
		{
			//computer player's turn...
			computer.launchTorpedoes(userGrid);
			_ship1.checkSunk(userGrid, _ship1, _ship2, _ship3, _ship4, _ship5);
			if (_ship1.getSunk() == true && _ship2.getSunk() == true && _ship3.getSunk() == true && _ship4.getSunk() == true && _ship5.getSunk() == true)
			{
				turn = 5;
				cout << endl << "All of your ships have been sunk. YOU LOSE!!! " << endl;
			}
			turn -= 1;
			cout << endl;
		}
		else
			gameOn = false;
	}

}
void Player::displayGrids()//virtual
{

}
void Player::launchTorpedoes()//virtual
{
	
}
void Player::displayShips()
{

}
void Player::readInShipLocations(WaterVehicle _shipArray[])
{
	ifstream infile;
	WaterVehicle tempShip;
	string ship, tempType, line1, subString, swapX, swapY;
	char tempX, tempOrientation;
	int tempY, i = 0;

	infile.open("ship_placement.csv");
	if (!infile.good())
		cout << "Error reading in the file." << endl;
	else
	{
		getline(infile, line1);//reading in the first line
		while (infile.good())
		{
			getline(infile, ship);
			istringstream ss(ship);//using stringstream to separate each element
			getline(ss, subString, ',');
			tempShip.shipType = subString;
			getline(ss, subString, ',');
			tempX = subString[0];
			tempShip.startingX = toupper(tempX);
			swapY = subString[1];
			tempY = stoi(swapY);
			tempShip.startingY = tempY;
			getline(ss, subString, ',');
			tempOrientation = subString[0];
			tempShip.orientation = toupper(tempOrientation);
			_shipArray[i] = tempShip;//
			i++;
		}
		infile.close();
		i = 0;
		while (i < 5)
		{//setting each ship to the correct length
			if (_shipArray[i].shipType == "Carrier")
			{
				_shipArray[i].shipLength = 5;
				_shipArray[i].shipSymbol = 'C';
			}
			else if (_shipArray[i].shipType == "Battleship")
			{
				_shipArray[i].shipLength = 4;
				_shipArray[i].shipSymbol = 'B';
			}
			else if (_shipArray[i].shipType == "Cruiser")
			{
				_shipArray[i].shipLength = 3;
				_shipArray[i].shipSymbol = 'c';
			}
			else if (_shipArray[i].shipType == "Submarine")
			{
				_shipArray[i].shipLength = 3;
				_shipArray[i].shipSymbol = 'S';
			}
			else if (_shipArray[i].shipType == "Destroyer")
			{
				_shipArray[i].shipLength = 2;
				_shipArray[i].shipSymbol = 'D';
			}
			else
			{
				cout << "This ship - " << _shipArray[i].shipType << " - does not exist." << endl;
				cout << "Enter the correct ship name ---> ";
				cin >> _shipArray[i].shipType;
				i--;
			}
			i++;
		}
	}
}
//HumanPlayer Implementation
void HumanPlayer::displayGrids(Grid& playerGrid, Grid& enemyGrid)
{

}
void HumanPlayer::launchTorpedoes(Grid& _grid, Grid& _enemyGrid)
{//pass the computer's grid into this function
	char tempX;
	string tempY;
	int yTgt, xTgt;
	bool check = false, valid = false;
	while (!valid || !check)
	{
		cout << "Pick next torpedo target (X then Y): " << endl;
		cin >> tempX;
		xTgt = toupper(tempX);
		if (xTgt == 'Q')
		{//giving the user the option to quit at any time
			cout << "Remember the MAINE!! ";
			exit(1);
		}
		cin >> tempY;
		yTgt = stoi(tempY);
		if (xTgt >= 'A' && xTgt <= 'J')
		{
			xTgt = (xTgt - 5) % 10;
			valid = true;
		}
		else
		{
			cout << "Invalid X-Coordinate. Please enter a character (A - J): " << endl;
			valid = false;
		}
		if (yTgt >= 1 && yTgt <= 10)
		{
			yTgt -= 1;
			check = true;
		}
		else
		{
			cout << "Invalid y-coordinate. Enter a number (1-10): " << endl;
			check = false;
		}
	}
	valid = false;
	
	while (!valid)
	{//testing to see if the torpedo hit a ship, or open ocean
		if (_enemyGrid.playerVec[yTgt][xTgt] == 'O')
		{
			_grid.torpedoVec[yTgt][xTgt] = 'M';
			cout << "Miss." << endl;
			valid = true;
		}
		else if (_enemyGrid.playerVec[yTgt][xTgt] == 'S' || _enemyGrid.playerVec[yTgt][xTgt] == 'C' ||
			_enemyGrid.playerVec[yTgt][xTgt] == 'B' || _enemyGrid.playerVec[yTgt][xTgt] == 'c' ||
			_enemyGrid.playerVec[yTgt][xTgt] == 'D')
		{
			_grid.torpedoVec[yTgt][xTgt] = 'X';
			_enemyGrid.playerVec[yTgt][xTgt] = 'X';
			cout << "Hit!!!" << endl;
			valid = true;
		}
		else
			valid = false;
	}
}
//ComputerPlayer Implementation
void ComputerPlayer::randomPlaceShips(Grid& _grid, WaterVehicle& eship1, WaterVehicle& eship2, WaterVehicle& eship3, WaterVehicle& eship4, WaterVehicle& eship5)
{
	int tempX, tempY, tempOrient, stopY, stopX;
	char randX;
	bool valid = false, goodOrientation = false;
	eship1.buildShips(eship1, eship2, eship3, eship4, eship5);
	WaterVehicle compArray[] = { eship1, eship2, eship3, eship4, eship5 };//putting the ships in an array for easy looping
	
	while (!valid)
	{
		tempX = rand() % 10;
		randX = 65 + tempX;
		tempY = rand() % 10;
		stopX = tempX + eship1.getShipLength();
		stopY = tempY + eship1.getShipLength();
		eship1.setStartingX(randX);
		eship1.setStartingY(tempY + 1);
		tempOrient = rand() % 2;
		if (tempOrient == 0)
		{
			eship1.setOrientation('V');
			if (stopY < 10)
				valid = true;
		}
		else
		{
			eship1.setOrientation('H');
			if (stopX < 10)
				valid = true;
		}
	}
	_grid.placeShip(_grid, eship1);//placing the fist ship, prior to the loop to allow for easier error checking

	for (int i = 1; i < 5; i++)
	{
		valid = false;
		while (!valid)
		{//checking for valid ship placement in this loop
			tempX = rand() % 10;
			tempY = rand() % 10;
			stopX = tempX + compArray[i].getShipLength();
			stopY = tempY + compArray[i].getShipLength();
			tempOrient = rand() % 2;
			if (tempOrient == 0)//vertical
				compArray[i].setOrientation('V');
			else
				compArray[i].setOrientation('H');

			if (compArray[i].getOrientation() == 'H')
			{
				if (stopX < 10)
				{
					valid = true;
					for (int x = tempX; x < stopX; x++)
						if (_grid.playerVec[tempY][x] != 'O')
							valid = false;
				}
			}
			else
				if (stopY < 10)
				{
					valid = true;
					for (int y = tempY; y < stopY; y++)
						if (_grid.playerVec[y][tempX] != 'O')
							valid = false;
				}//if
			if (valid == true)
			{
				compArray[i].setStartingX(tempX + 65);
				compArray[i].setStartingY(tempY + 1);
			}//if
		}//while		
	}//for
	eship2 = compArray[1];					//now storing the ship data into the ships that were passed into the function by reference
	_grid.placeShip(_grid, eship2);
	eship3 = compArray[2];
	_grid.placeShip(_grid, eship3);
	eship4 = compArray[3];
	_grid.placeShip(_grid, eship4);
	eship5 = compArray[4];
	_grid.placeShip(_grid, eship5);
}
void ComputerPlayer::launchTorpedoes(Grid& _grid)
{//pass the user's grid into this function
	bool valid = false;
	char xchar[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	while (!valid)
	{
		int randRow = rand() % 10;
		int randCol = rand() % 10;
		if (_grid.playerVec[randRow][randCol] == 'O')
		{
			_grid.playerVec[randRow][randCol] = 'X';
			cout << "Computer torpedo at " << xchar[randCol] << randRow+1 << " missed." << endl;
			valid = true;
		}
		else if (_grid.playerVec[randRow][randCol] == 'S' || _grid.playerVec[randRow][randCol] == 'C' ||
			_grid.playerVec[randRow][randCol] == 'B' || _grid.playerVec[randRow][randCol] == 'c' ||
			_grid.playerVec[randRow][randCol] == 'D')
		{
			_grid.playerVec[randRow][randCol] = 'X';
			cout << "Computer torpedo at " << xchar[randCol] << randRow+1 << " hit your ship!" << endl;
			valid = true;
		}
		else
			valid = false;
	}
}