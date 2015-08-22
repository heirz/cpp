#include<iostream>
using namespace std;

class Array_Overflow
{
private:
	int*array_data;
	int size_array;

	void Incriment_size_array();
	void Dicriment_size_array();

public:
	Array_Overflow();
	Array_Overflow(Array_Overflow& object);
	~Array_Overflow();

	int Get_Size_Arrey();
	void Schow_Array();

	int& operator[](int interation_number);
	Array_Overflow& operator =(const Array_Overflow& object);
	Array_Overflow& operator +(const Array_Overflow& object);
	Array_Overflow& operator -(const Array_Overflow& object);
	Array_Overflow& operator ++();
	Array_Overflow& operator --();

	void Inicial_Array(int start, ...);
};


//Конструктор по умолчанию
Array_Overflow::Array_Overflow()
{
	cout << "Введите количиство елементов вашего массива : ";
	int temp_size = 0;
	cin >> temp_size;

	if (temp_size>0)
	{
		array_data = new int[temp_size];
		size_array = temp_size;
	}

	else { cout << "Ошибка границ массива (неверно заданна размерность массива при создании)"; }

	cout << endl;


}

//Конструктор копии
Array_Overflow::Array_Overflow(Array_Overflow& object)
{

}

//Деструктор
Array_Overflow :: ~Array_Overflow()
{
	delete[] array_data;
}


int& Array_Overflow :: operator[](int interation_number)
{
	return array_data[interation_number];
}

Array_Overflow& Array_Overflow :: operator = (const Array_Overflow& object)
{
	for (int i = 0; i< size_array; i++)
	{
		array_data[i] = object.array_data[i];

	}
	return *this;
}

Array_Overflow& Array_Overflow :: operator +(const Array_Overflow& object)
{
	for (int i = 0; i< size_array; i++)
	{
		array_data[i] += object.array_data[i];

	}
	return *this;
}

Array_Overflow& Array_Overflow :: operator -(const Array_Overflow& object)
{
	for (int i = 0; i< size_array; i++)
	{
		array_data[i] -= object.array_data[i];

	}
	return *this;
}

//Получение размерности
int Array_Overflow::Get_Size_Arrey()
{
	return size_array;
}

//Показ массива
void Array_Overflow::Schow_Array()
{
	cout << "Ваш массив начало -> ";

	for (int i = 0; i<size_array; i++)
	{
		if (i == size_array - 1) { cout << array_data[i] << " <- конец ;"; }
		else{ cout << array_data[i] << ", "; }
	}

	cout << endl;
}

void Array_Overflow::Incriment_size_array()
{


	int *temp = new int[size_array + 1];

	for (int i = 0; i<size_array; i++)
	{
		temp[i] = array_data[i];
	}
	array_data = NULL;
	delete[] array_data;

	array_data = temp;
	size_array++;
}
void Array_Overflow::Dicriment_size_array()
{
	int *temp = new int[size_array - 1];

	for (int i = 0; i<size_array - 1; i++)
	{
		temp[i] = array_data[i];
	}
	array_data = NULL;
	delete[] array_data;

	array_data = temp;
	size_array--;

}

Array_Overflow& Array_Overflow :: operator ++()
{

	int temp_value = NULL;
	cout << "Введите значение которое хотите добавить : ";
	cin >> temp_value;
	cout << endl;

	Incriment_size_array();
	array_data[size_array - 1] = temp_value;

	return *this;
}

Array_Overflow& Array_Overflow :: operator --()
{
	Dicriment_size_array();
	return *this;
}

void Array_Overflow::Inicial_Array(int start, ...)
{
	int count = 0;

	int *pointer = &start;
	for (; *pointer;)
	{
		count++; pointer++;
	}

	if (size_array >= count)
	{
		pointer = &start;
		for (int i = 0; i<count; i++)
		{
			array_data[i] = (*pointer); pointer++;
		}
	}

	else { cout << "Ошибка границы пассива (количиство елементов превышает норму )" << endl; }

}



void main()
{
	setlocale(LC_ALL, "Russian");


	Array_Overflow mass;

	mass.Inicial_Array(12, 34, 31, 54, 67, 32, 89, 43, 21, 0);
	mass.Schow_Array();

	mass++;
	mass.Schow_Array();

	mass--;
	mass.Schow_Array();

}