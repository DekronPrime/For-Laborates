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

class Sales {
protected:
    float arr[3];
public:
    void setData() {
        for (int i = 0;i < 3;i++) {
            cout << "Введіть загальну вартість проданих книг за " << i + 1 << " місяць: ";
            cin >> this->arr[i];
        }
        cout << endl;
    }
    void getData() {
        for (int i = 0;i < 3;i++) {
            cout << "Загальна вартість проданих книг за " << i + 1 << " місяць: " << arr[i] << " грн.\n";
        }
        cout << endl;
    }
};

class Book : public Publication, public Sales {
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

class Type : public Publication, public Sales {
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
    cout << "Лабораторна робота №4. Завдання 2." << endl << endl;

    cout << "Press <Enter> to continue..." << endl;

    Book obj1;
    obj1.Publication::setData();
    obj1.setData();
    obj1.Publication::getData();
    obj1.getData();

    obj1.Sales::setData();
    obj1.Sales::getData();

    cout << "------------------------" << endl << endl;

    Type obj2;
    obj2.Publication::setData();    
    obj2.setData();
    obj2.Publication::getData();
    obj2.getData();

    obj2.Sales::setData();
    obj2.Sales::getData();
}