#include <stdio.h>
#include <stdarg.h>
#include <iostream>
using namespace std;

int printfAnalog(char * admString, ...);

int main(){
	printfAnalog("Hello, my name is %s!!! I'm %d years old. I'm %f meters tall.\n", "Nikita", 22, 1.85);
	return 0;
}

int printfAnalog(char * admString, ...){
	int symbCounter = 0;

	va_list parameters;
	va_start(parameters, admString);

	while (*admString != 0){
		if (*admString == '%'){
			admString++;

			if (*admString == '%')cout << '%';
			else if (*admString == 's'){
				cout << va_arg(parameters, char*);
			}
			else if (*admString == 'd')
			{
				cout << va_arg(parameters, int);
			}
			else if (*admString == 'f'){
				cout << va_arg(parameters, double);
			}
		}
		else {
			cout << *admString;
		}

		admString++;
	}

	va_end(parameters);

	return symbCounter;
}