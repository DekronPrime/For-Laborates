#include <iostream>
#include <string>
using namespace std;

class Publication
{
protected:
    string name;
    float price;
public:
    virtual void inputData() = 0;
    virtual void showData() = 0;
};

class Book : public Publication {
    int countofPages;
public:
    void inputData() override {
        cin.ignore();
        cout << "Enter a name of the book: ";
        getline(cin, this->name);
        cout << "Enter a price of the book (uan): ";
        cin >> this->price;
        cout << "Enter a count of pages: ";
        cin >> this->countofPages;
    }
    void showData() override {
        cout << "Name of the book: " << name << endl;
        cout << "Price: " << price << " uan." << endl;
        cout << "Count of pages: " << countofPages << endl << endl;
    }
};

class Type : public Publication {
    float time;
public:
    void inputData() override {
        cin.ignore();
        cout << "Enter a name of the book: ";
        getline(cin, this->name);
        cout << "Enter a price of the book (uan): ";
        cin >> this->price;
        cout << "Enter the recording time (min): ";
        cin >> this->time;
    }
    void showData() override {
        cout << "Name of the book: " << name << endl;
        cout << "Price: " << price << " uan." << endl;
        cout << "Recording time: " << time << " min." << endl << endl;
    }
};

int main()
{
    cout << "Volodymyr Hordichuk" << endl;
    cout << "Laborate Work 5. Task 1." << endl << endl;
    Publication* arr[4];
    int j = 0;
    while (j < 4) {
        int answer;
        cout << "\nChoose type of object:\n1 - class Book\n2 - class Type\nYour answer: ";
        cin >> answer;
        cout << endl;
        switch (answer) {
        case 1:
            arr[j] = new Book;
            arr[j]->inputData();
            break;
        case 2:
            arr[j] = new Type;
            arr[j]->inputData();
            break;
        default:
            cout << "Wrong answer. Please, try again. " << endl;
        }
        j++;
    }
    cout << endl;
    for (int i = 0;i < 4;i++)
        arr[i]->showData();
}