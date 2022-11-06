#pragma once

#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

class Group {
private:
	string grName;
	string specialty;
	int countofStudents;
	Student* students;
public:
	Group();
	Group(string grName, string specialty, int count, Student* stud);
	Group(const Group& obj);
	~Group();
	void showStudent(int index);
	friend ostream& operator <<(ostream& os, const Group& obj);
};