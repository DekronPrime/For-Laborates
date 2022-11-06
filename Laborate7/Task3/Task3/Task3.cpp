#include <iostream>
#include <Windows.h>
using namespace std;

template <class T>
class Array {
private:
    T* arr;
    int count;
public:

    Array() {
        int count;
        cout << "Введіть кількість елементів масиву: ";
        cin >> count;
        this->count = count;
        this->arr = new T[count];
    }

    Array(int count) {
        this->count = count;
        this->arr = new T[count];
    }

    void input() {
        cout << "\nВвід даних: " << endl;
        for (int i = 0;i < count;i++) {
            cout << "Введіть " << i + 1 << " елемент масиву: ";
            cin >> arr[i];
        }
        cout << endl;
    }

    void show() {
        cout << "Масив: ";
        for (int i = 0;i < count;i++) {
            cout << arr[i] << " ";
        }
    }

    double findAverage() {
        double sum = 0;
        for (int i = 0; i < count; i++) {
            sum += this->arr[i];
        }
        return sum / count;
    }

    T findMax() {
        T maxEl = 0;
        for (int i = 0;i < count;i++) {
            if (arr[i] > maxEl)
                maxEl = arr[i];
        }
        return maxEl;
    }

};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Гордійчук Володимир. " << endl;
    cout << "Лабораторна робота №7. Завдання 3." << endl << endl;

    Array<int> a1;
    a1.input();
    a1.show();
    cout << endl << "Середнє арифметичне: " << a1.findAverage() << endl;
    cout << "Максимальний елемент масиву: " << a1.findMax() << endl;

    Array<long> a2(5);
    a2.input();
    a2.show();
    cout << endl << "Середнє арифметичне: " << a2.findAverage() << endl;
    cout << "Максимальний елемент масиву: " << a2.findMax() << endl;

    Array<double> a3(4);
    a3.input();
    a3.show();
    cout << endl << "Середнє арифметичне: " << a3.findAverage() << endl;
    cout << "Максимальний елемент масиву: " << a3.findMax() << endl;

    return 0;
}