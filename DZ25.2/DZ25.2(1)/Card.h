#pragma once
static int index = 1;
class Card
{
public:
	Card(int);
	~Card();
	void Sort();
	int Rozd();
	int RozdBank();
	int Symma(int);
	int Symma();
	int SymmaBank(int);
	int SymmaBank();
private:

	int KolKart;
	int Mast[4];
	int* Dost;
	int *Kploda[4];