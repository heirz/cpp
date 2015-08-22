#include <iostream>
#include <stdio.h>
#include "menu.cpp"
#include <string.h>
#include <io.h>
#include <windows.h>
using namespace std;

struct node
{
	char fam[20];
	unsigned int tel;
	node *next;
};

class baza
{
private:
	node *head;
	node *tail;
	int Count;
public:
	baza()
	{
		head = tail = NULL;
		Count = 0;
	}

	~baza()
	{
		delall();
	}

	void add()
	{
		node *elem = new node;
		cout << "vvedit familiyu abonenta:\n";
		cin >> elem->fam;
		cout << "vvedit nomer abonenta:\n";
		cin >> elem->tel;
		elem->next = NULL;
		if (head != NULL)
		{
			tail->next = elem;
			tail = elem;
		}
		else
		{
			head = tail = elem;
		}
		Count++;

	}

	void del(const int poz)
	{
		if ((poz>-1) && (poz<Count))
		{
			node *tmp = new node;
			node *tmp2 = new node;
			tmp = head;
			tmp2 = NULL;
			for (int i = 0; i<poz; i++)
			{
				tmp2 = tmp;
				tmp = tmp->next;
			}
			tmp2->next = tmp->next;
			delete tmp;
			Count--;
		}
	}

	void delall()
	{
		node *tmp = new node;
		tmp = head;

		while (head != NULL)
		{
			tmp = head;
			head = head->next;
			delete tmp;
		}
		Count = 0;
	}

	void mod(const int poz)
	{
		if ((poz>-1) && (poz<Count))
		{
			node *tmp = new node;
			tmp = head;
			for (int i = 0; i<poz; i++)
			{
				tmp = tmp->next;
			}
			cout << "vveditde nov familiyu:\n";
			cin >> tmp->fam;
			cout << "vvedit nov telefon:\n";
			cin >> tmp->tel;
		}
	}

	bool p(char*s, char*s1)
	{
		if (strlen(s) != strlen(s1))
			return false;
		else
		{
			for (int i = 0; i<strlen(s); i++)
			{
				if (s[i] != s1[i])
					return false;
			}
			return true;
		}
	}

	void serch()
	{
		int flg = 0, tl = 0;
		char s[20];

		node *tmp = new node;
		tmp = head;
		cout << "po chemu bazhajete provesty poisk?\n";
		flg = menu(2, "nomer telefona", "familiya");
		if (flg == 0)
		{
			cout << "vvedit nomer telefona:\n";
			cin >> tl;
			while (tmp != NULL)
			{
				if (tmp->tel == tl)
					cout << tmp->fam << "\t" << tmp->tel << "\n";
				tmp = tmp->next;
			}
		}
		else
		{
			cout << "vvedit familiyu:\n";
			cin >> s;

			while (tmp != NULL)
			{
				if (p(tmp->fam, s))
					cout << tmp->fam << "\t" << tmp->tel << "\n";
				tmp = tmp->next;
			}
		}
	}

	void pris(char* a, char* b)
	{
		int i = 0;
		for (i; i<strlen(b); i++)
		{
			a[i] = b[i];
		}
		a[i] = '\0';
	}

	void sorter()
	{
		node *tmp = new node;
		char z, z1, m[20];

		int buf = 0;
		for (int i = 0; i<Count; i++)
		{
			tmp = head;
			while (tmp->next != NULL)
			{
				z = tmp->fam[0];
				z1 = tmp->next->fam[0];
				if (z>z1)
				{
					buf = tmp->tel;
					pris(m, tmp->fam);


					tmp->tel = tmp->next->tel;
					pris(tmp->fam, tmp->next->fam);

					tmp->next->tel = buf;
					pris(tmp->next->fam, m);
				}
				tmp = tmp->next;

			}
		}
	}


	void diapazon()
	{
		int fl = 0, tl = 0, x = 0, y = 0, lm = 0, p = 0, flg1 = 0;
		char s[20], l1[20], l2[20], s1, s2, sp[20];
		node *tmp = new node;
		FILE *f;
		tmp = head;
		cout << "bazhajete potom rezyltaty sohranit v udalit?\n";
		flg1 = menu(2, "da", "net");
		cout << "po chemu bazhajete vyvesty diapazon?\n";
		fl = menu(2, "telefon", "familiya");
		if (fl == 0)
		{
			cout << "vvedite promizutok nomerov (ot x do y):\n";
			cin >> x >> y;
			if (flg1 == 0)
				f = fopen("search.txt", "a");
			while (tmp != NULL)
			{
				if ((tmp->tel>x) && (tmp->tel<y))
				{
					cout << tmp->fam << "\t" << tmp->tel << "\n";
					if (flg1 == 0)
						fwrite(tmp, sizeof(node), Count, f);
				}
				tmp = tmp->next;

			}

		}
		else
		{
			cout << "vvedite promizhok nomerov (ot x do y):\n";
			cin >> l1 >> l2;

			if (strlen(l1)<strlen(l2))
			{
				lm = strlen(l1);
			}
			else
			{
				lm = strlen(l2);
			}
			for (int i = 0; i<lm; i++)
			{
				if (l1[i] != l2[i])
				{
					s1 = l1[i];
					s2 = l2[i];
					p = i;
					break;
				}
				else
				{
					sp[i] = l1[i];
				}
			}
			while (tmp != NULL)
			{
				if ((strnicmp(tmp->fam, sp, p - 1) == 0) && (tmp->fam[p]>s1) && (tmp->fam[p]<s2))
				{
					cout << tmp->fam << "\t" << tmp->tel << "\n";
					if (flg1 == 0)
						fwrite(tmp, sizeof(node), Count, f);
				}
				tmp = tmp->next;
			}
		}
		if (flg1 == 0)
			fclose(f);
	}

	void savetofile()
	{
		FILE *f;
		node *tmp = new node;
		f = fopen("baza.txt", "a");
		tmp = head;
		while (tmp != NULL)
		{
			fwrite(tmp, sizeof(node), Count, f);
			tmp = tmp->next;
		}
		fclose(f);
	}

	void loadfromfile()
	{
		bool first = true;
		if (!_access("baza.txt", 00))
		{
			FILE *f;
			f = fopen("baza.txt", "r+");


			while (!feof(f))
			{
				node *elem = new node;

				if (first)
				{
					head = elem;
					tail = elem;
					first = false;
				}
				else
				{
					tail->next = elem;
				}

				fread(elem, sizeof(node), 1, f);
				tail = elem;

			}
			tail->next = NULL;
			fclose(f);
		}
	}

	void print()
	{

		node *tmp = new node;
		tmp = head;
		if (this->Count != 0)
		{
			sorter();
			while (tmp != NULL)
			{
				cout << tmp->fam << "\t" << tmp->tel << "\n";
				tmp = tmp->next;
			}
		}
		else
			cout << "baza udalena\n";


	}

};

int main()
{
	int flag = 0, pt = 0;
	baza bz;
	while (1)
	{
		flag = menu(10, "vyhod", "dovit", "vydeliti element po pozicii", "modyfikaty", "poisk", "pechat diapazona", "pechat bazy", "sohranit bazu", "izmenit bazu", "udalit bazu");
		switch (flag)
		{
		case 0:
		{
			exit(0);
		}
		break;
		case 1:
		{
			system("cls");
			bz.add();
			system("cls");
		}
		break;
		case 2:
		{
			system("cls");
			cout << "vvedit pozyciu elementa\n";
			cin >> pt;
			bz.del(pt);
			system("cls");
		}
		break;
		case 3:
		{
			system("cls");
			cout << "vvedit pozyciu elementa\n";
			cin >> pt;
			bz.mod(pt);
			system("cls");
		}
		break;
		case 4:
		{
			system("cls");
			bz.serch();
		}
		break;
		case 5:
		{
			system("cls");
			bz.sorter();
			bz.diapazon();
		}
		break;
		case 6:
		{
			system("cls");

			bz.print();
		}
		break;
		case 7:
		{
			system("cls");
			bz.savetofile();
		}
		break;
		case 8:
		{
			system("cls");
			bz.loadfromfile();
		}
		break;
		case 9:
		{
			system("cls");
			bz.delall();
		}
		break;
		}
	}

	return 0;
}
