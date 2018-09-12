#ifndef STUDENT_H
#define STUDENT_H	
#include <iostream>
#include <cstring>
using namespace std;

struct Student
{
	char sName[20];
	int id;
};

ostream& operator<<(ostream& out, Student student)
{
	out << endl << "Name: ";
	for (int i = 0; i < strlen(student.sName); i++)
		out << student.sName[i];
	out << endl << "ID: " << student.id << endl;
	return out;
}
#endif // !STUDENT_H
#pragma once
