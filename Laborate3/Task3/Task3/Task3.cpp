#include <iostream>
#include <assert.h>
#include <Windows.h>
using namespace std;

class Time{
private:
	int hour;
	int minute;
	int second;
public:
	Time();

	Time(int hour, int minute, int second);

	~Time();

	void showTime() const;

	Time operator+=(int n);

	Time operator-(Time& obj);

	bool operator<=(Time& obj);

	bool operator>(Time& obj);

	friend istream& operator >>(istream& is, Time& obj);

	friend ostream& operator <<(ostream& os, Time& obj);
};

Time::Time()
{
	hour = 0;
	minute = 0;
	second = 0;
}

Time::Time(int hour, int minute = 0, int second = 0)
{
	int i = 0;

	this->hour = 0;
	this->minute = 0;
	this->second = 0;

	for (i = second; i >= 60; i -= 60) {
		this->minute++;
	}

	this->second = i;

	for (i = minute; i >= 60; i -= 60) {
		this->hour++;
	}

	this->minute += i;
	this->hour += hour;

	if (this->hour >= 24)
		this->hour -= 24;
}

Time::~Time()
{
	//cout << "(Destructor)" << endl;
}

void Time::showTime() const
{
	cout << this->hour << ":" << this->minute << ":" << this->second << endl;
}

Time Time::operator+=(int n)
{
	this->second += n;

	while (this->second >= 60) {
		this->second -= 60;
		this->minute++;
	}

	while (this->minute >= 60) {
		this->minute -= 60;
		this->hour++;
	}

	while (this->hour >= 24)
		this->hour -= 24;

	return *this;
}

Time Time::operator-(Time& obj)
{
	this->second -= obj.second;
	this->minute -= obj.minute;
	this->hour -= obj.hour;
	return *this;
}

bool Time::operator<=(Time& obj)
{
	this->second += this->hour * 3600 + this->minute * 60;
	obj.second += obj.hour * 3600 + obj.minute * 60;
	return this->second <= obj.second;
}

bool Time::operator>(Time& obj)
{
	this->second += this->hour * 3600 + this->minute * 60;
	obj.second += obj.hour * 3600 + obj.minute * 60;
	return !(this->second <= obj.second);
}

istream& operator>>(istream& is, Time& obj)
{
	cout << "Input data: " << endl;
	cout << "Enter a hour: ";
	is >> obj.hour;
	while (obj.hour >= 24) {
		cout << "Wrong hour. Please, write again." << endl;
		cout << "Enter a hour: ";
		is >> obj.hour;
	}
	cout << "Enter a minute: ";
	is >> obj.minute;
	while (obj.minute >= 60) {
		cout << "Wrong minute. Please, write again." << endl;
		cout << "Enter a minute: ";
		is >> obj.minute;
	}
	cout << "Enter a second: ";
	is >> obj.second;
	while (obj.second >= 60) {
		cout << "Wrong second. Please, write again." << endl;
		cout << "Enter a second: ";
		is >> obj.second;
	}
	cout << endl;
	return is;
}

ostream& operator<<(ostream& os, Time& obj)
{
	cout << obj.hour << ":" << obj.minute << ":" << obj.second << endl;
	return os;
}


int main()
{
	Time time1(10, 45, 59);
	Time time2(6, 21);
	Time time3;

	cin >> time3;
	cout << "Time1 | " << time1 << "Time2 | " << time2 << "Time3 | " << time3;
	cout << "____________________" << endl;

	Time time4 = time3 += 10;
	cout << "\nTime3 + 10s | " << endl;
	time4.showTime();

	Time time5 = time1 - time2;
	cout << "\nTime1 - Time2 | " << endl;
	time5.showTime();

	bool result = time2 > time3;
	cout << "\nTime2 > Time3 ? |" << endl;
	if (result)
		cout << "result - TRUE" << endl;
	else
		cout << "result - FALSE" << endl;
}

