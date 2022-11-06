#include "abiturient.h"

Abiturient::Abiturient() :
    id(0), lname(""), name(""), fname(""), address(""), phone(""), SP(0.0)
{}

Abiturient::Abiturient(int id, string l, string n, string f, string add, string ph, double sp) :
    id(id), lname(l), name(n), fname(f), address(add), phone(ph), SP(sp)
{}

string Abiturient::toString() {
    return to_string(this->id) + ", " + this->lname + ", " + this->name + ", " + this->fname +
            ", " + this->address + ", " + this->phone + ", " + to_string(this->SP);
}
