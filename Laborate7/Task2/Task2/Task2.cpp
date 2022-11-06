#include <iostream>
#include <Windows.h>
using namespace std;

#define SIZE 5

template<typename T>
T amax(T arr[], int count) {
    T maxEl = 0;
    for (int i = 0;i < count;i++) {
        if (arr[i] > maxEl)
            maxEl = arr[i];
    }
    return maxEl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "�������� ���������. " << endl;
    cout << "����������� ������ �7. �������� 2." << endl << endl;

    int arr1[SIZE] = { 4,7,3,0,-5 };
    long arr2[SIZE] = { 4574,8637,3425,1420,-5759 };
    double arr3[SIZE] = { 4.75,8.01,3.7,1.26,-5.0 };

    cout << "������������ ������� ������ int: " << amax(arr1, SIZE) << endl;
    cout << "������������ ������� ������ long: " << amax(arr2, SIZE) << endl;
    cout << "������������ ������� ������ double: " << amax(arr3, SIZE) << endl;
    return 0;
}