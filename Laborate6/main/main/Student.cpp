#include <iostream>
#include <Windows.h>
#include <string>
#include "Student.h"
using namespace std;

Student::Student() {
    cout << "Введіть дані про студента: " << endl;
    cout << "Прізвище: ";
    cin >> this->lname;
    cout << "Ім'я: ";
    cin >> this->name;
    cout << "По батькові: ";
    cin >> this->fname;
    cout << "Номер залікової книжки (8 цифр): ";
    cin >> this->number;
    cout << endl;
    cout << "0 - Платник\n1 - Державник\nВведіть номер: ";
    cin >> this->freeStudy;
}

Student::Student(string l, string n, string f, unsigned int number, bool value) {
    this->lname = l;
    this->name = n;
    this->fname = f;
    this->number = number;
    this->freeStudy = value;
}

Student::Student(const Student& obj) {
    this->lname = obj.lname;
    this->name = obj.name;
    this->fname = obj.fname;
    this->number = obj.number;
    this->freeStudy = obj.freeStudy;
}

void Student::changeData(string l, string n, string f, unsigned int number, bool value) {
    this->lname = l;
    this->name = n;
    this->fname = f;
    this->number = number;
    this->freeStudy = value;
}

ostream& operator<<(ostream& os, const Student& obj)
{
    os << "\tДані про студента" << endl;
    os << "============================" << endl;
    os << "Прізвище: " << obj.lname << endl;
    os << "Ім'я: " << obj.name << endl;
    os << "По батькові: " << obj.fname << endl;
    os << "Номер залікової книжки: " << obj.number << endl;
    string status;
    if (obj.freeStudy)
        status = "Державник";
    else
        status = "Платник";
    os << "Статус: " << status << endl << endl;
    return os;
}