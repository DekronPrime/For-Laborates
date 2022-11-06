#ifndef ABITURIENT_H
#define ABITURIENT_H

#include <string>
using namespace std;

class Abiturient
{
private:
    int id;
    string lname;
    string name;
    string fname;
    string address;
    string phone;
    float SP;

public:
    Abiturient();
    Abiturient(int id, string l, string n, string f, string add, string ph, double sp);
    string toString();
};

#endif // ABITURIENT_H
