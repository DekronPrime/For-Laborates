#include <iostream>
using namespace std;
class Time {
private:
	int hour;
	int min;
	int sec;
public:
	Time() {
		hour = 0;
		min = 0;
		sec = 0;
	}
	Time(int hour, int min = 0, int sec = 0) {
		int i = 0;

		this->hour = 0;
		this->min = 0;
		this->sec = 0;

		for (i = sec; i >= 60; i -= 60) {
			this->min++;
		}

		this->sec = i;

		for (i = min; i >= 60; i -= 60) {
			this->hour++;
		}

		this->min += i;
		this->hour += hour;
	}

	void showTime() {
		cout << this->hour << ":" << this->min << ":" << this->sec << endl;
	}

	Time sumofTimes(Time& newtime) {
		Time summaryTime(this->hour + newtime.hour, this->min + newtime.min, this->sec + newtime.sec);
		return summaryTime;
	}
};

int main()
{
	Time time0, time1(06, 59), time2(15, 01, 48);

	time0.showTime();
	time1.showTime();
	time2.showTime();

	cout << "\tSum of Times" << endl;
	cout << "-----------------------------" << endl;

	time0 = time1.sumofTimes(time2);
	time0.showTime();
	return 0;
}