#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

class Plant {
private:
    string species; // вид
    int height; // висота рослини
public:
    Plant();
    Plant(string newSpecies, int height);
    Plant(const Plant& plant);
    ~Plant();
    void setSpecies(string species);
    string getSpecies();
    void setHeight(int height);
    int getHeight();
    void print() const;
    void input();
};

Plant::Plant() {
    this->species = "";
    this->height = 0;
}

Plant::Plant(string newSpecies, int height){
    this->species = newSpecies;
    this->height = height;
}

Plant::Plant(const Plant& plant) {
    this->species = plant.species;
    this->height = plant.height;
}

Plant::~Plant() {

}

void Plant::setSpecies(string species) {
    this->species = species;
}

string Plant::getSpecies() {
    return this->species;
}

void Plant::setHeight(int height) {
    this->height = height;
}

int Plant::getHeight() {
    return this->height;
}

void Plant::print() const {
    cout << "Вид: " << this->species << "\tВисота: " << this->height << " см" << endl;
}

void Plant::input() {
    string species;
    do {
        cout << "Введіть вид рослини: ";
        cin >> species;
    } while (species != "");
    this->species = species;
    int height;
    do {
        cout << "Введіть висоту рослини: ";
        cin >> height;
    } while (height != 0);
    this->height = height;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    vector<Plant> pl;
    pl.reserve(10);

    pl.push_back(Plant("Береза", 2000));
    pl.push_back(Plant("Полуниця", 50));
    pl.push_back(Plant("Дуб", 1850));
    pl.push_back(Plant("Яблуня", 1500));
    pl.push_back(Plant("Мак", 75));
    pl.push_back(Plant("Морва", 1325));
    pl.push_back(Plant("Кропива", 80));
    pl.push_back(Plant("Ожина", 1050));
    pl.push_back(Plant("Вишня", 2100));
    pl.push_back(Plant("Горіх", 4560));

    for (int i = 0; i < pl.size(); ++i) {
        pl[i].print();
    }
    cout << endl;
    for (auto it = pl.cbegin(); it != pl.cend(); ++it) {
        it->print();
    }
}