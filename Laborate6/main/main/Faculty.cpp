#include <iostream>
#include <Windows.h>
#include <string>
#include "Faculty.h"
using namespace std;

//Faculty::Faculty() {
//    this->fName = "";
//    this->countofGroups = 0;
//    this->groups = nullptr;
//}

Faculty::Faculty(string fName, int count) {
    this->fName = fName;
    this->countofGroups = count;
    this->groups = new Group[count];
}

Faculty::Faculty(string fName, int count, Group* groups) {
    this->fName = fName;
    this->countofGroups = count;
    this->groups = groups;
}

Faculty::~Faculty() {
    if (groups) {
        delete[]groups;
        //cout << "Destructor" << endl;
    }      
}

void Faculty::changeName(string newName) {
    this->fName = newName;
}

void Faculty::showGroups() const {
    for (int i = 0;i < this->countofGroups;i++) {
        cout << this->groups[i];
    }
}

ostream& operator<<(ostream& os, const Faculty& obj) {
    os << "\tДані про факультет" << endl;
    os << "============================" << endl;
    os << "Назва факультету: " << obj.fName << endl;
    os << "Кількість груп: " << obj.countofGroups << endl;
    return os;
}