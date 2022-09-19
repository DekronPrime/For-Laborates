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

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "1. Створити об'єкт по замовчуванню." << endl << endl;
    Plant* plant1 = new Plant;
    plant1->print();

    cout << "2. Створити об'єкт за параметром." << endl << endl;
    Plant* plant2 = new Plant("Квітка", 55);
    plant2->print();

    cout << "3. Копіювати об'єкт." << endl << endl;
    Plant* plant3 = new Plant(*plant1);
    plant3->print();

    cout << "4. Доступ до даних." << endl << endl;
    Plant* plant4 = new Plant("Будинок", 800);
    plant4->print();
    cout << "Бачимо, що нам потрібно змінити значення. Використаємо сетери і виведемо на екран за допомогою гетерів: " << endl;
    plant4->setSpecies("Дерево");
    plant4->setHeight(450);
    cout << "Вид - " << plant4->getSpecies() << endl << "Висота - " << plant4->getHeight() << " см" << endl << endl;

    cout << "5. Ввести дані і створити об'єкт." << endl << endl;
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