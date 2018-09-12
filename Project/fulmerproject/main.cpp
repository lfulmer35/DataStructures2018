#include "grid.h"
#include "player.h"
#include "watervehicle.h"
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	HumanPlayer player1;
	Grid playerGrid, compGrid;
	playerGrid.setVec(playerGrid);
	WaterVehicle ship1, ship2, ship3, ship4, ship5;
	WaterVehicle shipArray[] = { ship1, ship2, ship3, ship4, ship5 };
	bool done = false;
	int choice;

	while (!done)
	{
		cout << "**********BATTLESHIP**********" << endl << endl;
		cout << "Main menu" << endl;
		cout << "1. Play Game " << endl << "2. Exit " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			while (!done)
			{
				cout << "1: Place ships manually" << endl << "2. Read-in file for ship placement " << endl <<
					"3. Exit" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << "Let's place your ships" << endl;
					ship1.buildShips(ship1, ship2, ship3, ship4, ship5);
					ship1.setStartLocation(playerGrid, ship1);
					cout << endl;
					ship2.setStartLocation(playerGrid, ship2);
					cout << endl;
					ship3.setStartLocation(playerGrid, ship3);
					cout << endl;
					ship4.setStartLocation(playerGrid, ship4);
					cout << endl;
					ship5.setStartLocation(playerGrid, ship5);
					cout << endl;
					player1.playGame(ship1, ship2, ship3, ship4, ship5);
				case 2:
					player1.readInShipLocations(shipArray);
					ship1 = shipArray[0];
					ship2 = shipArray[1];
					ship3 = shipArray[2];
					ship4 = shipArray[3];
					ship5 = shipArray[4];
					player1.playGame(ship1, ship2, ship3, ship4, ship5);
					break;
				case 3:
					cout << "REMEMBER THE MAINE!!!" << endl;
					done = true;
					break;
				default:
					cout << "Please enter a number from the menu: " << endl;
					break;
				}//case
			}//while
		}//case
	}//while

	return 0;
}