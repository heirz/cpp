#include "stdafx.h"
#include <windows.h> 
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
class QueuePriority
{
	// �������
	int * Wait;
	int * Pri;
	int MaxQueueLength;            // ������������ ������ �������
	int QueueLength;            // ������� ������ �������
public:
	QueuePriority(int m);        // �����������
	~QueuePriority();            // ����������
	void Add(int c, int p);        // ���������� ��������
	int Extract();                // ���������� ��������      
	void Clear();                // ������� �������   
	bool IsEmpty();                // �������� ������������� ��������� � �������
	bool IsFull();                // �������� �� ������������ �������  
	int GetCount();                // ���������� ��������� � �������
	void Show();                //������������ �������
	void sort();
	int PassengerComing(double Coming);
};
class QueueStat
{
	// �������
	time_t *InTimeArray;
	time_t *OutTimeArray;
	int MaxQueueLength;            // ������������ ������ �������
	int QueueLength;            // ������� ������ �������
public:
	QueueStat(int m);        // �����������
	~QueueStat();            // ����������
	void Add(time_t InTime, time_t OutTime);        // ���������� ��������
	double Extract();                // ���������� ��������      
	void Clear();                // ������� �������   
	bool IsEmpty();                // �������� ������������� ��������� � �������
	bool IsFull();                // �������� �� ������������ �������  
	int GetCount();                // ���������� ��������� � �������
	void Show();                //������������ �������
};
void QueueStat::Show()
{
	//������������ �������
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
	//�������� �������
	delete[]InTimeArray;
	delete[]OutTimeArray;
}
QueueStat::QueueStat(int m)
{
	//�������� ������
	MaxQueueLength = m;
	//������� �������
	InTimeArray = new time_t[MaxQueueLength];
	OutTimeArray = new time_t[MaxQueueLength];
	// ���������� ������� �����
	QueueLength = 0;
}
void QueueStat::Clear()
{
	// ������� ������� 
	QueueLength = 0;
}
bool QueueStat::IsEmpty()
{
	// ����?
	return QueueLength == 0;
}
bool QueueStat::IsFull()
{
	// �����?
	return QueueLength == MaxQueueLength;
}
int QueueStat::GetCount()
{
	// ���������� �������������� � ����� ���������
	return QueueLength;
}
void QueueStat::Add(time_t InTime, time_t OutTime)
{
	// ���� � ������� ���� �����, �� ����������� ����������
	// �������� � ��������� ����� �������
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
		// ������� ������������ ��������    
		return difftime(OutTimeArray[QueueLength], InTimeArray[QueueLength]);
	}
	else return -1;
}
void QueuePriority::Show()
{
	int S;
	//������������ �������
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
	//�������� �������
	delete[]Wait;
	delete[]Pri;
}
QueuePriority::QueuePriority(int m)
{
	//�������� ������
	MaxQueueLength = m;
	//������� �������
	Wait = new int[MaxQueueLength];
	Pri = new int[MaxQueueLength];
	// ���������� ������� �����
	QueueLength = 0;
}
void QueuePriority::Clear()
{
	// ������� ������� 
	QueueLength = 0;
}
bool QueuePriority::IsEmpty()
{
	// ����?
	return QueueLength == 0;
}
bool QueuePriority::IsFull()
{
	// �����?
	return QueueLength == MaxQueueLength;
}
int QueuePriority::GetCount()
{
	// ���������� �������������� � ����� ���������
	return QueueLength;
}
int QueuePriority::PassengerComing(double Coming)
{
	double time = 0;
	// ������������ ���������������� ����� ������������� �����������
	time = ceil(-Coming * 60 * log(1 - (double)rand() / (RAND_MAX + 1)));
	return (int)time;
}
void QueuePriority::Add(int c, int p)//p=����� ������� ��������
{
	// ���� � ������� ���� �����, �� ����������� ����������
	// �������� � ��������� ����� �������
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
	// ���� � ������� ���� ��������, �� ���������� ���, 
	// ������� ����� ������ � �������� �������    
	if (!IsEmpty())
	{
		//����� ������������ ������� - �������
		int max_pri = Pri[0];
		//� ������������ ������ = 0
		int pos_max_pri = 0;
		//���� ���������
		for (int i = 1; i<QueueLength; i++)
			//���� �������� ����� ������������ �������
			if (max_pri<Pri[i] && i++>i){
				max_pri = Pri[i];
				pos_max_pri = i;
			}
		//����������� ������������ �������
		int temp1 = Wait[pos_max_pri];
		int temp2 = Pri[pos_max_pri];
		//�������� ��� ��������
		for (int i = pos_max_pri; i<QueueLength - 1; i++)
		{
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		//��������� ����������
		QueueLength--;
		// ������� ������������ ��������    
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
	QueuePriority QUP(25);        //�������� �������
	QueueStat Stat(25);
	for (int i = 0; i<5; i++){
		QUP.Add(rand() % 5 + 1, 0);
	}

	QUP.sort();                    //���������� ���������
	QUP.Show();                    //����� �������

	for (int i = 0; i<5; i++){
		CurTime = time(NULL);
		Sleep(QUP.Extract() * 1000);    //���������� ��������
		Stat.Add(CurTime, time(NULL));
		QUP.Show();                    //����� �������
		Stat.Show();
	}