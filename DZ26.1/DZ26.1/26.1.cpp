

#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

const int max_elements = 15;

class Cgame
{
private:
	int **mas;
	int put, get, count;
	int size;

public:
	Cgame()
	{
		int mas_chip[max_elements] = { 1, 2, 14, 16, 36 };
		count = 10;
		get = NULL;
		size = 5;
		mas = new int*[3];
		for (int i(0); i < 3; i++)
			mas[i] = new int[size];
		for (int i(0); i < 3; i++)
			for (put = 0; put < size; put++)
				put_mas(i, put, mas_chip);
	}
	
	void put_mas(int i, int put, int *mas_chip)
	{
		mas[i][put] = mas_chip[put];
	}

	
	void get_mas(Cgame &A)
	{
		for (int i(0); i < 3; i++, cout << endl)
			for (int j(0); j < 3; j++)
				cout << (char)mas[j][i] << " ";
	}
	
	void play_game()
	{
		for (int i(0); i < (3 + rand() % 3); i++)
			for (int j(put - 1), tmp1 = mas[0][put - 1]; j > 0; j--)
			{
				mas[0][j] = mas[0][j - 1];
				if (j == 1)
					mas[0][get] = tmp1;
			}

		for (int i(0); i < (3 + rand() % 3); i++)
			for (int j(put - 1), tmp1 = mas[1][put - 1]; j > 0; j--)
			{
				mas[1][j] = mas[1][j - 1];
				if (j == 1)
					mas[1][get] = tmp1;
			}

		for (int i(0); i < (3 + rand() % 3); i++)
			for (int j(put - 1), tmp1 = mas[2][put - 1]; j > 0; j--)
			{
				mas[2][j] = mas[2][j - 1];
				if (j == 1)
					mas[2][get] = tmp1;
			}

		switch (true)
		{
		case (1) : if ((mas[0][1] == mas[1][1]) && (mas[1][1] == mas[2][1]))
		{
			count += 3;
			break;
		}
		case (2) : if ((mas[0][1] == mas[1][1]) || (mas[1][1] == mas[2][1]))
		{
			count += 1;
			break;
		}
		case (3) : count -= 3;
			break;
		}
	}

	int calculation()
	{
		return count;
	}


	//----------------------------------------
	~Cgame()
	{
		for (int i = 0; i < 3; i++)
			delete[] mas[i];
		delete[] mas;
		cout << "\ndel\n";
	}
};



bool main()
{
	double start_time = clock();
	Cgame A;
	srand(time(NULL));
	while (true)
	{
		A.play_game();
		cout << endl << endl;
		A.get_mas(A);
		cout << endl << "your points is: " << A.calculation() << endl << endl;

		double end_time = clock();
		double search_time = end_time - start_time;
		cout << "time of execution: " << search_time / 1000 << endl;

		if (A.calculation() <= 0)
		{
			cout << "\n---game over---\n";
			return false;
		}

		system("pause");
		system("cls");
	}
}