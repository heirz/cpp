#include <iostream>
#include <windows.h>
#include "menu.cpp"
#include <string.h>
using namespace std;

struct node
{
	unsigned int nom;
	char narushenie[150];
	node *parent, *left, *right;
};

class gai
{
private:
	node *root;
	int k;
public:
	gai()
	{
		root = NULL;
		k = 0;
	}

	~gai()
	{
		delall(root);
	}

	void delall(node *tmp)
	{


		if (tmp->left != NULL)
			delall(tmp->left);
		if (tmp->right != NULL)
			delall(tmp->right);
		delete tmp;

		k = 0;

	}

	node* serch(unsigned int nom, node *tmp)
	{

		while ((tmp != NULL) && (tmp->nom != nom))
		{
			if (nom>tmp->nom)
				tmp = tmp->left;
			else if (nom<tmp->nom)
				tmp = tmp->right;
		}
		return tmp;


	}

	void add()
	{
		node *elem = new node;
		node *tmp = new node;
		node *tmp2 = new node;
		elem->right = NULL;
		elem->left = NULL;
		cout << "vvedite nomer avto:\n";
		cin >> elem->nom;
		cout << "vvedite narushenie:\n";
		cin >> elem->narushenie;

		if (serch(elem->nom, root) != NULL)
		{
			int n = 0;
			char p[150];
			n = elem->nom;
			strcpy(p, elem->narushenie);
			serch(n, root)->nom = n;
			strcpy(serch(n, root)->narushenie, p);
		}
		else
		{
			if (root == NULL)
			{
				elem->parent = NULL;
				root = elem;

			}
			else
			{
				tmp = root;
				tmp2 = NULL;
				while (tmp != NULL)
				{
					tmp2 = tmp;
					if (elem->nom>tmp->nom)
						tmp = tmp->right;
					else
						tmp = tmp->left;
				}
				elem->parent = tmp2;
				if (elem->nom>tmp2->nom)
					tmp2->right = elem;
				else
					tmp2->left = elem;
			}
		}
		k++;
	}

	void print(node *tmp)
	{
		if (tmp != NULL)
		{
			if (k != 0)
			{
				cout << tmp->nom << "\t" << tmp->narushenie << "\n";
				if (tmp->left != NULL)
					print(tmp->left);
				if (tmp->right != NULL)
					print(tmp->right);
			}
			else
				cout << "baza narusheniy!\n";
		}

	}

	void diapazon(int l1, int l2, node *tmp)
	{

		if (tmp != NULL)
		{
			if (k != 0)
			{
				if ((tmp->nom>l1) && (tmp->nom<l2))
					cout << tmp->nom << "\t" << tmp->narushenie << "\n";
				if (tmp->left != NULL)
					diapazon(l1, l2, tmp->left);
				if (tmp->right != NULL)
					diapazon(l1, l2, tmp->right);
			}

		}
	}

	node*getroot()
	{
		return root;
	}

};



int main()
{

	gai G;
	int l1 = 0, l2 = 0, flag = 0;
	while (1)
	{
		flag = menu(6, "vyhod", "dobavit", "pechat bazy", "poisk", "pechat diapazona", "udalit bazu");
		switch (flag)
		{
		case 0:
		{
			system("cls");
			exit(0);
			system("cls");
		}
		break;
		case 1:
		{
			system("cls");
			G.add();
			system("cls");
		}
		break;
		case 2:
		{
			system("cls");
			cout << "baza:\n";
			G.print(G.getroot());
		}
		break;
		case 3:
		{
			system("cls");
			cout << "vvedite nomer:\n";
			cin >> l1;
			system("cls");
			if (G.serch(l1, G.getroot()) != NULL)
				cout << "naydeno\n" << G.serch(l1, G.getroot())->nom << "\t" << G.serch(l1, G.getroot())->narushenie << "\n";
			else
				cout << "ne naydeno!\n";

		}
		break;
		case 4:
		{
			system("cls");
			cout << "vvedite diapazon ( vid x do y ):\n";
			cin >> l1 >> l2;
			system("cls");
			G.diapazon(l1, l2, G.getroot());
		}
		break;
		case 5:
		{
			system("cls");
			G.delall(G.getroot());
		}
		break;
		}
	}



	return 0;
}
