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
        cout << "������ ����� �����: ";
        getline(cin, this->name);
        cout << "������ ���� �����(���): ";
        cin >> this->price;
    }
    void getData() {
        cout << "\n����� ������: " << name << endl;
        cout << "ֳ��: " << price << " ���." << endl;
    }
};

class Sales {
protected:
    float arr[3];
public:
    void setData() {
        for (int i = 0;i < 3;i++) {
            cout << "������ �������� ������� �������� ���� �� " << i + 1 << " �����: ";
            cin >> this->arr[i];
        }
        cout << endl;
    }
    void getData() {
        for (int i = 0;i < 3;i++) {
            cout << "�������� ������� �������� ���� �� " << i + 1 << " �����: " << arr[i] << " ���.\n";
        }
        cout << endl;
    }
};

class Book : public Publication, public Sales {
    int countofPages;
public:
    void setData() {
        cout << "������ ������� �������: ";
        cin >> this->countofPages;
    }
    void getData() {
        cout << "ʳ������ �������: " << countofPages << endl << endl;
    }
};

class Type : public Publication, public Sales {
    float time;
public:
    void setData() {
        cout << "������ ��� ������ �����(��): ";
        cin >> this->time;
    }
    void getData() {
        cout << "��� ������ �����: " << time << " ��." << endl << endl;
    }
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "�������� ���������" << endl;
    cout << "����������� ������ �4. �������� 2." << endl << endl;

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