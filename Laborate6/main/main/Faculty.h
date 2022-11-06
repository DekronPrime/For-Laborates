#pragma once

#include <iostream>
#include <string>
#include "Group.h"
using namespace std;

class Faculty {
private:
	string fName;
	int countofGroups;
	Group* groups;
public:
	//Faculty();
	Faculty(string fName, int count);
	Faculty(string fName, int count, Group* groups);
	~Faculty();
	void changeName(string newName);
	void showGroups() const;
	friend ostream& operator <<(ostream& os, const Faculty& obj);
};