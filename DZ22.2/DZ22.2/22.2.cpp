#include<iostream>
using namespace std;
class String
{
	char *str1;
	char *str3;
	int len;
public:
	String(){ str1 = NULL; str3 = NULL; }
	~String()
	{
		if (str1)
		{
			delete[] str1;
			str1 = NULL;
		}
		if (str3)
		{
			delete[] str3;
			str3 = NULL;
		}
	}
	void Inps1();
	String& operator *(String &N);
	String& operator =(String &N);
	void Showrez();

};
void String::Inps1()
{
	char a[256];
	gets(a);
	len = strlen(a) + 1;
	str1 = new char[strlen(N.str1) + 1];
	strcpy(str1, a);
}
String& String:: operator *(String &N)
{
	int tem = 1;
	len = strlen(str1) + 1;
	N.len = strlen(N.str1) + 1;
	for (int i = 0; i<len; i++)
	{
		for (int j = 0; j<N.len; j++)
		{
			if (str1[i] == N.str1[i])
				tem++;
		}
	}
	str3 = new char[strlen(N.str3) + 1];
	str3[0] = '\0';
	for (int i = 0; i<len; i++)
	{
		for (int j = 0; j<N.len; j++)
		{
			if (str1[i] == N.str1[j])
				strncat(str3, &str1[i], 1);
		}
	}
	return *this;
}
String& String:: operator =(String &N)
{
	if (str1)
		delete[] str1;
	if (str3)
		delete[] str3;
	str1 = new char[strlen(N.str1 + 1)];
	str3 = new char[strlen(N.str3 + 1)];
	strcpy(str1, N.str1);
	strcpy(str3, N.str3);
	len = N.len;
	return *this;
}
void String::Showrez()
{
	cout << "–езультат умножени€ двух строк: " << str3 << endl;
}
void main()
{
	setlocale(LC_CTYPE, "Rus");
	String A, B, C;
	cout << "¬ведите первую строку\n";
	A.Inps1();
	cout << "¬ведите вторую строку\n";
	B.Inps1();
	C = A*B;
	C.Showrez();
	cout << endl;
}