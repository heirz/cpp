#include <iostream>
#include <fstream>
#include <windows.h>
#include "menu.cpp"
#include <string.h>
using namespace std;

class D;

class node
{
protected:
    friend class D;
    char nazvanie[20], vlas[20], addr[50],rod[20];
    int tel;
    node *next;
public:
    void SetValue(char n[],char v[],char a[], char r[], int t)
    {
        next=NULL;
        tel=t;
        strcpy(nazvanie,n);
        strcpy(vlas,v);
        strcpy(addr,a);
        strcpy(rod,r);
    }
};

class D
{
private:
        friend class D;
    char naz[20], vl[20], ad[50],rd[20];
    int tl;
    node *head,*tail;
    int Count;
public:
    friend class node;
    D()
    {
        head=tail=NULL;
        Count=0;
    }

    void add()
    {
        cout<<"vvedite nazvanie firmy:\n";
        cin>>naz;
        cout<<"vvedite imja vldelca:\n";
        cin>>vl;
        cout<<"vvedite adres:\n";
        cin>>ad;
        cout<<"vvedite telefon:\n";
        cin>>tl;
        cout<<"vvedite rod deyatelnosti:\n";
        cin>>rd;
        node *elem = new node;
        if(head==NULL)
        {
          elem->SetValue(naz,vl,ad,rd,tl);
          head=tail=elem;
        }
        else
        {
            tail->next=elem;
            tail=elem;
         elem->SetValue(naz,vl,ad,rd,tl);
        }
        Count++;
    }
    void Print(node *s)
    {
        if(s==NULL)
        {
            node *tmp=new node;
            tmp=head;
            cout<<"firma\tvladelec\tadres\ttelefon\trod deyatelnosti\n";
            while(tmp!=NULL)
            {
                cout<<tmp->nazvanie<<"\t"<<tmp->vlas<<"\t"<<tmp->addr<<"\t"<<tmp->tel<<"\t"<<tmp->rod<<"\n";
                tmp=tmp->next;
            }
        }
        else
        {
         cout<<"firma\tvladelec\tadres\ttelefon\trod deyatelnosti\n";
         cout<<s->nazvanie<<"\t"<<s->vlas<<"\t"<<s->addr<<"\t"<<s->tel<<"\t"<<s->rod<<"\n";
        }
    }

    node* SearchForName(char name[])
    {
       node *tmp=new node;
            tmp=head;
         while(tmp!=NULL)
         {
             if(strcmp(name,tmp->nazvanie)==0)
                return tmp;
                else
             tmp=tmp->next;
         }

         return NULL;
    }

    node* SearchForOwner(char owner[])
    {
       node *tmp=new node;
            tmp=head;
         while(tmp!=NULL)
         {
             if(strcmp(owner,tmp->vlas)==0)
                return tmp;
                else
             tmp=tmp->next;
         }

         return NULL;
    }

        node* SearchForAct(char ac[])
    {
       node *tmp=new node;
            tmp=head;
         while(tmp!=NULL)
         {
             if(strcmp(ac,tmp->rod)==0)
                return tmp;
                else
             tmp=tmp->next;
         }

         return NULL;
    }

    node* SearchForTel(int tlp)
    {
       node *tmp=new node;
            tmp=head;
         while(tmp!=NULL)
         {
             if(tlp==tmp->tel)
                return tmp;
                else
             tmp=tmp->next;
         }

         return NULL;
    }

    ~D()
    {
     del();
    }

    void SaveToFile()
    {
        fstream file("data.txt",ios::out|ios::app);
               node *tmp=new node;
               int Size=0;
            tmp=head;
            while(tmp!=NULL)
            {
                Size=strlen(tmp->nazvanie);
               file.write((char*)&Size,sizeof(int));
               file.write((char*)&tmp->nazvanie,Size*sizeof(char));
               Size=strlen(tmp->vlas);
               file.write((char*)&Size,sizeof(int));
               file.write((char*)&tmp->vlas,Size*sizeof(char));
               Size=strlen(tmp->addr);
               file.write((char*)&Size,sizeof(int));
               file.write((char*)&tmp->addr,Size*sizeof(char));
               file.write((char*)&tmp->tel,sizeof(int));
               Size=strlen(tmp->rod);
               file.write((char*)&Size,sizeof(int));
               file.write((char*)&tmp->rod,Size*sizeof(char));
               tmp=tmp->next;
            }
            file.close();
    }

    void del()
    {
            node *tmp=new node;
            tmp=head;
            while(tmp!=NULL)
            {
                tmp=tmp->next;
                delete head;
                head=tmp;
            }
    }

    void LoadFromFile()
    {
        del();
        bool first=true;
        int temp=0;
        fstream file("data.txt",ios::in);
            while(!file.eof())
            {
              node *tmp=new node;
              if(first)
              {
                 tail=head=tmp;
                 first=false;
              }
              else
              {
                  tail->next=tmp;
                  tail=tmp;
              }
               file.read((char*)&temp,sizeof(int));
               file.read((char*)tmp->nazvanie,temp*sizeof(char));
               tmp->nazvanie[temp]='\0';
               file.read((char*)&temp,sizeof(int));
               file.read((char*)tmp->vlas,temp*sizeof(char));
               tmp->vlas[temp]='\0';
               file.read((char*)&temp,sizeof(int));
               file.read((char*)tmp->addr,temp*sizeof(char));
               tmp->addr[temp]='\0';
               file.read((char*)&tmp->tel,sizeof(int));
               file.read((char*)&temp,sizeof(int));
               file.read((char*)tmp->rod,temp*sizeof(char));
               tmp->rod[temp]='\0';
             }
            file.close();
    }


};


int main()
{
int tl1=0,flag=0;
char n1[20],rd1[20];
D d;
while(1)
{

    flag=menu(10,"vyhod","dobavit","poisk po nazvaniu","poisk po vladelcu","poisk po nomeru telefona","poisk po rodu deyatelnosti","pokazat vse zapysy","save v fail","zagruzit v fail","udalit vse");
    switch(flag)
    {
case 0:
    {
        exit(0);
        system("cls");
    }
    break;
case 1:
    {
        system("cls");
        d.add();
        system("cls");
    }
    break;
case 2:
    {
        system("cls");
        cout<<"vvedite nazvanie firmy:\n";
        cin>>n1;
        d.Print(d.SearchForName(n1));
    }
    break;
case 3:
    {
        system("cls");
       cout<<"vvedite vladelca firmy:\n";
        cin>>n1;
        d.Print(d.SearchForOwner(n1));
    }
    break;
case 4:
    {
        system("cls");
        cout<<"vvedit telefon firmy:\n";
        cin>>tl1;
        d.Print(d.SearchForTel(tl1));
    }
    break;
case 5:
    {
        system("cls");
        cout<<"vvedit rod deyatelnosti firmy:\n";
        cin>>rd1;
        d.Print(d.SearchForAct(rd1));
    }
    break;
case 6:
    {
        system("cls");
     d.Print(NULL);
    }
    break;

case 7:
    {
        system("cls");
     d.SaveToFile();
    }
    break;
case 8:
    {
        system("cls");
        d.LoadFromFile();
    }
    break;
case 9:
    {
        system("cls");
        d.del();
    }
    break;
}
}
    return 0;
}
