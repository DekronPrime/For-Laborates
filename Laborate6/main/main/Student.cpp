#include <iostream>
#include <Windows.h>
#include <string>
#include "Student.h"
using namespace std;

Student::Student() {
    cout << "������ ��� ��� ��������: " << endl;
    cout << "�������: ";
    cin >> this->lname;
    cout << "��'�: ";
    cin >> this->name;
    cout << "�� �������: ";
    cin >> this->fname;
    cout << "����� ������� ������ (8 ����): ";
    cin >> this->number;
    cout << endl;
    cout << "0 - �������\n1 - ���������\n������ �����: ";
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
    os << "\t��� ��� ��������" << endl;
    os << "============================" << endl;
    os << "�������: " << obj.lname << endl;
    os << "��'�: " << obj.name << endl;
    os << "�� �������: " << obj.fname << endl;
    os << "����� ������� ������: " << obj.number << endl;
    string status;
    if (obj.freeStudy)
        status = "���������";
    else
        status = "�������";
    os << "������: " << status << endl << endl;
    return os;
}