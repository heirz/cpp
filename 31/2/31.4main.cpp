#include <iostream>
#include "menu.cpp"
#include <string.h>
#include <malloc.h>
#include <windows.h>
using namespace std;

class Point{
protected:
  int X;
  int Y;
public:
  Point()
  {
    X=Y=0;
  }

  void SetPoint(int iX,int iY)
  {
    X=iX;
    Y=iY;
  }

  void Show()
  {
    cout<<"X:\t"<<X<<"\nY:\t"<<Y<<"\n";
  }
};
class Figura
{
protected:
  Point*obj;
  int Count;
  int color;
public:

  Figura()
  {
    Count=color=0;
    obj=NULL;
  }
  void CreateFigura(int cr,int ct)
  {
    Count=ct;
    color=cr;
    obj=new Point[Count];
      cout<<"Count\t"<<Count<<"\n";
    int tempX,tempY;
    for(int i=0;i<Count;i++)
    {
      cout<<"Set X\n";
      cin>>tempX;
      cout<<"Set Y\n";
      cin>>tempY;
      obj[i].SetPoint(tempX,tempY);
    }
  }



  ~Figura()
  {
    if(obj!=NULL)
        delete[]obj;
  }


};

class Fgr: public Figura
{
public:
char name[25];

  void ShowFigura()
  {
    cout<<"Name:\t"<<name<<"\nColor:\t"<<color<<"\nPoints:\t"<<Count<<"\n";
    for(int i=0;i<Count;i++)
    {
      obj[i].Show();
    }
  }
};

class Bitmap
{
private:
    Fgr *F;
    char *buf;
    int Size, K;
public:

    Bitmap()
    {
        F=(Fgr*)malloc(sizeof(Fgr));
        buf=(char*)malloc(sizeof(char));
        Size=K=0;
    }

    void SetValue()
    {
        int flag=0;
        int tmp=0, tmp2=0;
        while(1)
        {
            flag=menu(6,"Kvadrat","Krug","Treugolnik","Romb","Paralelogram","Mnogougolnik");
            switch(flag)
            {
            case 0:
                {
                    realloc(F,++K*sizeof(Fgr));
                    cout<<"vvedite cvet figury 0-255:\n";
                    cin>>tmp;
                    strcpy(F[K-1].name,"Kvadrat");
                    F[K-1].CreateFigura(tmp,4);

                }
                break;
            case 1:
                {
                    realloc(F,++K*sizeof(Fgr));
                    cout<<"vvedite cvet figury 0-255:\n";
                    cin>>tmp;
                    strcpy(F[K-1].name,"Krug");
                    F[K-1].CreateFigura(tmp,1);
                }
                break;
            case 2:
                {
                    realloc(F,++K*sizeof(Fgr));
                    cout<<"vvedite cvet figury 0-255:\n";
                    cin>>tmp;
                    strcpy(F[K-1].name,"Treugolnik");
                    F[K-1].CreateFigura(tmp,3);
                }
                break;
            case 3:
                {
                    realloc(F,++K*sizeof(Fgr));
                    cout<<"vvedite cvet figury 0-255:\n";
                    cin>>tmp;
                    strcpy(F[K-1].name,"Romb");
                    F[K-1].CreateFigura(tmp,4);
                }
                break;
            case 4:
                {
                    realloc(F,++K*sizeof(Fgr));
                    cout<<"vvedite cvet figury 0-255:\n";
                    cin>>tmp;
                    strcpy(F[K-1].name,"Paralelogram");
                    F[K-1].CreateFigura(tmp,4);
                }
                break;
            case 5:
                {
                    realloc(F,++K*sizeof(Fgr));
                    cout<<"vvedite cvet figury 0-255:\n";
                    cin>>tmp;
                    cout<<"vvedite kolichestvo uglov:\n";
                    cin>>tmp2;
                    strcpy(F[K-1].name,"Mnogougolnik");
                    F[K-1].CreateFigura(tmp,tmp2);
                }
                break;
            }
            flag=menu(2,"Dobavit figuru","Otmena");
            if(flag==1)
                break;
        }
    }

    int& GetK()
    {
        cout<<"Na vashomu risunke "<<K<<" figura;\n";
    }

    void Print()
    {
       cout<<"Figury na vashom risunke:\n";
       if(K>0)
       {
           for(int i=0;i<K;i++)
           {
               F[i+1].ShowFigura();
           }
       }
    }
    ~Bitmap()
    {
        free(F);
    }
};

int main()
{
 int flg=0;
Bitmap bmp;
 while(1)
 {
     flg=menu(4,"vyhod","dobavit figuru", "pokazat risunok","novyj risunok");
     switch(flg)
     {
     case 0:
        {
            system("cls");
            exit(0);
        }
     case 1:
        {
           system("cls");
          bmp.SetValue();
        system("cls");
        }
        break;
     case 2:
        {
            system("cls");
            bmp.GetK();
            bmp.Print();
        }
        break;
     case 3:
        {
            system("cls");
            bmp.~Bitmap();
            bmp.GetK()=0;
        }
        break;
     }
 }

}
