#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

void PrintVector(const vector<char>& vec);

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    vector<char> alphabet;
    alphabet.reserve(33);

    for (int i = 224;i < 250;++i) {
        switch (i) {
        case 228:
            alphabet.push_back(180);
            break;
        case 230:
            alphabet.push_back(186);
            break;
        case 233:
            alphabet.push_back(179);
            alphabet.push_back(191);
            break;
        }
        alphabet.push_back(i);
    }
    alphabet.push_back(252);
    alphabet.push_back(254);
    alphabet.push_back(255);

    PrintVector(alphabet);

    for (int i = 0;i < alphabet.size(); ++i) {
        if (alphabet[i] == 'à')
            alphabet[i] = 'À';
        else if (alphabet[i] == 'î')
            alphabet[i] = 'Î';
        else if (alphabet[i] == 'ó')
            alphabet[i] = 'Ó';
        else if (alphabet[i] == 'è')
            alphabet[i] = 'È';
        else if (alphabet[i] == '³')
            alphabet[i] = '²';
        else if (alphabet[i] == 'å')
            alphabet[i] = 'Å';
    }
    cout << endl;

    PrintVector(alphabet);
}

void PrintVector(const vector<char>& vec) {
    for (int i = 0;i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}