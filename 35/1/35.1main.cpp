#include <iostream>
#include <vector>
#include "menu.cpp"
#include <time.h>
#include <windows.h>
using namespace std;

class Vect_Square
{
private:
    vector <double> V;
public:
    Vect_Square()
    {
        V.resize(10,1);
    }

    void SetVect()
    {
        for(int i=0;i<10;i++)
        {
            cout<<"Vvedite "<<i<<" element:\n";
            cin>>V[i];
        }
        system("cls");
    }

    void SetVectRand()
    {
        double buf = 0.0;
     for(int i=0;i<10;i++)
        {
            srand(time(NULL));
            buf=rand()%30;
            cout<<i<<" element:\t"<<buf<<"\n";
            V[i] = buf;
            Sleep(650);
        }
        system("cls");
    }

    void Sqare()
    {
        vector <double>::iterator iter = V.begin();
        for(;iter<V.end();iter++)
        {
            (*iter)=(*iter) * (*iter);
        }
    }

    void Print()
    {
       vector <double>::iterator iter;
       cout<<"Vector:\n";
        for(iter=V.begin();iter<V.end();iter++)
        {
            cout<<*iter<<"\n";
        }
    }
};

int main()
{
    Vect_Square Vec;
    int flag=0;
    while(1)
    {
        flag=menu(3,"Zadat znachenia","Vyvesty na ekran", "Vyhod");
        switch(flag)
        {
        case 0:
            {
               flag=menu(2,"Zadat s klaviatury","Zadat avto");
               switch(flag)
               {
               case 0:
                {
                    Vec.SetVect();
                }
                break;
               case 1:
                {
                    Vec.SetVectRand();
                }
                break;
               }
            }
            break;
               case 1:
                {
                    Vec.Sqare();
                    Vec.Print();
                }
                break;
               case 2:
                {
                    exit(0);
                    system("cls");
                }
                break;
        }
    }


    return 0;
}
