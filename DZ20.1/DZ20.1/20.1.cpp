#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO Info;

class counter {

	int count;
	int speed;
	int min;
	int max;
	int startflag;
	char control;
	COORD current;
	COORD tmp;
	COORD stringpos;
	char symb;

public:

	counter(){
		count = 0;
		speed = 1000;
		min = 0;
		max = 60;
		startflag = 0;
		current.X = 0;
		current.Y = 0;
		tmp.X = 0;
		tmp.Y = 0;
		stringpos.X = 0;
		stringpos.Y = 0;
	}

private:
	void increase(){
		if (count<max){
			count++;
		}
		else{
			count = min;
			clearDigits();
		}
	}

	void clearDigits(){
		SetConsoleCursorPosition(H, tmp);
		cout << " ";
		SetConsoleCursorPosition(H, tmp);
	}

	void ShowText(){

		GetConsoleScreenBufferInfo(H, &Info);
		stringpos.X = Info.dwCursorPosition.X;
		stringpos.Y = Info.dwCursorPosition.Y;

		cout << "Текущее значение счетчика - ";
		GetConsoleScreenBufferInfo(H, &Info);
		tmp.X = Info.dwCursorPosition.X;
		tmp.Y = Info.dwCursorPosition.Y;

		clearDigits();
	}

	void ShowNext(){

		clearDigits();

		GetConsoleScreenBufferInfo(H, &Info);
		current.X = Info.dwCursorPosition.X;
		current.Y = Info.dwCursorPosition.Y;

		SetConsoleCursorPosition(H, tmp);
		cout << count;
		SetConsoleCursorPosition(H, current);
	}

public:
	void start(){

		ShowText();
		startflag = 1;
	}

	void stop(){
		GetConsoleScreenBufferInfo(H, &Info);
		deleteconsolestring(Info.dwCursorPosition);

		cout << endl;
		startflag = 0;
	}

	void counterloop() {
		while (startflag == 1){
			increase();
			ShowNext();
			Sleep(speed);

			if (_kbhit()){
				symb = _getch();
				if (symb == 27){
					stop();
				}
				else if (symb == 13){
					do{
						parameters_input();
						if (min>max){
							cout << "Минимальное значение не может быть больше максимального!!! Повторите ввод!!!";
						}
					} while (min>max);

					SetConsoleCursorPosition(H, stringpos);
					start();
					counterloop();
				}

			}
		}
	}

private:

	void deleteconsolestring(COORD START){
		SetConsoleCursorPosition(H, START);

		for (int i = 0; i<Info.srWindow.Bottom - 4; i++){
			for (int j = 0; j<Info.srWindow.Right; j++){
				cout << " ";
			}
		}
		SetConsoleCursorPosition(H, START);
	}

	void parameters_input(){
		stop();
		cout << endl;

		GetConsoleScreenBufferInfo(H, &Info);
		deleteconsolestring(Info.dwCursorPosition);

		cout << "Введите минимальное значение счетчика: ";
		cin >> min;
		cout << "Введите максимальное значение счетчика: ";
		cin >> max;
		cout << "Введите скорость счетчика (в миллисекундах): ";
		cin >> speed;
		cout << "Введите начальное значение счетчика: ";
		cin >> count;

	}
};

void main(){
	setlocale(0, "");
	cout << "Добро пожаловать в программу счетчик. (для выхода нажмите Esc, для ввода параметров - Enter)" << endl << endl;

	counter COUNT;

	COUNT.start();
	COUNT.counterloop();
}