#pragma once

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	string lname;
	string name;
	string fname;
	unsigned int number;
	bool freeStudy;
public:
	Student();
	Student(string l, string n, string f, unsigned int number, bool value);
	Student(const Student& obj);
	void changeData(string l, string n, string f, unsigned int number, bool value);
	friend ostream& operator<<(ostream& os, const Student& obj);
};