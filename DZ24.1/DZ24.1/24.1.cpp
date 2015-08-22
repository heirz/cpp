
#include <iostream>
using namespace std;

enum flag{ Off, On };

class time{

	int hours;
	int minutes;
	int seconds;
	bool american;

public:

	//конструкторы/деструктор/конструктор копировани€.
	time(){ hours = 0; minutes = 0; seconds = 0; american = Off; };
	time(int hours, int minutes, int seconds, bool american){
		if (hours>24 || minutes>60 || seconds>60) {
			cout << "Ќеправильный формат параметров! (кол-во часов не более 24, минут - не более 60, секунд - не более 60)\n";
			this->hours = 0; this->minutes = 0; this->seconds = 0; this->american = Off;
		}
		else { this->hours = hours; this->minutes = minutes; this->seconds = seconds; this->american = american; }
	};
	~time(){};
	time(time &obj){ this->hours = obj.hours; this->minutes = obj.minutes; this->seconds = obj.seconds; this->american = obj.american; }

	//сеттеры
	void setHours(int hours){ this->hours = hours; }
	void setMinutes(int hours){ this->minutes = minutes; }
	void setSeconds(int seconds){ this->seconds = seconds; }
	void setAmerican(bool On_Off){ this->american = On_Off; }

	//геттеры
	int getHours(){ return this->hours; }
	int getMinutes(){ return this->minutes; }
	int getSeconds(){ return this->seconds; }
	bool getAmerican(){ return this->american; }

	//операторы
	time operator+ (time obj);
	time operator- (time obj);
	bool operator> (time obj);
	bool operator>= (time obj);
	bool operator< (time obj);
	bool operator<= (time obj);
	bool operator== (time obj);
	void operator()(int hours, int minutes, int seconds, int american){ this->hours = hours; this->minutes = minutes; this->seconds = seconds; this->american = american; };
	time operator= (time obj){ this->hours = obj.hours; this->minutes = obj.minutes; this->seconds = obj.seconds; this->american = obj.american; return *this; };

	//ввод-вывод
	void Show();
};

void time::Show(){
	if (!this->american) {
		if (hours<10)
			cout << 0 << hours;
		else cout << hours;
	         cout << ":";
		if (minutes<10)cout << 0 << minutes;
		else cout << minutes;
		cout << ":";
		if (seconds<10)cout << 0 << seconds;
		else cout << seconds;
		cout << "\n";
	}
	else{
		char ampm[10];

		if (hours>0 && hours<12) {
			strcpy(ampm, "am");
			if (hours<10)cout << 0 << hours;
			else cout << hours;
		}
		else if (hours == 12){
			strcpy(ampm, "midday");
			cout << hours;
		}
		else if (hours>12 && hours<24) {
			strcpy(ampm, "pm");
			if (hours - 12<10)cout << 0 << hours - 12;
			else cout << hours - 12;
		}
		else if (hours == 24){
			strcpy(ampm, "midnight");
			cout << hours - 12;
		}

		cout << ":";
		if (minutes<10)cout << 0 << minutes;
		else cout << minutes;
		cout << ":";
		if (seconds<10)cout << 0 << seconds;
		else cout << seconds;
		cout << " " << ampm;
		cout << "\n";

	}
};

time time::operator+ (time obj){

	seconds = seconds + obj.seconds;
	if (seconds >= 60) {
		seconds = seconds - 60; minutes++;
		if (minutes >= 60) { minutes = minutes - 60; hours++; }
		if (hours >= 24) hours = hours - 24;
	}

	minutes = minutes + obj.minutes;
	if (minutes >= 60) {
		minutes = minutes - 60; hours++;
		if (hours >= 24) hours = hours - 24;
	}

	hours = hours + obj.hours;
	if (hours >= 24) hours = hours - 24;

	return *this;
}

time time::operator- (time obj){

	seconds = seconds - obj.seconds;
	if (seconds<0) { seconds = 60 + seconds; minutes--; }
	if (minutes<0) { minutes = 60 + minutes; hours--; }
	if (hours<0) hours = 24 + hours;

	minutes = minutes - obj.minutes;
	if (minutes<0) { minutes = 60 + minutes; hours--; }
	if (hours<0) hours = 24 + hours;

	hours = hours - obj.hours;
	if (hours<0) hours = 24 + hours;

	return *this;
}

bool time::operator>(time obj){
	if (this->hours>obj.hours)return true;
	else if (this->hours>obj.hours == obj.hours && this->minutes>obj.minutes)return true;
	else if (this->hours>obj.hours == obj.hours && this->minutes == obj.minutes && this->seconds>obj.seconds)return true;
	else return false;
}
bool time::operator>= (time obj){
	if (this->hours>obj.hours)return true;
	else if (this->hours>obj.hours == obj.hours && this->minutes>obj.minutes)return true;
	else if (this->hours>obj.hours == obj.hours && this->minutes == obj.minutes && this->seconds>obj.seconds)return true;
	else if (this->seconds == obj.seconds)return true;
	else return false;
}
bool time::operator< (time obj){
	if (this->hours<obj.hours)return true;
	else if (this->hours>obj.hours == obj.hours && this->minutes<obj.minutes)return true;
	else if (this->hours>obj.hours == obj.hours && this->minutes == obj.minutes && this->seconds<obj.seconds)return true;
	else return false;
}
bool time::operator<= (time obj){
	if (this->hours<obj.hours)return true;
	else if (this->hours>obj.hours == obj.hours && this->minutes<obj.minutes)return true;
	else if (this->hours>obj.hours == obj.hours && this->minutes == obj.minutes && this->seconds<obj.seconds)return true;
	else if (this->seconds == obj.seconds)return true;
	else return false;
}

bool time::operator== (time obj){
	if (this->hours == obj.hours && this->minutes == obj.minutes && this->seconds == obj.seconds)return true;
	else return false;
}

int main(int argc, char * argv[]){
	setlocale(0, "");

	time testOne(12, 15, 33, Off);
	testOne.Show();
	time testTwo(07, 59, 59, Off);
	testTwo.Show();

	time testThree = testOne + testTwo;
	testThree.Show();
	testThree = testOne - testTwo;
	testThree.Show();

	cout << (testThree<testTwo) << '\n';
	cout << (testThree>testTwo) << '\n';
	cout << (testTwo == testTwo) << '\n';
	cout << (testTwo >= testTwo) << '\n';
	return 0;
}