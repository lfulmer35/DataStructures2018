//Lucas Fulmer

#include "vehicle.h"
using namespace std;

int main()
{
	int index, _year, choice;
	string _make;
	bool done = true;
	Vehicle car1;
	vector<Vehicle> vehicleVector;
	cout << "Welcome!!" << endl;
	while (done)
	{
		cout << "What would you like to do? " << endl;
		cout << "1. Read in vehicles. " << endl;
		cout << "2. Recursive search by year. " << endl;
		cout << "3. Recursive search by make. " << endl;
		cout << "4. Iterative search by year. " << endl;
		cout << "5. Iterative search by make. " << endl;
		cout << "6. Exit. " << endl << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			readInVehicles(vehicleVector);
			cout << "Here are the vehicles that I read in: " << endl;
			for (int i = 0; i < vehicleVector.size(); i++)
				cout << vehicleVector[i] << endl;
			break;
		case 2:
			car1.sortByYear(vehicleVector);
			cout << "What year would you like to search? " << endl;
			cin >> _year;
			index = car1.binSearchRec(vehicleVector, 0, vehicleVector.size() - 1, _year);
			if (index == -1)
			{
				cout << "No vehicles found. " << endl;
				break;
			}
			else
				cout << "Here's what I found: " << endl << vehicleVector[index];
			break;
		case 3:
			car1.sortByMake(vehicleVector);
			cout << "What make would you like to search? " << endl;
			cin >> _make;
			index = car1.binSearchRec(vehicleVector, 0, vehicleVector.size()-1, _make);
			if (index == -1)
			{
				cout << "No vehicles of that make were found. " << endl;
				break;
			}
			else
				cout << "Here's what I found: " << endl << vehicleVector[index];
			break;
		case 4:
			car1.sortByYear(vehicleVector);
			cout << "What year would you like to search? " << endl;
			cin >> _year;
			index = car1.binSearchIter(vehicleVector, vehicleVector.size() - 1, _year);
			if (index == -1)
			{
				cout << "No vehicles found. " << endl;
				break;
			}
			else
				cout << "Here's what I found: " << endl << vehicleVector[index];
			break;
		case 5:
			car1.sortByMake(vehicleVector);
			cout << "What make would you like to search? " << endl;
			cin >> _make;
			index = car1.binSearchIter(vehicleVector, vehicleVector.size() - 1, _make);
			if (index == -1)
			{
				cout << "No vehicles of that make were found. " << endl;
				break;
			}
			else
				cout << "Here's what I found: " << endl << vehicleVector[index];
			break;
		case 6:
			done = false;
			cout << "Goodbye and Godspeed" << endl;
			break;
		default:
			cout << "Please enter a number from the menu: " << endl;
			break;
		}//switch
	}//while

	
return 0;
}
