#include "WaterVehicle.h"

using namespace std;


int main()
{
	cout << "*****************BATTLESHIP********************";
	cout << endl << "Welcome to the game" << endl << endl;
	Grid userGrid, compGrid;
	WaterVehicle carrier, battleship, cruiser, submarine, destroyer;
	int startY, startX, choice;
	bool done = false, option = false;
	userGrid.setVec(userGrid);
	srand(time(NULL));

	while (!done)
	{
		cout << "1. Play Game" << endl;
		cout << "2. Edit Ship Length" << endl;
		cout << "3. Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Let's place your ships" << endl;
			carrier.buildShips(carrier, battleship, cruiser, submarine, destroyer);
			carrier.setStartLocation(userGrid, carrier);
			cout << endl;
			battleship.setStartLocation(userGrid, battleship);
			cout << endl;
			cruiser.setStartLocation(userGrid, cruiser);
			cout << endl;
			submarine.setStartLocation(userGrid, submarine);
			cout << endl;
			destroyer.setStartLocation(userGrid, destroyer);
			cout << endl;
			

			cout << "LAUNCHING TORPEDOES!!!!!" << endl;
			carrier.randomTorpedo(userGrid);
			carrier.checkSunk(userGrid, carrier, battleship, cruiser, submarine, destroyer);
			cout << carrier << battleship << cruiser << submarine << destroyer;
			break;
		case 2:
			while (!option)
			{
				int shipChoice, newLength;
				cout << "Which ship would you like to edit? " << endl;
				cout << "1. Carrier" << endl << "2. Battleship" << endl << "3. Cruiser" << endl
					<< "4. Submarine" << endl << "5. Destroyer" << endl << "6. Return to menu" << endl;
				cin >> shipChoice;
				switch (shipChoice)
				{
				case 1:
					cout << endl << "The default length is 5 for this ship. What would you like to change it to? " << endl;
					cin >> newLength;
					carrier.setShipLength(newLength);
					break;
				case 2:
					cout << endl << "The default length is 4 for this ship. What would you like to change it to? " << endl;
					cin >> newLength;
					battleship.setShipLength(newLength);
					break;
				case 3:
					cout << endl << "The default length is 3 for this ship. What would you like to change it to? " << endl;
					cin >> newLength;
					cruiser.setShipLength(newLength);
					break;
				case 4:
					cout << endl << "The default length is 3 for this ship. What would you like to change it to? " << endl;
					cin >> newLength;
					submarine.setShipLength(newLength);
					break;
				case 5:
					cout << endl << "The default length is 2 for this ship. What would you like to change it to? " << endl;
					cin >> newLength;
					destroyer.setShipLength(newLength);
					break;
				case 6:
					option = true;
					break;
				default:
					cout << "Please enter a number from the menu: " << endl;
					break;
				}//case
			}//while
			break;
		case 3:
			cout << "REMEMBER THE MAINE!!!!" << endl;
			done = true;
			break;
		default:
			cout << "Please enter a number from the menu: " << endl;
			break;
		}//case
	}//while
	return 0;
}//main