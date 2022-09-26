#include <iostream>
#include <math.h>
#include <Windows.h>
using namespace std;

class CoupleofNumbers {
protected:
    float a;
    float b;
public:

    CoupleofNumbers() : a(0), b(0)
    {}

    CoupleofNumbers(float a, float b) : a(a), b(b)
    {}

    ~CoupleofNumbers()
    {}

    void setA(float a) {
        this->a = a;
    }

    float getA() {
        return a;
    }

    void setB(float b) {
        this->b = b;
    }

    float getB() {
        return b;
    }

    void setNumbers() {
        cout << "������ ����� �����: ";
        cin >> this->a;
        cout << "������ ����� �����: ";
        cin >> this->b;
        cout << endl;
    }

    void showNumbers() {
        cout << "����� �����: " << a << endl;
        cout << "����� �����: " << b << endl << endl;
    }

    float multi() {
        return a * b;
    }

};

class RightTriangle : public CoupleofNumbers {
private:
    float catA;
    float catB;
public:
    RightTriangle() : CoupleofNumbers()
    {}

    RightTriangle(float a, float b) : catA(a), catB(b)
    {}

    ~RightTriangle()
    {}

    void setcatA(float catA) {
        this->catA = catA;
    }

    float getcatA() {
        return catA;
    }

    void setcatB(float catB) {
        this->catB = catB;
    }

    float getcatB() {
        return catB;
    }

    float Hypotenuse() {
        if (catA > 0 || catB > 0)
            return sqrt(pow(catA, 2) + pow(catB, 2));
        else
            throw exception();
    }

    void inputData() {
        cout << "������ ������ �����: ";
        cin >> catA;
        if (catA <= 0)
            throw exception();
        cout << "������ ������ �����: ";
        cin >> catB;
        cout << endl;
        if (catB <= 0)
            throw exception();
    }

    void showData() {
        if (catA > 0 || catB > 0) {
            cout << "������ �����: " << catA << endl;
            cout << "������ �����: " << catB << endl;
            cout << "ó��������: " << Hypotenuse() << endl << endl;
        }
        else
            throw exception();
    }

    float Square() {
        if (catA > 0 || catB > 0) {
            float h = Hypotenuse();
            float p = (catA + catB + h) / 2;
            return sqrt(p * (p - catA) * (p - catB) * (p - h));
        }
        else
            throw exception();
    }
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "�������� ���������" << endl;
    cout << "����������� ������ �4. �������� 3. ������ 4." << endl << endl;

    cout << "<obj1>" << endl << endl;
    CoupleofNumbers obj1, obj2(14,3), obj3;
    obj1.showNumbers();
    obj1.setA(2);
    obj1.setB(7);
    obj1.showNumbers();

    cout << "<obj2>" << endl << endl;
    obj2.showNumbers();

    cout << "<obj3>" << endl << endl;
    obj3.setNumbers();
    obj3.showNumbers();

    float res = obj2.multi();
    cout << "�������� ����� " << obj2.getA() << " i " << obj2.getB() << " = " << res << endl;

    cout << "==============================" << endl << endl;

    RightTriangle tr1, tr2(6,2), tr3;

    cout << "<tr1>" << endl << endl;
    tr1.inputData();
    tr1.showData();

    cout << "<tr2>" << endl << endl;
    tr2.showData();

    cout << "<tr3>" << endl << endl;
    tr3.inputData();
    tr3.showData();
    float S = tr3.Square();
    cout << "����� ������������ ���������� � �������� " << tr3.getcatA() << " i " << tr3.getcatB() << ": " << endl;
    cout << "Square = " << S << endl;
}