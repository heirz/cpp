#include <iostream>
using namespace std;

struct Element
{
	// Данные
	char data;
	// Адрес следующего элемента списка
	Element * Next;
};

// Односвязный список
class List
{
	// Адрес головного элемента списка
	Element * Head;
	// Адрес головного элемента списка
	Element * Tail;
	// Количество элементов списка
	int Count;

public:
	// Конструктор
	List();
	// Деструктор
	~List();

	// Добавление элемента в список
	// (Новый элемент становится последним)
	void Add(char data);

	// Удаление элемента списка
	// (Удаляется головной элемент)
	void Del();
	// Удаление всего списка
	void DelAll();

	// Распечатка содержимого списка
	// (Распечатка начинается с головного элемента)
	void Print();

	// Получение количества элементов, находящихся в списке
	int GetCount();

	//вставка элемента в заданную позицию.
	bool insert(int position, char data);
	//Удаление элемента по заданной позиции.
	void erase(int position);
	//поиск i-го элемента.
	int search(char data);
};

List::List()
{
	// Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// Вызов функции удаления
	DelAll();
}

int List::GetCount()
{
	// Возвращаем количество элементов
	return Count;
}

void List::Add(char data)
{
	// создание нового элемента
	Element * temp = new Element;

	// заполнение данными
	temp->data = data;
	// следующий элемент отсутствует
	temp->Next = NULL;
	// новый элемент становится последним элементом списка
	// если он не первый добавленный
	if (Head != NULL){
		Tail->Next = temp;
		Tail = temp;
	}
	// новый элемент становится единственным
	// если он первый добавленный
	else{
		Head = Tail = temp;
	}

	Count++;
}

void List::Del()
{
	// запоминаем адрес головного элемента
	Element * temp = Head;
	// перебрасываем голову на следующий элемент
	Head = Head->Next;
	// удаляем бывший головной элемент
	delete temp;
}

void List::DelAll()
{
	// Пока еще есть элементы
	while (Head != 0)
		// Удаляем элементы по одному
		Del();
}

void List::Print()
{
	// запоминаем адрес головного элемента
	Element * temp = Head;
	// Пока еще есть элементы
	while (temp != 0)
	{
		// Выводим данные
		cout << temp->data << " ";
		// Переходим на следующий элемент
		temp = temp->Next;
	}

	cout << "\n\n";
}

//вставка элемента в заданную позицию.
bool List::insert(int position, char data){

	if (position<1 || position>Count)
	{
		cout << "Error!";
		exit(1);
	}

	if (position == 1){
		Element * ptr = Head;
		Head = new Element;
		Head->data = data;
		Head->Next = ptr;
	}

	else if (position == Count){
		Element * ptr = Tail;
		Tail = new Element;
		Tail->data = data;
		Tail->Next = NULL;
		ptr->Next = Tail;
	}

	else
	{
		Element * ptr = Head;
		int i = 1;
		while (i<position - 1){
			ptr = ptr->Next;
			i++;
		}

		Element * prev = ptr;
		Element * next = ptr->Next;
		Element * cur = new Element;
		prev->Next = cur;
		cur->data = data;
		cur->Next = next;
	}
	Count++;
}
//Удаление элемента по заданной позиции.
void List::erase(int position){
	if (position<1 || position>Count)
	{
		cout << "Error!";
		exit(1);
	}

	if (position == 1){
		Element * ptr = Head;
		Head = Head->Next;
		delete ptr;
	}

	else if (position == Count){
		int i = 1;
		Element * ptr = Head;
		while (i<Count - 1){
			ptr = ptr->Next;
			i++;
		}
		Tail = ptr;
		delete Tail->Next;
		Tail->Next = NULL;
	}
	else
	{
		Element * ptr = Head;
		int i = 1;
		while (i<position - 1){
			ptr = ptr->Next;
			i++;
		}

		Element * prev = ptr;
		Element * cur = ptr->Next;
		Element * next = cur->Next;
		prev->Next = next;
		delete cur;
	}
	Count--;
}

//поиск.
int List::search(char data){
	Element * ptr = Head;

	int i = 1;

	while (ptr){
		if (ptr->data == data) return i;
		ptr = ptr->Next;
		i++;
	}

	return NULL;
}

// Тестовый пример
void main()
{
	// Создаем объект класса List
	List lst;

	// Тестовая строка
	char s[] = "Hello, World !!!";
	// Выводим строку
	cout << s << "\n\n";
	// Определяем длину строки
	int len = strlen(s);
	// Загоняем строку в список
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	// Распечатываем содержимое списка
	lst.Print();

	//добавляем элементы в произвольные позиции.
	lst.insert(1, 'K');
	lst.insert(1 + 1, 'I');
	lst.insert(1 + 2, 'L');
	lst.insert(1 + 3, 'L');
	lst.insert(1 + 4, ' ');
	lst.insert(1 + 5, 'y');
	lst.insert(1 + 6, 'o');
	lst.insert(1 + 7, 'u');
	lst.insert(1 + 8, '!');
	lst.insert(1 + 9, ' ');
	//Распечатываем содержимое списка
	lst.Print();

	//удаляем элементы с проивольных позиций.
	lst.erase(12);
	lst.erase(10);
	lst.erase(8);
	lst.erase(6);
	lst.erase(4);
	lst.erase(2);
	lst.erase(1);
	lst.erase(lst.GetCount());
	lst.Print();

	//ищем букву в строке.
	cout << lst.search('d') << '\n';
}

