#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO Info;

struct date{
	int day;
	int month;
	int year;
};

class student {

public:
	char * name;
	char * thurname;
	char * GroupName;
	date DateOfBirth;

	student(){
		name = new char[100];
		thurname = new char[100];
		GroupName = new char[100];
	}

	~student(){
		delete[] name;
		name = NULL;
		delete[] thurname;
		thurname = NULL;
		delete[] GroupName;
		GroupName = NULL;
	}

};

class GroupOfStudents{

public:

	student * students;
	int StudentsAmount;
	char * GroupName;

	GroupOfStudents(int amount, char * Name){
		students = new student[amount];
		StudentsAmount = amount;
		GroupName = new char[100];
		strcpy(GroupName, Name);
		cout << "Создана группа " << GroupName << ". В группе " << StudentsAmount << " студентов!" << endl;
	}

	~GroupOfStudents(){
		cout << "Уничтожена группа " << GroupName << "!" << endl;
		delete[] students;
		students = NULL;
		delete[]GroupName;
		GroupName = NULL;

	}
};

void main(){
	setlocale(0, "");

	GroupOfStudents A_FIRST(6, "П-32-14");

}