#include <iostream>
#include "menu.cpp"
#include <windows.h>
#include <fstream>
#include <string.h>
using namespace std;

class Passport
{
protected:
    char name[20], sur[20], par[20], addr[50], sp[15], dat[15];
    int vozrast, num;
public:
    Passport()
    {
        vozrast=0;
        num=0;
    }

    void SetValue()
    {
        cout<<"vvedite familia:\n";
        cin>>sur;
         cout<<"vvedite imja:\n";
         cin>>name;
         cout<<"vvedite otchestvo:\n";
         cin>>par;
        cout<<"vvedite vozrast:\n";
        cin>>vozrast;
        cout<<"vvedite datu rodzhennja (format: dd/mm/yyyy):\n";
        cin>>dat;
        cout<<"vvedite adresu:\n";
        cin>>addr;
        cout<<"vvedite simejnyj pologenie:\n";
        cin>>sp;

    }

    void SetName()
    {
     cout<<"vvedite imja:\n";
        cin>>name;
    }

        void SetSur()
    {
     cout<<"vvedite familia:\n";
        cin>>sur;
    }

        void SetPar()
    {
     cout<<"vvedite otchestvo:\n";
        cin>>par;
    }

    void SetAge()
    {
      cout<<"vvedite vozrast:\n";
        cin>>vozrast;
    }

    void SetAddr()
    {
      cout<<"vvedite adresu:\n";
        cin>>addr;
    }

        void SetSp()
    {
      cout<<"vvedite simejnyj pologenie:\n";
        cin>>sp;
    }



    void SetDat()
    {
      cout<<"vvedite datu rodzhennja (format: dd/mm/yyyy):\n";
        cin>>dat;
    }

    void Print()
    {
        cout<<"Imja:\t\t\t"<<name<<"\nfamilia:\t\t"<<sur<<"\notchestvo:\t\t"<<par<<"\nData rodzhennja:\t"<<dat<<"\nvozrast:\t\t\t"<<vozrast<<"\nAdresa:\t\t\t"<<addr<<"\nSimejnyj pologenie:\t\t"<<sp<<"\n";
    }


};

class Foreign_passport: public Passport
{
private:
    char visa[200], ser[5];
    int nom;
public:
    void Set_Value()
    {
        cout<<"vvedite dannie po visy:\n";
        cin>>visa;
        cout<<"vvedite seriju:\n";
        cin>>ser;
        cout<<"vvedite nomer zagran pasporta:\n";
        cin>>nom;
    }

    void SetVisa()
    {
      cout<<"vvedite dannie po visy:\n";
        cin>>visa;
    }

    void SetNom()
    {
       cout<<"vvedite nomer pasporta:\n";
        cin>>nom;
    }

            void SetSer()
    {
      cout<<"vvedite seriju pasporta:\n";
        cin>>ser;
    }


        void SaveToFile()
    {
        int Size=0;
        fstream file("pasport.txt",ios::out);
        Size=strlen(name);
        file.write((char*)&Size,sizeof(int));
        file.write((char*)&name,Size*sizeof(char));
        Size=strlen(sur);
        file.write((char*)&Size,sizeof(int));
        file.write((char*)&sur,Size*sizeof(char));
        Size=strlen(par);
        file.write((char*)&Size,sizeof(int));
        file.write((char*)&par,Size*sizeof(char));
        Size=strlen(dat);
        file.write((char*)&Size,sizeof(int));
        file.write((char*)&dat,Size*sizeof(char));
        Size=strlen(addr);
        file.write((char*)&Size,sizeof(int));
        file.write((char*)&addr,Size*sizeof(char));
        Size=strlen(sp);
        file.write((char*)&Size,sizeof(int));
        file.write((char*)&sp,Size*sizeof(char));
        Size=strlen(visa);
        file.write((char*)&Size,sizeof(int));
        file.write((char*)&visa,Size*sizeof(char));
        Size=strlen(ser);
        file.write((char*)&Size,sizeof(int));
        file.write((char*)&ser,Size*sizeof(char));

        file.write((char*)&vozrast,sizeof(int));
        file.write((char*)&nom,sizeof(int));
        file.close();
    }

    void LoadFromFile()
    {
        int Size=0;
        fstream file("pasport.txt",ios::in);
        file.read((char*)&Size,sizeof(int));
        file.read((char*)&name,Size*sizeof(char));
        name[Size]='\0';
        file.read((char*)&Size,sizeof(int));
        file.read((char*)&sur,Size*sizeof(char));
        sur[Size]='\0';
        file.read((char*)&Size,sizeof(int));
        file.read((char*)&par,Size*sizeof(char));
        par[Size]='\0';
        file.read((char*)&Size,sizeof(int));
        file.read((char*)&dat,Size*sizeof(char));
        dat[Size]='\0';
        file.read((char*)&Size,sizeof(int));
        file.read((char*)&addr,Size*sizeof(char));
        addr[Size]='\0';
        file.read((char*)&Size,sizeof(int));
        file.read((char*)&sp,Size*sizeof(char));
        sp[Size]='\0';
        file.read((char*)&Size,sizeof(int));
        file.read((char*)&visa,Size*sizeof(char));
        visa[Size]='\0';
        file.read((char*)&Size,sizeof(int));
        file.read((char*)&ser,Size*sizeof(char));
        ser[Size]='\0';

        file.read((char*)&vozrast,sizeof(int));
        file.read((char*)&nom,sizeof(int));

        file.close();
    }

    void _Print()
    {
        cout<<"Vizy:\t\t\t"<<visa<<"\nSerija:\t\t\t"<<ser<<"\nNomer:\t\t\t"<<nom<<"\n";
    }

};

int main()
{
    Foreign_passport pas;
    int flag=0;
    while(1)
    {
        flag=menu(15,"vihod","vvesty informaciju","izmenit imja","izmenit familia","izmenit otchestvo", "izmenit datu rodzhennja", "izmenit vozrast", "izmenit adresu", "izmenit simejnyj pologenie","izmenit dannie po vizy","izmenit seriju pasporta","izmenit nomer pasporta", "save fajl", "zagruzit fajl", "pechat");
        switch(flag)
        {
        case 0:
            {
                system("cls");
                exit(0);
            }
            break;
        case 1:
            {
                 system("cls");
                pas.SetValue();
                pas.Set_Value();
                 system("cls");
            }
            break;
        case 2:
            {
                 system("cls");
                pas.SetName();
                 system("cls");
            }
            break;
        case 3:
            {
                 system("cls");
                pas.SetSur();
                 system("cls");
            }
            break;
        case 4:
            {
                 system("cls");
                pas.SetPar();
                system("cls");
            }
            break;
        case 5:
            {
                 system("cls");
                pas.SetDat();
                 system("cls");
            }
            break;
        case 6:
            {
                 system("cls");
                pas.SetAge();
                 system("cls");
            }
            break;
        case 7:
            {
                 system("cls");
                pas.SetAddr();
                 system("cls");
            }
            break;
        case 8:
            {
                 system("cls");
                pas.SetSp();
                 system("cls");
            }
            break;
        case 9:
            {
                system("cls");
                pas.SetVisa();
                 system("cls");
            }
            break;
        case 10:
            {
                system("cls");
                pas.SetSer();
                 system("cls");
            }
            break;
        case 11:
            {
                system("cls");
                pas.SetNom();
                 system("cls");
            }
            break;
        case 12:
            {
                 system("cls");
                pas.SaveToFile();

            }
            break;
        case 13:
            {
                 system("cls");
                pas.LoadFromFile();

            }
            break;
        case 14:
            {
                 system("cls");
                pas.Print();
                pas._Print();
            }
            break;

        }
    }


    return 0;
}
