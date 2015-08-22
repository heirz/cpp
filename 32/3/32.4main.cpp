#include <iostream>
#include <windows.h>
#include <time.h>
#include "menu.cpp"
using namespace std;

class Okra
{
protected:
    unsigned int Counter;

    unsigned int MaxAge;
public:
    Okra()
    {
        Counter=0;
        MaxAge=0;
    }



};

class Fox: public Okra
{
public:
    Fox *next,*prev;
unsigned int age;


    Fox()
    {
        MaxAge=8;
        age=0;
        next=prev=NULL;
    }
    bool IsFull()
    {
        return Counter==5;
    }

    bool IsEmpty()
    {
        return Counter==0;
    }

    void Old()
    {
     age++;
    }



};

class FoxList
{
private:
    Fox *head,*tail;
    int k;
    unsigned int age;
public:

     FoxList()
     {
         head=tail=NULL;
         k=0;
     }

     void Birth()
     {
         Fox *elem = new Fox;
         if(head==NULL)
         {
             head=tail=elem;
         }
         else
         {
             tail->next=elem;
             elem->prev=tail;
             tail=elem;
         }
        k++;
        cout<<"Dobavlena lysa!\n";
     }

     void Deth()
     {
         int t=8+rand()%5-3;

             Fox *tmp = new Fox;
             tmp=head;
             while(tmp!=NULL)
             {
                 if(tmp->age >= t)
                 {
                     if(tmp->prev!=NULL)
                     tmp->prev->next=tmp->next;
                     if(tmp->prev!=NULL)
                     tmp->next->prev=tmp->prev;
                     delete tmp;
                     cout<<"Lysa umerla!\n";
                      k--;
                 }
                 tmp=tmp->next;
             }



     }

     void Older()
     {
      Fox *tmp = new Fox;
      tmp=head;
      while(tmp!=NULL)
      {
          if(rand()%2==1)
          {
              tmp->Old();
          }
          tmp=tmp->next;
          Sleep(300);
      }
     }

     int GetK()
     {
         return k;
     }

     ~FoxList()
     {
         Fox *tmp = new Fox;

         while(tmp!=NULL)
         {
             tmp=head;
          head=head->next;
          delete tmp;

         }
     }
};

class Rab: public Okra
{
public:
    unsigned int MaxAge;
    unsigned int age;
    Rab *next, *prev;

    Rab()
    {
        age=0;
        MaxAge=5;
        next=prev=NULL;
    }
    bool IsFull()
    {
        return Counter==7;
    }

    bool IsEmpty()
    {
        return Counter==0;
    }
    void Old()
    {
     age++;
    }

};

class RabList
{
private:
    Rab *head,*tail;
    int k;
public:

     RabList()
     {
         head=tail=NULL;
         k=0;
     }

     void Birth()
     {
         Rab *elem = new Rab;
         if(head==NULL)
         {
             head=tail=elem;
         }
         else
         {
             tail->next=elem;
             elem->prev=tail;
             tail=elem;
         }
        k++;
        cout<<"Dobavlen krolik!\n";
     }

     int Getk()
     {
         return k;
     }

     void EatMe()
     {
         Rab *tmp = new Rab;
         tmp=head;
         if(tmp!=NULL)
         {
             head=head->next;
             delete tmp;
             k--;
             cout<<"Sjedeno krolykov!\n";
         }
     }

     void Deth()
     {
         int t=5+rand()%3-2;

             Rab *tmp = new Rab;
             Rab *tmp2 = new Rab;
             tmp=head;
             tmp2=NULL;
         while(tmp!=NULL)
             {
                  tmp2=tmp->next;
                 if(tmp->age >= t)
                 {
                     if(tmp->prev!=NULL)
                     {
                         if(tmp->prev->next!=NULL)
                       tmp->prev->next=tmp->next;
                     if(tmp->prev!=NULL)
                     {
                      tmp->next->prev=tmp->prev;
                     delete tmp;
                     cout<<"Krolik umer!\n";
                     k--;
                     }

                     }

                 }
                 tmp=tmp2;

         }


     }

     void Older()
     {
      Rab *tmp = new Rab;
      tmp=head;
      while(tmp!=NULL)
      {
          if(rand()%2==1)
          {
              tmp->Old();
          }
          Sleep(300);
      tmp=tmp->next;

      }
     }

     ~RabList()
     {
         Rab *tmp = new Rab;

         while(tmp!=NULL)
         {
             tmp=head;
          head=head->next;
          delete tmp;

         }
     }
};

class Gra: public Okra
{
public:
   Gra *next, *prev;

    bool IsFull()
    {
        return Counter==10;
    }



    bool IsEmpty()
    {
        return Counter==0;
    }


};

class GraList
{
private:
    Gra *head,*tail;
    int k;
public:

     GraList()
     {
         head=tail=NULL;
         k=0;
     }

     void Birth()
     {
         Gra *elem = new Gra;
         if(head==NULL)
         {
             head=tail=elem;
         }
         else
         {
             tail->next=elem;
             elem->prev=tail;
             tail=elem;
         }
        k++;
        cout<<"Dobavlena trava!\n";
     }

     int Getk()
     {
         return k;
     }

     void EatMe()
     {
         Gra *tmp = new Gra;
         tmp=head;
         if(tmp!=NULL)
         {
             head=head->next;
             delete tmp;
             k--;
             cout<<"Cjedena trava!\n";
         }
     }

     ~GraList()
     {
         Gra *tmp = new Gra;

         while(tmp!=NULL)
         {
             tmp=head;
          head=head->next;
          delete tmp;

         }
     }
};

class NoLife
{
public:
    NoLife()
    {
     cout<<"No life!\n";
     Sleep(750);
     exit(0);
    }

};

int main()
{

 FoxList f;
 RabList r;
 GraList g;
  f.Birth();
  f.Birth();
  r.Birth();
  r.Birth();
  g.Birth();
  g.Birth();
while(1)
{
 Sleep(650);

 if(r.Getk()>g.Getk())
 {
     srand(time(NULL));
     int j=rand()%3;
if(g.Getk()>j)
{
    for(int i=0;i<j;i++)
    {
        g.EatMe();
    }
}
else
{
    if(g.Getk()>=1)
    {
        g.EatMe();
    }
}
 }
 f.Deth();
 r.Deth();
 if(f.GetK()<5)
 {
     if(f.GetK()>=1)
     {
      int t=0;
      srand(time(NULL));
     t=rand()%2;
     if(t==1)
     {
         f.Birth();
     }
     }

 }
 if(r.Getk()<f.GetK())
 {
     r.EatMe();
 }
 if(r.Getk()<7)
 {
     if(r.Getk()>=1)
     {
         int t=0;
         srand(time(NULL));
     t=rand()%2;
     if(t==1)
     {
         r.Birth();
     }
     }

 }
  if(g.Getk()<10)
 {
     if(g.Getk()>=1)
     {
         int t=0;
         srand(time(NULL));
     t=rand()%4;
     if(t==1)
     {
         g.Birth();
     }
     }

 }
 f.Older();
 r.Older();
 cout<<"Lysic:\t"<<f.GetK()<<"\nKrolikov:\t"<<r.Getk()<<"\nTravy:\t"<<g.Getk()<<"\n";

}

    return 0;
}
