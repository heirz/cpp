#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
using namespace std;

class virajenie
{
private:
    string v;
    int l1, l2;
public:
    virajenie()
    {
        cout<<"vvedite virajenie:\n";
        cin>>v;
        l1=l2=0;
    }

    void Proc()
    {
        int d1=0,d2=0;

        string sub1, sub2;
        int ctr=1;
        double rz=0.0;
        char buf[50];
        string sym;
        if(!v.empty())
        {
            d1=v.find('(');
            d2=v.find(')');
           while((d1>-1)&&(d2>-1))
            {


                    string sub;
                    sub = v.substr(++d1,--d2-d1);
                    int mn=0;
                    cout<<sub.c_str()<<"\n";

                    for(int i=0;i<sub.length();i++)
                    {
                        if((sub[i]=='+')||(sub[i]=='-')||(sub[i]=='/')||(sub[i]=='*'))
                        {
                            mn=sub.length();
                            sub1=sub.substr(0,i);
                            sub2=sub.substr(i+1,mn-i);
                            sym=sub[i];
                            cout<<sub1.c_str()<<"\t"<<sub2.c_str()<<"\t"<<sym.c_str()<<"\n";

                            break;
                        }
                    }





            if(sym.compare("+")==0)
                {
                    rz=atof(sub1.c_str())+atof(sub2.c_str());
                }
            else if(sym.compare("-")==0)
                {
                    rz=atof(sub1.c_str())-atof(sub2.c_str());
                }
           else if(sym.compare("*")==0)
                {
                    rz=atof(sub1.c_str())*atof(sub2.c_str());

                }
         else if(sym.compare("/")==0)
                {
                    rz=atof(sub1.c_str())/atof(sub2.c_str());
                }
             else
                {
                    cout<<"default\n";
                }
               // sub1=boost::lexical_cast<std::string>(rz);
               sprintf(buf,"%f",rz);
                v=v.erase(--d1,d2-d1+3);
                v=v.insert(d1,buf);
                cout<<v<<"\n";

             d1=v.find('(');
            d2=v.find(')');
            }


          d1=v.find('*');
          while(d1>-1)
          {

              for(int i=d1;i<v.length();i++)
              {
                  if((v[i+1]=='+')||(v[i+1]=='-')||(v[i+1]=='*')||(v[i+1]=='/')||(v[i+1]=='\0'))
                  {
                      l2=i;
                      cout<<"l2: "<<l2<<"\n";
                      break;
                  }
                  }
                  for(int j=d1;j>0;j--)
                  {
                    if((v[j-1]=='+')||(v[j-1]=='-')||(v[j-1]=='*')||(v[j-1]=='/'))
                  {
                      l1=j;
                      break;
                  }
                  }
                   cout<<"erase: "<<l1<<"\t"<<l2<<"\n";
                  sub1=v.substr(l1,d1-l1);
                  sub2=v.substr(++d1,l2-d1);
                  cout<<sub1<<"\n"<<sub2<<"\n";
                   cout<<"erase: "<<l1<<"\t"<<l2<<"\n";

                  rz=atof(sub1.c_str())*atof(sub2.c_str());
                   sprintf(buf,"%f",rz);



                   v.erase(l1,l2-l1+1);
                   cout<<"post erase: "<<v<<"\n";
                   v=v.insert(l1,buf);
                  cout<<v<<"\n";

               d1=v.find('*');
              }


               d1=v.find('/');
          while(d1>-1)
          {

              for(int i=d1;i<v.length();i++)
              {
                  if((v[i+1]=='+')||(v[i+1]=='-')||(v[i+1]=='*')||(v[i+1]=='/')||(v[i+1]=='\0'))
                  {
                      l2=i;
                      cout<<"l2: "<<l2<<"\n";
                      break;
                  }
                  }
                  for(int j=d1;j>0;j--)
                  {
                    if((v[j-1]=='+')||(v[j-1]=='-')||(v[j-1]=='*')||(v[j-1]=='/'))
                  {
                      l1=j;
                      break;
                  }
                  }
                   cout<<"erase: "<<l1<<"\t"<<l2<<"\n";
                  sub1=v.substr(l1,d1-l1);
                  sub2=v.substr(++d1,l2-d1);
                  cout<<sub1<<"\n"<<sub2<<"\n";
                   cout<<"erase: "<<l1<<"\t"<<l2<<"\n";

                  rz=atof(sub1.c_str())/atof(sub2.c_str());
                   sprintf(buf,"%f",rz);



                   v.erase(l1,l2-l1+1);
                   cout<<"post erase: "<<v<<"\n";
                   v=v.insert(l1,buf);
                  cout<<v<<"\n";

               d1=v.find('/');
              }


               d1=v.find('+');
          while(d1>-1)
          {

              for(int i=d1;i<v.length();i++)
              {
                  if((v[i+1]=='+')||(v[i+1]=='-')||(v[i+1]=='*')||(v[i+1]=='/')||(v[i+1]=='\0'))
                  {
                      l2=i;
                      cout<<"l2: "<<l2<<"\n";
                      break;
                  }
                  }
                  for(int j=d1;j>0;j--)
                  {
                    if((v[j-1]=='+')||(v[j-1]=='-')||(v[j-1]=='*')||(v[j-1]=='/'))
                  {
                      l1=j;
                      break;
                  }
                  }
                   cout<<"erase: "<<l1<<"\t"<<l2<<"\n";
                  sub1=v.substr(l1,d1-l1);
                  sub2=v.substr(++d1,l2-d1);
                  cout<<sub1<<"\n"<<sub2<<"\n";
                   cout<<"erase: "<<l1<<"\t"<<l2<<"\n";

                  rz=atof(sub1.c_str())+atof(sub2.c_str());
                   sprintf(buf,"%f",rz);



                   v.erase(l1,l2-l1+1);
                   cout<<"post erase: "<<v<<"\n";
                   v=v.insert(l1,buf);
                  cout<<v<<"\n";

               d1=v.find('+');
              }

               d1=v.find('-');
          while(d1>-1)
          {

              for(int i=d1;i<v.length();i++)
              {
                  if((v[i+1]=='+')||(v[i+1]=='-')||(v[i+1]=='*')||(v[i+1]=='/')||(v[i+1]=='\0'))
                  {
                      l2=i;
                      cout<<"l2: "<<l2<<"\n";
                      break;
                  }
                  }
                  for(int j=d1;j>0;j--)
                  {
                    if((v[j-1]=='+')||(v[j-1]=='-')||(v[j-1]=='*')||(v[j-1]=='/'))
                  {
                      l1=j;
                      break;
                  }
                  }
                   cout<<"erase: "<<l1<<"\t"<<l2<<"\n";
                  sub1=v.substr(l1,d1-l1);
                  sub2=v.substr(++d1,l2-d1);
                  cout<<sub1<<"\n"<<sub2<<"\n";
                   cout<<"erase: "<<l1<<"\t"<<l2<<"\n";

                  rz=atof(sub1.c_str())-atof(sub2.c_str());
                   sprintf(buf,"%f",rz);



                   v.erase(l1,l2-l1+1);
                   cout<<"post erase: "<<v<<"\n";
                   v=v.insert(l1,buf);
                  cout<<v<<"\n";

               d1=v.find('-');
              }
          }




        }




};

int main()
{
virajenie vr;
vr.Proc();
    return 0;
}
