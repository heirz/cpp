#include <iostream>
#include <windows.h>
#include "menu.cpp"
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <iterator>
#include <fstream>
using namespace std;

struct Reminder
{
    string Text;
    string Date;

};

struct date
{
    int yyyy;
    int mm;
    int dd;
    int hh;
    int mn;
};

class Organizer
{
private:
 const char *FILE_NAME = "D:\\Organizer.txt";
 Reminder R;
 vector <Reminder> Rem;
public:

    void LoadFromFile()
    {
        fstream F(FILE_NAME,ios::in);
        int Size = 0;
        char buf[200];

        while(!F.eof())
        {
        buf[0] = '\0';
        strcpy(buf,R.Date.c_str());
        F.read((char*)&Size,sizeof(int));
        F.read((char*)buf,Size*sizeof(char));
        buf[0] = '\0';
        strcpy(buf,R.Text.c_str());
        F.read((char*)&Size,sizeof(int));
        F.read((char*)buf,Size*sizeof(int));

        Rem.push_back(R);
        }
        F.close();
    }

    Organizer()
    {
        this->LoadFromFile();
    }

    date ParsingDate(string d)
    {
        date dt;
        string tmp;
        tmp = d.substr(0,2);
        dt.dd = atoi(tmp.c_str());
        tmp = d.substr(2,2);
        dt.mm = atoi(tmp.c_str());
        tmp = d.substr(6,4);
        dt.yyyy = atoi(tmp.c_str());
        tmp = d.substr(11,2);
        dt.hh = atoi(tmp.c_str());
        tmp = d.substr(14,2);
        dt.mn = atoi(tmp.c_str());
        return dt;
    }

    date Now()
    {
        date dt;
        time_t now;
        struct tm *timeinfo;
        char buf[20];
        time(&now);
        timeinfo = localtime(&now);
        strftime(buf,20,"%d-%m-%Y-%H-%M",timeinfo);
        string tmp(buf);
        string tmp2;
        tmp2 = tmp.substr(0,2);
        dt.dd = atoi(tmp2.c_str());
        tmp2 = tmp.substr(2,2);
        dt.mm = atoi(tmp2.c_str());
        tmp2 = tmp.substr(6,4);
        dt.yyyy = atoi(tmp2.c_str());
        tmp2 = tmp.substr(11,2);
        dt.hh = atoi(tmp2.c_str());
        tmp2 = tmp.substr(14,2);
        dt.mn = atoi(tmp2.c_str());
        return dt;
    }

    void ShowRem()
    {
        cout<<"Vashi pojelania:\n";
        cout<<"#\tData\t\t\tText\n";
        for(int i = 0; i<Rem.size(); i++)
        {
         cout<<i+1<<"\t"<<Rem[i].Date<<"\t"<<Rem[i].Text<<"\n";
        }
    }

    void ShowActRem()
    {
        date dn;
        date _now;
      cout<<"Vashi aktualnie pojelania:\n";
        cout<<"#\tData\t\t\tText\n";
        for(int i = 0; i<Rem.size(); i++)
        {
            dn = ParsingDate(Rem[i].Date);
            _now = Now();
            if((dn.yyyy>=_now.yyyy)&&(dn.mm>=_now.mm)&&(dn.dd>=_now.dd))
            {
                if((dn.yyyy==_now.yyyy)&&(dn.mm==_now.mm)&&(dn.dd==_now.dd))
                {
                    if((dn.hh>=_now.hh)&&(dn.mn>=_now.mn))
                    {
                     cout<<i+1<<"\t"<<Rem[i].Date<<"\t"<<Rem[i].Text<<"\n";
                    }
                }
                else
                {
                    cout<<i+1<<"\t"<<Rem[i].Date<<"\t"<<Rem[i].Text<<"\n";
                }
            }

        }
    }

    void Add()
    {
        Reminder *tmp = new Reminder;
        date dn;

        date _now;
        _now = Now();
        cout<<"Vvedite text pojelania:\n";
        cin>>tmp->Text;
        while(1)
        {
         cout<<"Vvedite datu pojelania: format: (dd-mm-yyyy-hh-mn)\n";
         cin>>tmp->Date;
         dn = ParsingDate(tmp->Date);
         if((tmp->Date.length()==16)&&(tmp->Date[2]=='-')&&(tmp->Date[5]=='-')&&(tmp->Date[10]=='-')&&(tmp->Date[13]=='-'))
         {

           if((dn.yyyy>=_now.yyyy)&&(dn.mm>=_now.mm)&&(dn.dd>=_now.dd))
            {
                if((dn.yyyy==_now.yyyy)&&(dn.mm==_now.mm)&&(dn.dd==_now.dd))
                {
                    if((dn.hh>=_now.hh)&&(dn.mn>=_now.mn))
                    {
                     break;
                    }
                }
                else
                {
                    break;
                }
            }
         }
        }
        Rem.push_back(*tmp);
    }

    void SaveToFile()
    {
        fstream F(FILE_NAME,ios::in);
        int Size = 0;
        string s;
        for(int i=0; i<Rem.size();i++)
        {
            s = Rem[i].Date;
            Size=s.length();
            F.write((char*)&Size,sizeof(int));
            F.write((char*)Rem[i].Text.c_str(),Size*sizeof(char));
            s = Rem[i].Text;
            Size = s.length();
            F.write((char*)&Size,sizeof(int));
            F.write((char*)Rem[i].Text.c_str(),Size*sizeof(char));
        }
        F.close();
    }

    void Clear()
    {
        Rem.clear();
        this->SaveToFile();
    }

    void ChangeData()
    {
        int index = 0;
        Reminder tmp;
        date _now;
        cout<<"Vvedit nomer :\n";
        while(1)
        {
            cin>>index;
            if(index<Rem.size())
            {
                break;
            }
        }
        tmp = Rem[index];
        while(1)
        {
         cout<<"Vvedit datu pojelania: format: (dd-mm-yyyy-hh-mn)\n";
         cin>>Rem[index].Date;
        date dn = ParsingDate(Rem[index].Date);
         if((tmp.Date.length()==16)&&(tmp.Date[2]=='-')&&(tmp.Date[5]=='-')&&(tmp.Date[10]=='-')&&(tmp.Date[13]=='-'))
         {

           if((dn.yyyy>=_now.yyyy)&&(dn.mm>=_now.mm)&&(dn.dd>=_now.dd))
            {
                if((dn.yyyy==_now.yyyy)&&(dn.mm==_now.mm)&&(dn.dd==_now.dd))
                {
                    if((dn.hh>=_now.hh)&&(dn.mn>=_now.mn))
                    {
                     break;
                    }
                }
                else
                {
                    break;
                }
            }
         }
        }
        cout<<"Vvedit text:\n";
        cin>>Rem[index].Text;
    }

    ~Organizer()
    {
        this->SaveToFile();
    }

    void Remove()
    {
        vector <Reminder>::iterator iter = Rem.begin();
        int index=0;
        cout<<"Vvedit index:\n";
        while(1)
        {
            cin>>index;
            if(index<Rem.size())
            {
                for(int i=0; i<index;i++)
                {
                    iter++;
                }
                Rem.erase(iter);
                return;
            }
        }
    }

};

int main()
{
    Organizer Or;
    int flag=0;
    while(1)
    {
        flag = menu(8,"Dobavit","Izmenit","Udalyt pojelania","Ochystyt","Save","Vyvesty vse zapisi","Vyvesty aktualni zapisi","Vyhod");
        switch(flag)
        {
        case 0:
            {
                system("cls");
                Or.Add();
                system("cls");
            }
            break;
        case 1:
            {
                system("cls");
                Or.ChangeData();
                system("cls");
            }
            break;
        case 2:
            {
                system("cls");
                Or.Remove();
                system("cls");
            }
            break;
        case 3:
            {
                system("cls");
                Or.Clear();
                system("cls");
            }
            break;
        case 4:
            {
                system("cls");
                Or.SaveToFile();

            }
            break;
        case 5:
            {
                system("cls");
                Or.ShowRem();
            }
            break;
        case 6:
            {
                system("cls");
                Or.ShowActRem();
            }
            break;
        case 7:
            {
                system("cls");
                exit(0);
            }
        }
    }
    return 0;
}
