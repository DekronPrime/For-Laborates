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

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "1. �������� ��'��� �� ������������." << endl << endl;
    Plant* plant1 = new Plant;
    plant1->print();

    cout << "2. �������� ��'��� �� ����������." << endl << endl;
    Plant* plant2 = new Plant("�����", 55);
    plant2->print();

    cout << "3. �������� ��'���." << endl << endl;
    Plant* plant3 = new Plant(*plant1);
    plant3->print();

    cout << "4. ������ �� �����." << endl << endl;
    Plant* plant4 = new Plant("�������", 800);
    plant4->print();
    cout << "������, �� ��� ������� ������ ��������. ����������� ������ � �������� �� ����� �� ��������� ������: " << endl;
    plant4->setSpecies("������");
    plant4->setHeight(450);
    cout << "��� - " << plant4->getSpecies() << endl << "������ - " << plant4->getHeight() << " ��" << endl << endl;

    cout << "5. ������ ��� � �������� ��'���." << endl << endl;
    Plant* plantNew = new Plant();
    plantNew->input();
    plantNew->print();

    delete plant1;
    delete plant2;
    delete plant3;
    delete plant4;
    delete plantNew;

    return 0;
}