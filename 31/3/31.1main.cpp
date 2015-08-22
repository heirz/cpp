#include <iostream>
#include "menu.cpp"
#include <windows.h>
#include <fstream>
#include <string.h>
using namespace std;

class student
{
protected:
    char pib[50], spec[50];
    int vozrast, kurs, bal;
public:
    student()
    {
        vozrast=0;
        kurs=0;
        bal=0;
    }

    void SetValue()
    {
        cout<<"vvedite familiu, otchestvo:\n";
        cin>>pib;
        cout<<"vvedite vozrast:\n";
        cin>>vozrast;
        cout<<"vvedite kurs:\n";
        cin>>kurs;
		cout << "vvedite specialnost:\n"; specialnost
        cin>>spec;
        cout<<"vvedite bal:\n";
        cin>>bal;
    }

    void SetName()
    {
     cout<<"vvedite familiu, otchestvo:\n";
        cin>>pib;
    }

    void SetAge()
    {
      cout<<"vvedite vozrast:\n";
        cin>>vozrast;
    }

    void SetKurs()
    {
      cout<<"vvedite kurs:\n";
        cin>>kurs;
    }

    void SetSpec()
    {
      cout<<"vvedite specialnost:\n";
        cin>>spec;
    }

    void SetBal()
    {
     cout<<"vvedite bal:\n";
        cin>>bal;
    }

    void Print()
    {
        cout<<"PIB studenta:\t\t"<<pib<<"\nvozrast studenta:\t\t"<<vozrast<<"\nKurs:\t\t\t"<<kurs<<"\nspecialnost:\t\t"<<spec<<"\nBal:\t\t\t"<<bal<<"\n";
    }


};

class Aspirant: public student
{
private:
    char tema[50], date[15];
public:
    void Set_Value()
    {
        cout<<"vvedite temu kandydatskoji roboti:\n";
        cin>>tema;
        cout<<"vvedite datu zdachi (format: dd//mm//yyyy):\n";
        cin>>date;
    }

    void SetTema()
    {
      cout<<"vvedite temu kandydatskoji roboti:\n";
        cin>>tema;
    }

    void SetDate()
    {
       cout<<"vvedite datu zdachi (format: dd//mm//yyyy):\n";
        cin>>date;
    }

        void SaveToFile()
    {
        int Size=0;
        fstream file("data.txt",ios::out);
        Size=strlen(pib);
        file.write((char*)&Size,sizeof(int));
        file.write((char*)&pib,Size*sizeof(char));
        Size=strlen(spec);
        file.write((char*)&Size,sizeof(int));
        file.write((char*)&spec,Size*sizeof(char));
                Size=strlen(tema);
        file.write((char*)&Size,sizeof(int));
        file.write((char*)&tema,Size*sizeof(char));
                Size=strlen(date);
        file.write((char*)&Size,sizeof(int));
        file.write((char*)&date,Size*sizeof(char));
        file.write((char*)&vozrast,sizeof(int));
        file.write((char*)&kurs,sizeof(int));
        file.write((char*)&bal,sizeof(int));
        file.close();
    }

    void LoadFromFile()
    {
        int Size=0;
        fstream file("data.txt",ios::in);
        file.read((char*)&Size,sizeof(int));
        file.read((char*)&pib,Size*sizeof(char));
        pib[Size]='\0';
        file.read((char*)&Size,sizeof(int));
        file.read((char*)&spec,Size*sizeof(char));
        spec[Size]='\0';
        file.read((char*)&Size,sizeof(int));
        file.read((char*)&tema,Size*sizeof(char));
        tema[Size]='\0';
        file.read((char*)&Size,sizeof(int));
        file.read((char*)&date,Size*sizeof(char));
        date[Size]='\0';
        file.read((char*)&vozrast,sizeof(int));
        file.read((char*)&kurs,sizeof(int));
        file.read((char*)&bal,sizeof(int));
        file.close();
    }

    void _Print()
    {
        cout<<"Tema kandydatskoji:\t"<<tema<<"\nData zdachi:\t\t"<<date<<"\n";
    }

};

int main()
{
    Aspirant Asp;
    int flag=0;
    while(1)
    {
        flag=menu(12,"vihod","vvesty informaciju","izmenit PIB","izmenit specialnost","izmenit vozrast", "izmenit kurs", "izmenit bal", "izmenit temu kandydatskoji", "izmenit datu zdachi", "save fajl", "load fajlu", "pechat");
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
                Asp.SetValue();
                Asp.Set_Value();
                 system("cls");
            }
            break;
        case 2:
            {
                 system("cls");
                Asp.SetName();
                 system("cls");
            }
            break;
        case 3:
            {
                 system("cls");
                Asp.SetSpec();
                 system("cls");
            }
            break;
        case 4:
            {
                 system("cls");
                Asp.SetAge();
                 system("cls");
            }
            break;
        case 5:
            {
                 system("cls");
                Asp.SetKurs();
                 system("cls");
            }
            break;
        case 6:
            {
                 system("cls");
                Asp.SetBal();
                 system("cls");
            }
            break;
        case 7:
            {
                 system("cls");
                Asp.SetTema();
                 system("cls");
            }
            break;
        case 8:
            {
                 system("cls");
                Asp.SetDate();
                 system("cls");
            }
            break;
        case 9:
            {
                 system("cls");
                Asp.SaveToFile();

            }
            break;
        case 10:
            {
                 system("cls");
                Asp.LoadFromFile();

            }
            break;
        case 11:
            {
                 system("cls");
                Asp.Print();
                Asp._Print();
            }
            break;

        }
    }


    return 0;
}
