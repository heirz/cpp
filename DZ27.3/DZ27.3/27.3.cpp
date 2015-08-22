#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Array{
	T * mData;
	int mCounter;
	int mSize;
	int mGrow;

public:
	Array();
	~Array();
	int GetSize();
	void SetSize(unsigned int size, int grow = 1);
	int GetUpperBound();
	bool isEmpty();
	void FreeExtra();
	void removeAll();
	T GetAt(int index);
	void SetAt(int index, T data);
	T & operator[](int index);
	void Add(T data);
	void Append(Array &obj);
	Array<T> &operator= (const Array &obj);
	T** GetData();
	void InsertAt(int position, T data);
	void RemoveAt(int position);
	void Show();
};

#pragma once
#include "Array.h"

template <typename T>
Array<T>::Array()
{
	mCounter = 0;
	mSize = 0;
	mGrow = 1;
	mData = NULL;
}

template <typename T>
Array<T>::~Array()
{
	if (mData) free(mData);
	mData = NULL;
}

template <typename T>
int Array<T>::GetSize()
{
	return mSize;
}

template <typename T>
void Array<T>::SetSize(unsigned int size, int grow = 1)
{
	mGrow = grow;

	if (size == mSize){
		return;
	}

	mSize = size;

	if (mSize>0)
	{
		if (mSize%mGrow != 0)
		{
			mData = (T*)realloc(mData, sizeof(T)*(mSize + (grow - mSize%grow)));
		}
		else if (mSize%mGrow == 0)
		{
			mData = (T*)realloc(mData, sizeof(T)*mSize);
		}
	}

	if (mCounter>mSize)
	{
		mCounter = mSize;
	}
}

template <typename T>
int Array<T>::GetUpperBound()
{
	return mCounter - 1;
}

template <typename T>
bool Array<T>::isEmpty()
{
	if (mCounter == 0) return true;
	else return false;
}

template <typename T>
void Array<T>::FreeExtra()
{
	if (mSize%mGrow != 0)
	{
		mData = (T*)realloc(mData, sizeof(T)*(mCounter + (mGrow - mCounter%mGrow)));;
		mSize = mCounter + (mGrow - mCounter%mGrow);
	}
	else if (mSize%mGrow == 0)
	{
		mData = (T*)realloc(mData, sizeof(T)*mCounter);
		mSize = mCounter;
	}
}

template <typename T>
void Array<T>::removeAll()
{
	free(mData);
	mData = NULL;
	mCounter = 0;
	mSize = 0;
}

template <typename T>
T Array<T>::GetAt(int index)
{
	if (index >= 0 && index<mCounter) return mData[index];
}

template <typename T>
void Array<T>::SetAt(int index, T data)
{
	if (index >= 0 && index<mSize)
	{
		mData[index] = data;
		mCounter = index + 1;
	}
}

template <typename T>
T & Array<T>::operator[](int index)
{
	if (index >= 0 && index<mCounter) return mData[index];
}

template <typename T>
void Array<T>::Add(T data)
{
	if (mCounter<mSize)
	{
		mData[mCounter++] = data;
	}
	else if (mCounter >= mSize)
	{
		SetSize(mSize + 1);
		mData[mSize - 1] = data;
		mCounter++;
	}
}

template <typename T>
void Array<T>::Append(Array &obj){
	int maxCounter = this->GetUpperBound()>obj.GetUpperBound() ? this->GetUpperBound() + 1 : obj.GetUpperBound() + 1;
	int minCounter = this->GetUpperBound()<obj.GetUpperBound() ? this->GetUpperBound() + 1 : obj.GetUpperBound() + 1;
	this->SetSize(maxCounter, mGrow);

	for (int i = 0; i<minCounter; i++)
	{
		mData[i] = mData[i] + obj[i];
	}
}

template <typename T>
Array<T> & Array<T>::operator= (const Array &obj)
{
	if (this == &obj) return *this;

	mGrow = obj.mGrow;
	mCounter = obj.mCounter;
	mSize = obj.mSize;

	mData = (T*)realloc(mData, sizeof(T)*(mSize + (mGrow - mSize%mGrow)));

	for (int i = 0; i<mCounter; i++)
	{
		mData[i] = obj.mData[i];
	}

	return *this;
}

template <typename T>
T** Array<T>::GetData()
{
	return &mData;
}

template <typename T>
void Array<T>::InsertAt(int position, T data)
{
	if (position<0 || position >= mCounter)
	{
		return;
	}

	if (mCounter >= mSize)
	{
		SetSize(mSize + 1);
	}

	for (int i = mCounter; i >= position; i--)
	{
		mData[i] = mData[i - 1];
	}

	mData[position] = data;
	mCounter++;
}

template <typename T>
void Array<T>::RemoveAt(int position)
{
	if (position<0 || position >= mCounter)
	{
		return;
	}

	for (int i = position; i<mCounter; i++)
	{
		mData[i] = mData[i + 1];
	}

	mCounter--;
}

template <typename T>
void Array<T>::Show()
{
	for (int i = 0; i<mCounter; i++)
	{
		cout << mData[i] << " ";
	}

	cout << endl << endl;
}


int main(){

	setlocale(0, "");
	system("mode con cols=70 lines=70");
	Array<int> test;

	cout << "метод \"GetSize\":\n";
	cout << test.GetSize() << endl << endl;

	test.Add(1);
	test.Add(2);
	test.Add(3);
	cout << "метод \"Add\":\n";
	test.Show();

	cout << "метод \"GetUpperBound\":\n";
	cout << test.GetUpperBound() << endl << endl;

	cout << "метод \"IsEmpty\":\n";
	cout << test.isEmpty() << endl << endl;

	cout << "метод \"GetSize\" (показываем количество элементов массива, под которые выделена память):\n";
	cout << test.GetSize() << endl << endl;

	test.SetSize(5);
	cout << "метод \"SetSize\" (устанавилваем размер равнывй 5):\n";
	cout << test.GetSize() << endl << endl;

	test.SetAt(3, 4);
	test.SetAt(4, 5);
	cout << "метод \"SetAt\" (устанавилваем значение 4 и 5):\n";
	test.Show();

	cout << "метод \"FreeExtra\" (устанавливаем размер 10, используем фри экстра):\n";
	test.SetSize(10);
	test.FreeExtra();
	cout << test.GetSize() << endl << endl;

	cout << "метод \"GetAt\" (Получаем значение 3-го элемента):\n";
	cout << test.GetAt(2) << endl << endl;

	cout << "метод \"operator[]\" (Получаем значение 3-го элемента):\n";
	cout << test[2] << endl << endl;

	Array<int> test2;
	test2 = test;
	cout << "метод \"operator=\" (создали второй массив и приравняли первому.)\n";
	test2.Show();

	cout << "метод \"GetData\" (Получаем адрес массива):\n";
	cout << test.GetData() << endl << endl;

	cout << "метод \"Append\" (Прибавили к первому массиву второй):\n";
	test.Append(test2);
	test.Show();

	cout << "метод \"InsertAt\" (Вставили во вторую позицию цифру 256):\n";
	test.InsertAt(2, 256);
	test.Show();

	cout << "метод \"RemoveAt\" (Убрали со второй позиции цифру 256):\n";
	test.RemoveAt(2);
	test.Show();

	return 0;
}