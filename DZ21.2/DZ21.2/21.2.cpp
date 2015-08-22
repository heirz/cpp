#include <iostream>
#include<string.h>
#include<Windows.h>
using namespace std;

class STR {
	char * data;

public:

	STR(){
		data = new char[80];
	}

	STR(int charAmount){
		data = new char[charAmount];
	}

	STR(int charAmount, char*uText){
		data = new char[charAmount];
		strcpy(data, uText);
	}

	void SHOW(){
		cout << data << endl;
	}

	void INPUT(){
		strcpy(data, "\0");
		gets(data);
		OemToAnsi(data, data);
	}

	~STR(){ delete[] data; }
};

int main(){
	setlocale(0, "");

	STR text(200, "Текст, заданный как аргумент метода класса!!! Введи строку:");
	text.SHOW();
	text.INPUT();
	text.SHOW();

	return 0;
}