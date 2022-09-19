#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string.h>
using namespace std;

class Plant {
private:
    char* species;  // ���
    int height;     // ������ �������
public:

    Plant();

    Plant(const char* newSpecies, int height);

    Plant(const Plant& plant);

    ~Plant();

    void setSpecies(const char* species);

    char* getSpecies();

    void setHeight(int height);

    int getHeight();

    void print() const;

    void input();

    friend istream& operator >>(istream& is, Plant& obj);

    friend ostream& operator <<(ostream& os, Plant& obj);
};

Plant::Plant()
{
    species = new char[10];
    strcpy(species, "�����");
    height = 30;
    cout << "(��������� ����������� �� ������������) " << endl;
}

Plant::Plant(const char* newSpecies, int height)
{
    this->species = new char[strlen(newSpecies) + 1];
    strcpy(this->species, newSpecies);
    this->height = height;
    cout << "(��������� ���������������� �����������) " << endl;
}

Plant::Plant(const Plant& plant)
{
    this->species = new char[strlen(plant.species) + 1];
    strcpy(this->species, plant.species);
    this->height = plant.height;
    cout << "(��������� ����������� ���������) " << endl;
}

Plant::~Plant()
{
    cout << "(��������� ����������)" << endl;
    if (species != nullptr) {
        delete[] species;
    }
}

void Plant::setSpecies(const char* species)
{
    if (this->species != nullptr) {
        delete this->species;
    }
    this->species = new char[strlen(species) + 1];
    strcpy(this->species, species);
}

char* Plant::getSpecies()
{
    return this->species;
}

void Plant::setHeight(int height)
{
    if (height <= 0) {
        cout << "���������� ������� ��������. ������ ������� �� 1 ��." << endl;
        height = 1;
    }
    this->height = height;
}

int Plant::getHeight()
{
    return this->height;
}

void Plant::print() const
{
    cout << "��� - " << this->species << endl << "������ - " << this->height << " ��" << endl << endl;
}

void Plant::input()
{
    species = new char[20];
    cout << "\t������ ��� �������: ";
    cin.getline(species, 20);
    while (strlen(species) == 0) {
        cout << "�� ����� �� ��������. ��������� �� ���." << endl << endl;
        cout << "\t������ ��� �������: ";
        cin.getline(species, 20);
    }
    strcpy(this->species, species);
    int height;
    cout << "\t������ ������ �������: ";
    cin >> height;
    while (height <= 0) {
        cout << "����������� ������. ������ �� ���." << endl << endl;
        cout << "\t������ ������ �������: ";
        cin >> height;
    }
    this->height = height;
    cout << endl;
}

istream& operator>>(istream& is, Plant& obj)
{
    if (obj.species != nullptr)
        delete[]obj.species;
    char* value = new char[20];
    cout << "���: ";
    is >> value;
    obj.species = new char[strlen(value) + 1];
    strcpy(obj.species, value);
    delete[]value;
    cout << "������: ";
    is >> obj.height;
    cout << endl;
    return is;
}

ostream& operator<<(ostream& os, Plant& obj)
{
    cout << "��� - " << obj.species << endl << "������ - " << obj.height << " ��" << endl << endl;
    return os;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Plant plant;
    cout << "������ ��� ������� �� �� ������: " << endl;
    cin >> plant;
    cout << plant;

    return 0;
}