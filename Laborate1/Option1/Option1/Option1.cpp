#include <iostream>
using namespace std;

class Integer {
private:
    int number;
public:
    Integer() {
        this->number = 0;
    }
    Integer(int number) {
        this->number = number;
    }
    void display() {
        cout << "Number is " << this->number << endl;
    }

    Integer sumofNumbers(Integer& newnumber) {
        Integer newSum (this->number + newnumber.number);
        return newSum;
    }
};


int main()
{
    Integer obj1, obj2(1), obj3(99);

    obj1.display();
    obj2.display();
    obj3.display();

    cout << "\tSum of Integers" << endl;
    cout << "------------------------------------" << endl;

    obj1 = obj2.sumofNumbers(obj3);
    obj1.display();
    return 0;
}