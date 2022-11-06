#include <iostream>
#include <Windows.h>
#include <string>
#include "Student.h"
#include "Group.h"
using namespace std;

Group::Group() {
    this->grName = "";
    this->specialty = "";
    this->countofStudents = 0;
    this->students = nullptr;
}

Group::Group(string name, string specialty, int count, Student* stud) {
    this->grName = name;
    this->specialty = specialty;
    this->countofStudents = count;
    this->students = stud;
}

Group::Group(const Group& obj) {
    this->grName = obj.grName;
    this->specialty = obj.specialty;
    this->countofStudents = obj.countofStudents;
    if (obj.students) {
        this->students = new Student();
    }
}

void Group::showStudent(int index) {
    cout << this->students[index];
}

Group::~Group() {

}

ostream& operator<<(ostream& os, const Group& obj) {
    os << "\t��� ��� �����" << endl;
    os << "============================" << endl;
    os << "�����: " << obj.grName << endl;
    os << "������������: " << obj.specialty << endl;
    os << "ʳ������ ��������: " << obj.countofStudents << endl;
    return os;
}