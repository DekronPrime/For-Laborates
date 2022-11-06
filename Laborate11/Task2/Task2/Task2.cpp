#include <iostream>
#include <list>
#include <Windows.h>
using namespace std;

void PrintList(const list<char>& lst);

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    list<char> lastname = { 'Г','о','р','д','і','й','ч','у','к' };

    PrintList(lastname);
    cout << endl << "Список сортується..." << endl << endl;

    auto it1 = lastname.begin();
    advance(it1, 4);
    lastname.erase(it1);
    lastname.sort();
    auto it2 = lastname.begin();
    advance(it2, 2);
    lastname.emplace(it2, 'і');

    PrintList(lastname);
}

void PrintList(const list<char>& lst) {
    for (list<char>::const_iterator it = lst.cbegin(); it != lst.cend(); ++it) {
        cout << *it;
    }
    cout << endl;
}