#include <iostream>
#include <windows.h>
#include "menu.cpp"

using namespace std;

class Employer
{
protected:
    bool content;
   char name[50];
   int age;
public:
    Employer()
    {
    age=0;
    content=false;
    }

    void ChangeName()
    {

                   cout<<"vvedite imja:\n";
                   cin>>name;

    }

    void ChangeAge()
    {

                   cout<<"vvedite vozrast:\n";
                   cin>>age;

    }

       char* RetName()
       {
           char *ptr=name;
           return ptr;
       }

       int RetAge()
       {
          return age;
       }

    bool Content()
    {
        bool buf=content;
        if(content)
            content=false;
        else
            content=true;
       return buf;
    }
   virtual void Print()=0;
};

class President:public Employer
{
protected:
    int oklad;
    char company[20];
    int stazh;
public:
    President()
    {
        oklad=0;
        stazh=0;
    }

char* RetCom()
       {
           char *ptr=company;
           return ptr;
       }

    void ChangeOklad()
    {
        cout<<"vvedite oklad:\n";
                   cin>>oklad;
    }

    void ChangeStazh()
    {
        cout<<"vvedite stazh:\n";
                   cin>>stazh;
    }

    void ChangeCompany()
    {
          cout<<"vvedite nazvanie kompaniji:\n";
                   cin>>company;
    }

   virtual void Print()
   {
    cout<<"\t\tPresident\t\t\nImja:\t"<<RetName()<<"\nVik:\t"<<RetAge()<<"\nOklad:\t"<<oklad<<"\nNazva kompaniji:\t"<<RetCom()<<"\nStazh:\t"<<stazh<<"\n";
   }

};

class Manager:public Employer
{
protected:
    int oklad;
    char company[20];
    char department[20];
    int stazh;
    int kilk;
public:
    Manager()
    {
        oklad=0;
        stazh=0;
        kilk=0;
    }



char* RetCom()
       {
           char *ptr=company;
           return ptr;
       }

       char* RetDep()
       {
           char *ptr=department;
           return ptr;
       }

    void ChangeOklad()
    {
        cout<<"vvedite oklad:\n";
                   cin>>oklad;
    }

    void ChangeStazh()
    {
       cout<<"vvedite stazh:\n";
                   cin>>stazh;
    }

    void
     ChangeCompany()
    {
         cout<<"vvedite nazvanie kompaniji:\n";
                   cin>>company;
    }

    void ChangeDepartment()
    {
         cout<<"vvedite nazvanie departmenta:\n";
        cin>>department;
    }

    void ChangeKilk()
    {
       cout<<"vvedite kilkist rabochih:\n";
        cin>>kilk;
    }
       virtual void Print()
   {
    cout<<"\t\tManager\t\t\nImja:\t"<<RetName()<<"\nVozrast:\t"<<RetAge()<<"\nOklad:\t"<<oklad<<"\nNazvanie kompaniji:\t"<<RetCom()<<"\nStazh:\t"<<stazh<<"\nDepartment: \t"<<RetDep()<<"\nKilkist rabochih:\t"<<kilk<<"\n";
   }

};

class Worker:public Employer
{
protected:
    int oklad;
    char company[20];
    int stazh;
    int level;
public:
    Worker()
    {
        oklad=0;
        stazh=0;
        level=0;
    }

char* RetCom()
       {
           char *ptr=company;
           return ptr;
       }

    void ChangeOklad()
    {
        cout<<"vvedite oklad:\n";
                   cin>>oklad;
    }

    void ChangeStazh()
    {
        cout<<"vvedite stazh:\n";
                   cin>>stazh;
    }

    void ChangeCompany()
    {
       cout<<"vvedite nazvanie kompaniji:\n";
                   cin>>company;
    }

    void ChangeLevel()
    {
        cout<<"vvedite uroven mastera:\n";
                   cin>>level;
    }

   virtual void Print()
   {
    cout<<"\t\tWorker\t\t\nImja:\t"<<RetName()<<"\nVozrast:\t"<<RetAge()<<"\nOklad:\t"<<oklad<<"\nNazvanie kompaniji:\t"<<RetCom()<<"\nStazh:\t"<<stazh<<"\nUroven mastera:\t"<<level<<"\n";
   }

};

int main()
{
    int flag=0,flg=0;
    bool first=true;
    President *p=NULL;
    Manager *m=NULL;
    Worker *w=NULL;
    while(1)
    {
		flag = menu(4, "Novaya dolgnost", "Vyvesty danie", "Menu dolgnosti", "Vyhod");
     switch(flag)
     {
     case 0:
        {
        system("cls");
      if(p)
      {
          delete p;
      }
      else if(m)
      {
          delete m;
      }
      else if(w)
      {
          delete w;
      }
      else
      {
          flg=menu(3,"President","Manager","Worker");
          switch(flg)
          {
          case 0:
            {
                p = new President;
            }
            break;
          case 1:
            {
                m = new Manager;
            }
            break;
          case 2:
            {
                w = new Worker;
            }
            break;
          }
      }
      system("cls");
      if(p || m || w)
        cout<<"Done!\n";
      else
        cout<<"Error!";
        }
        break;
          case 1:
            {
                system("cls");
              if(p)
      {

          if(p->Content())
          p->Print();

      }
      else if(m)
      {
          if(m->Content())
          m->Print();

      }
      else if(w)
      {
          if(w->Content())
         w->Print();

      }
      else
      {
          cout<<"Access denied!\n";
      }

            }
            break;
          case 2:
            {

               if(p)
               {
                   system("cls");
                   p->ChangeName();
                   p->ChangeAge();
                   p->ChangeOklad();
                   p->ChangeStazh();
                   p->ChangeCompany();
                   p->Content();
                   system("cls");
               }
               else if(m)
               {
                 system("cls");
                   m->ChangeName();
                   m->ChangeAge();
                   m->ChangeOklad();
                   m->ChangeStazh();
                   m->ChangeCompany();
                   m->ChangeDepartment();
                   m->ChangeKilk();
                   m->Content();
                   system("cls");
               }
               else if(w)
               {
                   system("cls");
                   w->ChangeName();
                   w->ChangeAge();
                   w->ChangeOklad();
                   w->ChangeStazh();
                   w->ChangeCompany();
                   w->ChangeLevel();
                   w->Content();
                   system("cls");
               }
               else
               {
                   system("cls");
                   cout<<"Access denied!\n";
               }
            }
            break;
          case 3:
            {
                system("cls");
                exit(0);
            }
            break;
     }
    }

    return 0;
}
