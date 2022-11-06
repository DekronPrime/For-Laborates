#include <iostream>
#include <Windows.h>
using namespace std;

template <typename T>
double SA(T arr[],int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Гордійчук Володимир. " << endl;
    cout << "Лабораторна робота №7. Завдання 1." << endl << endl;

    int arr1[5] = { 4,7,3,0,-5 };
    cout << "Середнє значення масиву типу int: " << SA(arr1,5) << endl;

    long arr2[3] = { 4574,8637,-5759 };
    cout << "Середнє значення масиву типу long: " << SA(arr2,3) << endl;

    double arr3[4] = { 4.75,8.01,1.26,-5.0 };
    cout << "Середнє значення масиву типу double: " << SA(arr3,4) << endl;

    char arr4[5] = {'A','B','C','D','E'};
    cout << "Середнє значення масиву типу char: " << SA(arr4,5) << endl;

    return 0;
}