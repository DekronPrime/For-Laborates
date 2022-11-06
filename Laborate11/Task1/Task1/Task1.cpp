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
        if (alphabet[i] == '�')
            alphabet[i] = '�';
        else if (alphabet[i] == '�')
            alphabet[i] = '�';
        else if (alphabet[i] == '�')
            alphabet[i] = '�';
        else if (alphabet[i] == '�')
            alphabet[i] = '�';
        else if (alphabet[i] == '�')
            alphabet[i] = '�';
        else if (alphabet[i] == '�')
            alphabet[i] = '�';
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