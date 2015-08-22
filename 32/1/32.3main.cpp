#include <iostream>
#include "menu.cpp"
#include <windows.h>
using namespace std;

class Ar
{
protected:
    double S;
public:
    Ar()
    {
    S=0.0;
    }

    virtual void GetArea()
    {
    S=0.0;
    }
};

class Rect: public Ar
{
private:
    double Height, width;
public:
    Rect()
    {
        Height=0.0;
        width=0.0;
    }
   virtual void SetValue()
    {
        cout<<"Vedite vysotu:\n";
        cin>>Height;
        cout<<"Vedite shyrynu:\n";
        cin>>width;
    }
    virtual void GetArea()
    {
        SetValue();
        S=Height*width;
        cout<<"Ploschad pramougolnika:\t"<<S<<"\n";
    }



};

class Circle: public Ar
{
private:
    double R;
public:
    Circle()
    {
        R=0.0;
    }

  virtual void SetValue()
    {
     cout<<"Vedite radius:\n";
        cin>>R;
    }

    virtual void GetArea()
    {
        SetValue();
        S=3.14*(R*R);
        cout<<"Ploschad kruga:\t"<<S<<"\n";
    }
};

class R_Tria: public Ar
{
private:
    double RLedge, Bedge;
public:
    R_Tria()
    {
      RLedge=0.0;
      Bedge=0.0;
    }
   virtual void SetValue()
    {
        cout<<"Vedite katet 1:\n";
        cin>>RLedge;
        cout<<"Vedite katet 2:\n";
        cin>>Bedge;
    }
        virtual void GetArea()
    {
        SetValue();
        S=RLedge*Bedge/2;
        cout<<"Ploschad pramougolnika:\t"<<S<<"\n";
    }



};

class Trapezoid: public Ar
{
private:
    double a, b,h;
public:
    Trapezoid()
    {
        a=0.0;
        b=0.0;
        h=0.0;
    }
       virtual void SetValue()
    {
        cout<<"Vedite pervuy osnovu:\n";
        cin>>a;
        cout<<"Vedite pervuy osnovu:\n";
        cin>>b;
        cout<<"Vedite vysotu:\n";
        cin>>h;
    }
    virtual void GetArea()
    {
        SetValue();
        S=(a+b)*h/2;
        cout<<"Ploschad pramougolnika:\t"<<S<<"\n";
    }




};

int main()
{
    Rect a;
    Circle b;
     R_Tria c;
     Trapezoid d;

    Ar *ptr[4];


    ptr[0] = &a;
    ptr[1] = &b;
    ptr[2] = &c;
    ptr[3] = &d;

    int flag=0;
    while(1)
    {
        flag=menu(5,"Opredilit ploschad prjamokutnyka","Opredilit ploschad kruga","Opredilit ploschad prjamokutnogo trykutnyka","Opredilit ploschad trapeciji","vyhod");
        switch(flag)
        {
        case 0:
            {
                system("cls");
             ptr[0]->GetArea();
            }
            break;
        case 1:
            {
                system("cls");
                ptr[1]->GetArea();
            }
            break;
        case 2:
            {
                system("cls");
                ptr[2]->GetArea();
            }
            break;
        case 3:
            {
                system("cls");
                ptr[3]->GetArea();
            }
            break;
        case 4:
            {
                system("cls");
                exit(0);
            }
            break;
        }
    }

    return 0;
}
