//Lucas Fulmer

#include "vehicle.h"
#include <fstream>

Vehicle::Vehicle()
{
	year = 0;
	make = " ";
	model = " ";
	cout << "Default constructor called." << endl;
}
Vehicle::Vehicle(int _year, string _make, string _model)
{
	year = _year;
	make = _make;
	model = _model;
}
int Vehicle::binSearchRec(const vector<Vehicle> vec, int first, int last, int targetYear)
{
	int index;
	if (first > last)
		index = -1; //target not in vector
	else
	{
		int mid = first + (last - first) / 2;
		if (targetYear == vec[mid].year)
			index = mid;
		else if (targetYear < vec[mid].year)
			index = binSearchRec(vec, first, mid - 1, targetYear);
		else
			index = binSearchRec(vec, mid + 1, last, targetYear);
	}
	return index;
}
int Vehicle::binSearchRec(vector<Vehicle> vec, int first, int last, string _make)
{
	int index;
	_make[0] = toupper(_make[0]);
	if (first > last)
		index = -1; //target not in vector
	else
	{
		int mid = first + (last - first) / 2;
		if (_make == vec[mid].make)
			index = mid;
		else if (_make < vec[mid].make)
			index = binSearchRec(vec, first, mid - 1, _make);
		else
			index = binSearchRec(vec, mid + 1, last, _make);
	}//else
	return index;
}

int Vehicle::binSearchIter(const vector<Vehicle> vec, int numElem, string _make)
{
	int first = 0,
		last = numElem - 1,
		middle,
		position = -1;
	bool found = false;
	_make[0] = toupper(_make[0]);

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (vec[middle].make == _make)
		{
			found = true;
			position = middle;
		}
		else if (vec[middle].make > _make)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return position;
}
int Vehicle::binSearchIter(const vector<Vehicle> vec, int numElem, int targetYear)
{
	int first = 0,
		last = numElem - 1,
		middle,
		position = -1;
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (vec[middle].year == targetYear)
		{
			found = true;
			position = middle;
		}
		else if (vec[middle].year > targetYear)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return position;
}
void Vehicle::sortByMake(vector<Vehicle>& vec)
{
	int size;
	Vehicle tempVec;
	size = vec.size();
	for (int i = 0; i < (size - 1); i++)
	{
		for (int x = 0; x < size-i-1; x++)
		{
			if (vec[x].make > vec[x+1].make)
			{
				tempVec = vec[x];
				vec[x] = vec[x + 1];
				vec[x + 1] = tempVec;
			}//if
		}
	}
}
void Vehicle::sortByModel(vector<Vehicle>& vec)
{
	int size;
	Vehicle tempVec;
	size = vec.size();
	for (int i = 0; i < (size - 1); i++)
	{
		for (int x = 0; x < size - i - 1; x++)
		{
			if (vec[x].model > vec[x + 1].model)
			{
				tempVec = vec[x];
				vec[x] = vec[x + 1];
				vec[x + 1] = tempVec;
			}//if
		}//for
	}//for
}//function
void Vehicle::sortByYear(vector<Vehicle>& vec)
{
	int size;
	Vehicle tempVec;
	size = vec.size();
	for (int i = 0; i < (size - 1); i++)
	{
		for (int x = 0; x < size - i - 1; x++)
		{
			if (vec[x].year > vec[x + 1].year)
			{
				tempVec = vec[x];
				vec[x] = vec[x + 1];
				vec[x + 1] = tempVec;
			}//if
		}//for
	}//for
}//function
void readInVehicles(vector<Vehicle> &vehicleVector)
{
	ifstream inputFile;
	Vehicle tempVehicle;
	int tempYear;
	string tempMake, tempModel;

	//opening the file
	inputFile.open("vehiclein.txt");

	if (!inputFile.good())//error if file fails to open
		cout << "Error opening the file." << endl;
	else
	{
		while (inputFile.good())//while file has text available to read
		{
			inputFile >> tempYear;
			inputFile.ignore();
			getline(inputFile, tempMake);
			getline(inputFile, tempModel);
			tempVehicle.setYear(tempYear);
			tempVehicle.setMake(tempMake);
			tempVehicle.setModel(tempModel);
			vehicleVector.push_back(tempVehicle);
		}//while
		inputFile.close();
	}//else
}//readIn
ostream& operator <<(ostream& out, Vehicle _vehicle)
{
	out << _vehicle.getYear() << endl << _vehicle.getMake() << endl << _vehicle.getModel() << endl;
	return out;
}
