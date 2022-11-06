#include <iostream>
#include <Windows.h>
#include <string>
#include "Student.h"
#include "Group.h"
#include "Faculty.h"
using namespace std;   

#define STUDENTS 3

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Гордійчук Володимир. " << endl;
    cout << "Лабораторна робота №6. " << endl << endl;

    ////////////////////////////////////////////////////

    //Student s("Ейнштейн", "Альберт", "Степанович", 35748926, 0);
    Student st1;
    Student st2("Ньютон", "Ісаак", "Зіновійович", 74235684, 1);
    Student st3 = st2;
    st2.changeData("Коперник", "Микола", "Володимирович", 57846356, 0);

    Student list[STUDENTS] = { st1,st2,st3 };

    for (int i = 0;i < STUDENTS;i++) {
        cout << list[i];
    }

    ////////////////////////////////////////////////////


    Student s1("Галілей", "Галілео", "Анатолійович", 68325697, 0);
    Student s2("Ньютон", "Ісаак", "Зіновійович", 74235684, 1);
    Student s3("Хокінг", "Стівен", "Олександрович", 14693679, 1);

    Student* unity = new Student[STUDENTS]{ s1,s2,s3 };

    Group* gr = new Group("CS", "Computer Science", 3, unity);
    cout << *gr;
    gr->showStudent(1);
    delete gr;

    cout << "------------------------------------------------------" << endl;
    for (int i = 0;i < 3;i++) {
        cout << unity[i]; // досі існують
    }
    cout << "------------------------------------------------------" << endl;

    //////////////////////////////////////////////////////


    Group* group = new Group[3]{
       Group("SD", "Software Developing", 3, unity),
       Group("GD", "Game Developing", 3, unity),
       Group("WD", "Web Design", 3, unity)
    };

    Faculty* faculty = new Faculty("Information technologies", 3, group);
    cout << *faculty;
    cout << "------------------------------------------------------" << endl;
    faculty->showGroups();
    cout << "------------------------------------------------------" << endl;
    delete faculty;
}