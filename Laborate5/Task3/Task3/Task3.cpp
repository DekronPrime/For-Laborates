#include <iostream>
#include <math.h>
using namespace std;

class CoupleofNumbers {
public:
    virtual float Multy(float a, float b) {
        return a * b;
    }
    virtual void Square() = 0;
    virtual void inputData() = 0;
};

class RightTriangle : public CoupleofNumbers {
private:
    float catA;
    float catB;
public:

    RightTriangle() : catA(0), catB(0) {}

    RightTriangle(float a, float b) : catA(a), catB(b) {}

    ~RightTriangle() {}

    void inputData() override {
        do {
            cout << "\tInput data." << endl << endl;
            cout << "Enter the first side: ";
            cin >> catA;
            cout << "\nEnter the second side: ";
            cin >> catB;
            cout << endl;
        } while (catA <= 0 || catB <= 0);
    }

    void Square() override {
        float Hyp = sqrt(pow(catA, 2) + pow(catB, 2));
        float p = (catA + catB + Hyp) / 2;
        float S = sqrt(p * (p - catA) * (p - catB) * (p - Hyp));
        cout << "Square of triangle: " << S << endl;
    }
};

class Rhomb : public CoupleofNumbers {
private:
    float a;
    float angle;
public:

    Rhomb() : a(0), angle(0) {}

    Rhomb(float a, float b) : a(a), angle(b) {}

    ~Rhomb() {}

    void inputData() override {
        do {
            cout << "\tInput data." << endl << endl;
            cout << "Enter the side of a rhomb: ";
            cin >> a;
            cout << "\nEnter an angle: ";
            cin >> angle;
            cout << endl;
        } while (a <= 0 || angle <= 0);
    }

    void Square() override {
        float S = pow(a, 2) * sin(angle);
        cout << "Square of rhomb: " << round(S*10)/10 << endl;
    }
};

int main()
{
    cout << "Volodymyr Hordichuk" << endl;
    cout << "Laborate Work 5. Task 3." << endl << endl;

    RightTriangle tr(5, 3);
    Rhomb r(4, 45);

    CoupleofNumbers* arr[2];
    arr[0] = &tr;
    arr[1] = &r;
    for (int i = 0;i < 2;i++)
        arr[i]->Square();
}