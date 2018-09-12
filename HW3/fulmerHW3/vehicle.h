//Lucas Fulmer

#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle
{
private:
	int year;
	string make;
	string model;
public:
	Vehicle();
	Vehicle(int _year, string _make, string _model);
	int getYear() { return year; }
	string getMake() { return make; }
	string getModel() { return model; }
	void setYear(int _year) { year = _year; }
	void setMake(string _make) { make = _make; }
	void setModel(string _model) { model = _model; }
	int binSearchRec(const vector<Vehicle> vec, int first, int last, int targetYear);
	int binSearchRec(const vector<Vehicle> vec, int first, int last, string _make);
	int binSearchIter(const vector<Vehicle> vec, int numElem, string _make);
	int binSearchIter(const vector<Vehicle> vec, int numElem, int targetYear);
	void sortByMake(vector<Vehicle>& vec);
	void sortByModel(vector<Vehicle>& vec);
	void sortByYear(vector<Vehicle>& vec);
	friend void readInVehicles(vector<Vehicle> &vehicleVector);
	friend ostream& operator <<(ostream& out, Vehicle _vehicle);
};
#endif // !VEHICLE_H