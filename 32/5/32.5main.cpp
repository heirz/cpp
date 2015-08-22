#include <iostream>
#include <windows.h>
#include "menu.cpp"
#include <math.h>

using namespace std;

class equation
{
protected:

    double X,x1,x2;
public:

    equation()
    {
        X=0;
        x1=0;
        x2=0;
    }

    virtual void root()
    {
        cout<<"X= "<<X<<"\n";
    }
};

class SquarEQ: public equation
{
private:
    double a,b,c,d;

public:
    SquarEQ()
    {

        a=b=c=d=0;
    }

    void SetEq()
    {
        int i=0;
        cout<<"Uravnenie vidu ax2+bx+c=0\n";
        cout<<"Vvedite perviy koeficient uravnenie\n";
        cin>>a;
        cout<<"Vvedite vtoroy koeficient uravnenie\n";
        cin>>b;
        cout<<"Vvedite tretiy koeficient uravnenie\n";
        cin>>c;
        d=b*b-4*a*c;
    }

   virtual void root()
   {
       x1=(-b+sqrt(d))/(2*a);
       x2=(-b-sqrt(d))/(2*a);
       cout<<"x1="<<x1<<"\nx2="<<x2<<"\n";
   }
};

class LineEQ: public equation
{
private:
    double a,b,y;
 public:
     LineEQ()
     {
         a=b=y=0;
     }

     void SetEq()
     {
         cout<<"Uravnenie vyda ax+b=y\n";
         cout<<"Vvedite a\n";
        cin>>a;
        cout<<"Vvedite b\n";
        cin>>b;
        cout<<"Vvedite y\n";
        cin>>y;
     }

     virtual void root()
     {
         X=(y-b)/a;
                cout<<"X="<<X<<"\n";

     }
};

int main()
{
  int flag=0,flg=0;
  while(1)
  {
      flag=menu(3,"zadat kvadratnoe uravnenie i poschitat","zadaty linijne uravnenie i poschitat","vyhod");
      switch(flag)
      {
      case 0:
        {
         SquarEQ *s = new SquarEQ;
         s->SetEq();
         s->root();
            delete s;
        }
        break;
      case 1:
        {
           LineEQ *l = new LineEQ;
         l->SetEq();
         l->root();
            delete l;
        }
        break;
      case 2:
        {
            exit(0);
        }
        break;
      }
  }
    return 0;
}
