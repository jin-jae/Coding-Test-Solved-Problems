#include <iostream>

class	Time {
	private:
		int	hour;
		int	minute;
	public:
		Time(int hour = 0, int minute = 0);
		Time(const Time &a);
		Time& operator-=(int minute);
		friend std::ostream& operator<<(std::ostream &os, const Time &a);
};

Time::Time(int hour, int minute) : hour(hour), minute(minute) {
}

Time::Time(const Time &a) {
	this->hour = a.hour;
	this->minute = a.minute;
}

Time&	Time::operator-=(int minute) {
	this->minute -= minute;
	if (this->minute < 0) {
		this->hour -= 1;
		this->minute += 60;
	}
	if (this->hour < 0) {
		this->hour += 24;
	}
	return	*this;
}

std::ostream& operator<<(std::ostream &os, const Time &a) {
	os << a.hour << " " << a.minute;
	return	os;
}

int	main(void) {
	int	hour, minute;
	std::cin >> hour >> minute;
	Time	a(hour, minute);
	a -= 45;
	std::cout << a << std::endl;
}
