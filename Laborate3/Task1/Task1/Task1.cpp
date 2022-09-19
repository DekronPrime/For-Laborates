#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string.h>
using namespace std;

class Integer {
private:
    int number;
public:
    Integer();

    Integer(int number);

    Integer operator + (const Integer& obj);

    Integer operator - (const Integer& obj);

    Integer operator * (const Integer& obj);

    Integer operator / (const Integer& obj);

    void showNumber() const;
};

Integer::Integer()
{
    number = 0;
}

Integer::Integer(int number)
{
    this->number = number;
}

Integer Integer::operator+(const Integer& obj)
{
    long double a = this->number;
    long double b = obj.number;
    a += b;
    if (a <= INT_MIN || a >= INT_MAX) {
        cout << "Error. This number is out the range 'int' type." << endl;
        return 0;
    }
    return Integer(a);
}

Integer Integer::operator-(const Integer& obj)
{
    long double a = this->number;
    long double b = obj.number;
    a -= b;
    if (a <= INT_MIN || a >= INT_MAX) {
        cout << "Error. This number is out the range 'int' type." << endl;
        return 0;
    }
    return Integer(a);
}

Integer Integer::operator*(const Integer& obj)
{
    long double a = this->number;
    long double b = obj.number;
    a *= b;
    if (a <= INT_MIN || a >= INT_MAX) {
        cout << "Error. This number is out the range 'int' type." << endl;
        return 0;
    }
    return Integer(a);
}

Integer Integer::operator/(const Integer& obj)
{
    long double a = this->number;
    long double b = obj.number;
    if (b == 0) {
        cout << "Devision by zero!" << endl;
        exit(0);
    }
    else {
        a /= b;
        if (a <= INT_MIN || a >= INT_MAX) {
            cout << "Error. This number is out the range 'int' type." << endl;
            return 0;
        }
        return Integer(a);
    }
}

void Integer::showNumber() const
{
    cout << "This number is " << this->number << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Integer n1(200);
    Integer n2(100);

    Integer n3 = n1 + n2;
    n3.showNumber();

    Integer n4 = n1 - n2;
    n4.showNumber();

    Integer n5 = n1 * n2;
    n5.showNumber();

    Integer n6 = n1 / n2;
    n6.showNumber();

    cout << "________________________" << endl;
    Integer obj1(500);
    Integer obj2(0);
    Integer div = obj1 / obj2;
    div.showNumber();

    return 0;
}