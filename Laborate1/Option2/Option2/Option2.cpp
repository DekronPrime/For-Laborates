#include <iostream>
using namespace std;

class Kasa {
private:
	int cars;
	double money;
public:
	Kasa() {
		this->cars = 0;
		this->money = 0;
	}
	
	void payingCar() {
		this->cars++;
		this->money += 0.5;
	}

	void nopayCar() {
		this->cars++;
	}

	void display() {
		cout << "Cars: " << this->cars << endl;
		cout << "Money: " << this->money << " $" << endl << endl;
	}
};

int main()
{
	cout << "\tWelcom on the freeway!" << endl;
	cout << "_____________________________________" << endl;
	
	Kasa obj;

	while (true) {
		char symbol;
		cout << "Press 'P' to pay or 'N' to not pay." << endl;
		cout << "Press 'D' to show all data." << endl;
		cout << "Press 'E' to end the program." << endl;
		cout << "Your answer: ";
		cin >> symbol;
		cout << endl;
		switch (symbol) {
		case 'P':
			cout << "You chose 'P'. Your fare is paid." << endl << endl;
			obj.payingCar();
			break;
		case 'N':
			cout << "You chose 'N'. Your fare has not been paid." << endl << endl;
			obj.nopayCar();
			break;
		case 'D':
			cout << "All data: " << endl;
			cout << "===================" << endl;
			obj.display();
			break;
		case 'E':
			cout << "Bye" << endl;
			return 0;
		default:
			cout << "Wrong option. Please try again. " << endl << endl;
		}
	}
}