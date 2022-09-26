#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;


class Publication
{
protected:
    string name;
    float price;
public:
    void setData() {
        cin.ignore();
        cout << "Введіть назву книги: ";
        getline(cin, this->name);
        cout << "Введіть ціну книги(грн): ";
        cin >> this->price;
    }
    void getData() {
        cout << "\nНазва книжки: " << name << endl;
        cout << "Ціна: " << price << " грн." << endl;
    }
};

class Book : public Publication {
    int countofPages;
public:
    void setData() {
        cout << "Введіть кількість сторінок: ";
        cin >> this->countofPages;
    }
    void getData() {
        cout << "Кількість сторінок: " << countofPages << endl << endl;
    }
};

class Type : public Publication {
    float time;
public:
    void setData() {
        cout << "Введіть час запису книги(хв): ";
        cin >> this->time;
    }
    void getData() {
        cout << "Час запису книги: " << time << " хв." << endl << endl;
    }
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Гордійчук Володимир" << endl;
    cout << "Лабораторна робота №4. Завдання 1." << endl << endl;

    cout << "Press <Enter> to continue..." << endl;

    Book obj1;
    obj1.Publication::setData();
    obj1.setData();
    obj1.Publication::getData();
    obj1.getData();

    Type obj2;
    obj2.Publication::setData();
    obj2.setData();
    obj2.Publication::getData();
    obj2.getData();
}