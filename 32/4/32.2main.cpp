#include <iostream>
#include "menu.cpp"
#include <windows.h>
#include <string.h>
using namespace std;

class Node
{
public:
    char name[50];
    int number;
    Node *next, *prev;
    Node()
    {
        number=0;
        prev=next=NULL;
        strset(name,27);
    }
};

class List
{
protected:
    unsigned int Counter;
    unsigned int Max_Length;
    Node *head,*tail;
public:
    List(int k=3)
    {
        Counter=0;
        Max_Length=0;
        head=NULL;
        tail=NULL;
        Max_Length=k;
    }

     virtual void SetMax()
     {
         cout<<"Vveditee maksymal kolichestvo znacheniy:\n";
         cin>>Max_Length;
     }

     virtual void GetCounter()
     {
         cout<<"Kolichestvo elementov:\t"<<Counter<<"\n";
     }

   virtual bool IsEmpty()
    {
        return Counter==0;
    }

   virtual bool IsFull()
    {
        return Counter==Max_Length;
    }

    virtual void Add()
    {
        if(IsFull())
        {
            cout<<"Is full!\n";
        }
        else
        {
            Node *elem = new Node;
            cout<<"Vveditee imja:\n";
            cin>>elem->name;
            cout<<"Vveditee telefon:\n";
            cin>>elem->number;
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
        }
        Counter++;
    }

   virtual void Del(Node *tmp)
    {
        tmp->prev->next=tmp->next;
        delete tmp;
        Counter--;
    }

    virtual void ExtractQ()
    {
        if(IsEmpty())
        {
            cout<<"Is empty!\n";
        }
        else
        {
            Node *tmp = new Node;
            tmp=head;
            head=head->next;
          cout<<"Imja:\t"<<tmp->name<<"\nTelefon:\t"<<tmp->number<<"\n";
          Del(tmp);
        }

    }

        virtual void ExtractS()
    {
        if(IsEmpty())
        {
            cout<<"Is empty!\n";
        }
        else
        {
            Node *tmp = new Node;
            tmp=tail;
            tail=tail->prev;
          cout<<"Imja:\t"<<tmp->name<<"\nTelefon:\t"<<tmp->number<<"\n";
          Del(tmp);
        }

    }

} ;

class Stak: virtual public List
{
public:
    void Print()
    {
        if(head!=NULL)
        {
         Node *tmp = new Node;
        tmp=head;
        while(tmp!=NULL)
        {
        cout<<"Imja:\t"<<tmp->name<<"\nTelefon:\t"<<tmp->number<<"\n";
        tmp=tmp->next;
        }
        }
        else
        {
            cout<<"Access denied!";
        }

    }


    ~Stak()
    {
        if(head!=NULL)
        {
            Node *tmp=new Node;
            tmp=head;
            while(tmp!=head)
            {
                head=head->next;
                Del(tmp);
            }
        }
    }
};

class Que: virtual public List
{
 public:
    void Print()
    {
        if(head!=NULL)
        {
         Node *tmp = new Node;
        tmp=head;
        while(tmp!=NULL)
        {
        cout<<"Imja:\t"<<tmp->name<<"\nTelefon:\t"<<tmp->number<<"\n";
        tmp=tmp->next;
        }
        }
        else
        {
            cout<<"Access denied!";
        }

    }

        ~Que()
    {
        if(head!=NULL)
        {
            Node *tmp=new Node;
            tmp=head;
            while(tmp!=head)
            {
                head=head->next;
                Del(tmp);
            }
        }
    }
};

int main()
{
    int flag=0,flg=0;
    flg=menu(3,"Sozdat stek","Sozdat ochered","Vyhod");
    system("cls");
    switch(flg)
    {
    case 0:
        {
          Stak *s = new Stak;
               while(1)
               {
                flag=menu(6,"Dobavit element","Poschtat element","Print steka","Zadat max kolichestvo elementov","Print potochnogo kolichestva","Vyhod");
                switch(flag)
                {
                case 0:
                    {
                        system("cls");
                        s->Add();
                        system("cls");
                    }
                    break;
                case 1:
                    {
                        system("cls");
                        s->ExtractS();
                    }
                    break;
                case 2:
                    {
                        system("cls");
                        s->Print();
                    }
                    break;
                case 3:
                    {
                       system("cls");
                       s->SetMax();
                       system("cls");
                    }
                    break;
                case 4:
                    {
                      system("cls");
                       s->GetCounter();
                    }
                    break;
                case 5:
                    {
                        system("cls");

                       exit(0);
                    }
                }
               }
        }
        break;
                case 1:
                    {
                        Que *q = new Que;
                     while(1)
               {
                flag=menu(6,"Dobavit element","Poschitat element","Print ocheredi","Zadat max kolicestvo elementov","Print potochnogo kolichestva","Vyhod");
                switch(flag)
                {
                case 0:
                    {
                        system("cls");
                        q->Add();
                        system("cls");
                    }
                    break;
                case 1:
                    {
                        system("cls");
                        q->ExtractS();
                    }
                    break;
                case 2:
                    {
                        system("cls");
                        q->Print();
                    }
                    break;
                case 3:
                    {
                       system("cls");
                       q->SetMax();
                       system("cls");
                    }
                    break;
                case 4:
                    {
                      system("cls");
                       q->GetCounter();
                    }
                    break;
                case 5:
                    {
                        system("cls");

                       exit(0);
                    }
                }
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


    return 0;
}
