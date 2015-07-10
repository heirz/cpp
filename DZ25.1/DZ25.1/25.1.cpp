#include <iostream>
using namespace std;

#include <math.h>

class cDig {
	double x;
	double y;

public:
	cDig(double x = 0, double y = 0) :x(x), y(y){};
	cDig(const cDig & obj) :x(obj.x), y(obj.y){};

	//=
	cDig operator=(cDig obj);
	//==
	bool operator==(cDig obj);
	//!=
	bool operator!=(cDig obj);
	//+
	cDig operator+(cDig obj);
	//-
	cDig operator-(cDig obj);
	//*
	cDig operator*(cDig obj);
	///
	cDig operator/(cDig obj);
	//abs
	double cAbs();
	//sqrt
	cDig cSqrt();
	//<<
	friend ostream& operator<<(ostream&out, cDig & obj);
	//>>
	friend istream& operator>>(istream&in, cDig & obj);
};

cDig cDig::operator= (cDig obj){ x = obj.x; y = obj.y; return *this; }

bool cDig::operator==(cDig obj){
	if (x == obj.x && y == obj.y)return true;
	else return false;
}
bool cDig::operator!=(cDig obj){
	if (x == obj.x && y == obj.y)return false;
	else return true;
}
cDig cDig::operator+(cDig obj){
	cDig tmp;
	tmp.x = x + obj.x;
	tmp.y = y + obj.y;
	return tmp;
}
cDig cDig::operator-(cDig obj){
	cDig tmp;
	tmp.x = x - obj.x;
	tmp.y = y - obj.y;
	return tmp;
}
cDig cDig::operator*(cDig obj){
	cDig tmp;
	tmp.x = x*obj.x - y*obj.y;
	tmp.y = y*obj.x + x*obj.y;
	return tmp;
}
cDig cDig::operator/(cDig obj){
	cDig tmp;
	tmp.x = (x*obj.x + y*obj.y) / (obj.x*obj.x + obj.y*obj.y);
	tmp.y = (y*obj.x - x*obj.y) / (obj.x*obj.x + obj.y*obj.y);
	return tmp;
}
double cDig::cAbs(){
	double abs = sqrt(pow(x, 2) + pow(y, 2));
	return abs;
}
cDig cDig::cSqrt(){
	cDig tmp;
	tmp.x = x*x - y*y;
	tmp.y = 2 * x*y;
	return tmp;
}
ostream& operator<<(ostream&out, cDig & obj){
	out << "Complex digit:\n";
	out << "Real part - " << obj.x << ";\n";
	out << "Impress part - " << obj.y << ";\n\n";
	return out;
}
istream& operator>>(istream&in, cDig & obj){
	cout << "Set complex digit:\n";
	cout << "Set real part - ";
	in >> obj.x;
	cout << "Set impress part - ";
	in >> obj.y;
	cout << "\n";

	return in;
}

int main(){

	cDig test1;
	cin >> test1;

	cDig test2;
	cin >> test2;

	cDig test3;

	cout << "operator +\n";
	test3 = test1 + test2;
	cout << test3;
	cout << "operator -\n";
	test3 = test1 - test2;
	cout << test3;
	cout << "operator *\n";
	test3 = test1 * test2;
	cout << test3;
	cout << "operator /\n";
	test3 = test1 / test2;
	cout << test3;

	cout << "function cSqrt\n";
	cout << test1.cSqrt();

	cout << "function cAbs\n";
	cout << test1.cAbs() << "\n\n";

	cout << "operator ==\n";
	cout << (test1 == test2) << "\n\n";
	cout << "operator !=\n";
	cout << (test1 != test2) << "\n\n";

	return 0;
}