#include "stdafx.h"
#include <windows.h> 
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
class QueuePriority
{
	// Очередь
	int * Wait;
	int * Pri;
	int MaxQueueLength;            // Максимальный размер очереди
	int QueueLength;            // Текущий размер очереди
public:
	QueuePriority(int m);        // Конструктор
	~QueuePriority();            // Деструктор
	void Add(int c, int p);        // Добавление элемента
	int Extract();                // Извлечение элемента      
	void Clear();                // Очистка очереди   
	bool IsEmpty();                // Проверка существования элементов в очереди
	bool IsFull();                // Проверка на переполнение очереди  
	int GetCount();                // Количество элементов в очереди
	void Show();                //демонстрация очереди
	void sort();
	int PassengerComing(double Coming);
};
class QueueStat
{
	// Очередь
	time_t *InTimeArray;
	time_t *OutTimeArray;
	int MaxQueueLength;            // Максимальный размер очереди
	int QueueLength;            // Текущий размер очереди
public:
	QueueStat(int m);        // Конструктор
	~QueueStat();            // Деструктор
	void Add(time_t InTime, time_t OutTime);        // Добавление элемента
	double Extract();                // Извлечение элемента      
	void Clear();                // Очистка очереди   
	bool IsEmpty();                // Проверка существования элементов в очереди
	bool IsFull();                // Проверка на переполнение очереди  
	int GetCount();                // Количество элементов в очереди
	void Show();                //демонстрация очереди
};
void QueueStat::Show()
{
	//демонстрация очереди
	char InT[26];
	char OutT[26];
	cout << "Processed:\n";
	for (int i = 0; i<QueueLength; i++)
	{
		strncpy(InT, ctime(&InTimeArray[i]), 25);
		InT[25] = '\0';
		strncpy(OutT, ctime(&OutTimeArray[i]), 25);
		OutT[25] = '\0';
		cout << "In Time:  " << InT\
			<< "Out Time: " << OutT\
			<< "processing, sec: " << difftime(OutTimeArray[i], InTimeArray[i]) << "\n";
	}
	cout << "-------------------------------------\n";
}
QueueStat::~QueueStat()
{
	//удаление очереди
	delete[]InTimeArray;
	delete[]OutTimeArray;
}
QueueStat::QueueStat(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	InTimeArray = new time_t[MaxQueueLength];
	OutTimeArray = new time_t[MaxQueueLength];
	// Изначально очередь пуста
	QueueLength = 0;
}
void QueueStat::Clear()
{
	// очистка очереди 
	QueueLength = 0;
}
bool QueueStat::IsEmpty()
{
	// Пуст?
	return QueueLength == 0;
}
bool QueueStat::IsFull()
{
	// Полон?
	return QueueLength == MaxQueueLength;
}
int QueueStat::GetCount()
{
	// Количество присутствующих в стеке элементов
	return QueueLength;
}
void QueueStat::Add(time_t InTime, time_t OutTime)
{
	// Если в очереди есть место, то увеличиваем количество
	// значений и вставляем новый элемент
	if (!IsFull())
	{
		InTimeArray[QueueLength] = InTime;
		OutTimeArray[QueueLength] = OutTime;
		QueueLength++;
	}
}
double QueueStat::Extract()
{
	if (!IsEmpty())
	{
		QueueLength--;
		// возврат извлеченного элемента    
		return difftime(OutTimeArray[QueueLength], InTimeArray[QueueLength]);
	}
	else return -1;
}
void QueuePriority::Show()
{
	int S;
	//демонстрация очереди
	for (int i = 0; i<QueueLength; i++)
	{

		if (Wait[i] == Wait[i + 1] && Pri[i]<Pri[i + 1])
		{
			S = Pri[i];
			Pri[i] = Pri[i + 1];
			Pri[i + 1] = S;
		}
	}
	for (int i = 0; i<QueueLength; i++)
	{
		cout << Wait[i] << " - " << Pri[i] << "\n";
	}
	cout << "-------------------------------------\n";
}
QueuePriority::~QueuePriority()
{
	//удаление очереди
	delete[]Wait;
	delete[]Pri;
}
QueuePriority::QueuePriority(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new int[MaxQueueLength];
	Pri = new int[MaxQueueLength];
	// Изначально очередь пуста
	QueueLength = 0;
}
void QueuePriority::Clear()
{
	// очистка очереди 
	QueueLength = 0;
}
bool QueuePriority::IsEmpty()
{
	// Пуст?
	return QueueLength == 0;
}
bool QueuePriority::IsFull()
{
	// Полон?
	return QueueLength == MaxQueueLength;
}
int QueuePriority::GetCount()
{
	// Количество присутствующих в стеке элементов
	return QueueLength;
}
int QueuePriority::PassengerComing(double Coming)
{
	double time = 0;
	// Используется экспоненциальный закон распределения вероятности
	time = ceil(-Coming * 60 * log(1 - (double)rand() / (RAND_MAX + 1)));
	return (int)time;
}
void QueuePriority::Add(int c, int p)//p=время простоя принтера
{
	// Если в очереди есть место, то увеличиваем количество
	// значений и вставляем новый элемент
	p = PassengerComing(1);
	if (!IsFull())
	{
		Wait[QueueLength] = c;
		Pri[QueueLength] = p;
		QueueLength++;
	}
}
int QueuePriority::Extract()
{
	// Если в очереди есть элементы, то возвращаем тот, 
	// который вошел первым и сдвигаем очередь    
	if (!IsEmpty())
	{
		//пусть приоритетный элемент - нулевой
		int max_pri = Pri[0];
		//а приоритетный индекс = 0
		int pos_max_pri = 0;
		//ищем приоритет
		for (int i = 1; i<QueueLength; i++)
			//если встречен более приоритетный элемент
			if (max_pri<Pri[i] && i++>i){
				max_pri = Pri[i];
				pos_max_pri = i;
			}
		//вытаскиваем приоритетный элемент
		int temp1 = Wait[pos_max_pri];
		int temp2 = Pri[pos_max_pri];
		//сдвинуть все элементы
		for (int i = pos_max_pri; i<QueueLength - 1; i++)
		{
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		//уменьшаем количество
		QueueLength--;
		// возврат извлеченного элемента    
		return temp1;
	}
	else return -1;
}
void QueuePriority::sort()
{
	int max, temp, temp2;
	for (int i = 0; i<QueueLength - 1; i++)
	{
		max = i;
		for (int j = i + 1; j<QueueLength; j++)
		{
			if (Wait[j]>Wait[max])
				max = j;
		}
		if (max == i)
			continue;
		temp = Pri[i];
		Pri[i] = Pri[max];
		Pri[max] = temp;
		temp2 = Wait[i];
		Wait[i] = Wait[max];
		Wait[max] = temp2;
	}
}
void main()
{
	time_t CurTime;
	srand(time(0));
	QueuePriority QUP(25);        //создание очереди
	QueueStat Stat(25);
	for (int i = 0; i<5; i++){
		QUP.Add(rand() % 5 + 1, 0);
	}

	QUP.sort();                    //сортировка элементов
	QUP.Show();                    //показ очереди

	for (int i = 0; i<5; i++){
		CurTime = time(NULL);
		Sleep(QUP.Extract() * 1000);    //извлечение элемента
		Stat.Add(CurTime, time(NULL));
		QUP.Show();                    //показ очереди
		Stat.Show();
	}