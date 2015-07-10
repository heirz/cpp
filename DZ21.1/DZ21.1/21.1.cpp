#include <iostream>
#include<string.h>
#include<Windows.h>
using namespace std;

class Person{
private:
	string name;
	size_t age;
	bool sex;
	string phone_number;
public:
	Person(const string &n, const size_t &a, bool s, const string &p) :
		name(n), age(a), sex(s), phone_number(p){}
	void set(const string &n, const size_t &a, bool s, const string &p)
	{
		name = n; age = a; sex = s; phone_number = p;
	}
	
	void put_name(const string& s);
	void put_age(const size_t& a);
	void put_sex(bool s);
	void put_number(const string& n);
	void print() const
	{
		cout << "name: " << name << "\n";
		cout << "age: " << age << "\n";
		cout << "sex: " << (sex ? "male" : "female") << "\n";
		cout << "Pnumber: " << phone_number << "\n";
	}
};

int main() 
{
	Person t1("Petrov", 11, true, "11-11-11");

	t1.print();
	t1.put_age(22);
	t1.put_name("aasd");
	t1.put_sex(false);
	t1.put_number("none");

	t1.print();
}