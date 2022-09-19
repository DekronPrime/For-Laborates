#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string.h>
using namespace std;

class Plant {
private:
    char* species;  // вид
    int height;     // висота рослини
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
    strcpy(species, "Трава");
    height = 30;
    cout << "(Спрацював конструктор по замовчуванню) " << endl;
}

Plant::Plant(const char* newSpecies, int height)
{
    this->species = new char[strlen(newSpecies) + 1];
    strcpy(this->species, newSpecies);
    this->height = height;
    cout << "(Спрацював параметризований конструктор) " << endl;
}

Plant::Plant(const Plant& plant)
{
    this->species = new char[strlen(plant.species) + 1];
    strcpy(this->species, plant.species);
    this->height = plant.height;
    cout << "(Спрацював конструктор копіювання) " << endl;
}

Plant::~Plant()
{
    cout << "(Спрацював деструктор)" << endl;
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
        cout << "Некоректно введене значення. Висота замінена на 1 см." << endl;
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
    cout << "Вид - " << this->species << endl << "Висота - " << this->height << " см" << endl << endl;
}

void Plant::input()
{
    species = new char[20];
    cout << "\tВведіть вид рослини: ";
    cin.getline(species, 20);
    while (strlen(species) == 0) {
        cout << "Ви нічого не написали. Спробуйте ще раз." << endl << endl;
        cout << "\tВведіть вид рослини: ";
        cin.getline(species, 20);
    }
    strcpy(this->species, species);
    int height;
    cout << "\tВведіть висоту рослини: ";
    cin >> height;
    while (height <= 0) {
        cout << "Неправильна висота. Введіть ще раз." << endl << endl;
        cout << "\tВведіть висоту рослини: ";
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
    cout << "Вид: ";
    is >> value;
    obj.species = new char[strlen(value) + 1];
    strcpy(obj.species, value);
    delete[]value;
    cout << "Висота: ";
    is >> obj.height;
    cout << endl;
    return is;
}

ostream& operator<<(ostream& os, Plant& obj)
{
    cout << "Вид - " << obj.species << endl << "Висота - " << obj.height << " см" << endl << endl;
    return os;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Plant plant;
    cout << "Введіть вид рослини та її висоту: " << endl;
    cin >> plant;
    cout << plant;

    return 0;
}