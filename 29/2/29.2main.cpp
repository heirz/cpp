#include <iostream>
#include <windows.h>
#include "menu.cpp"
#include <stdio.h>
#include <io.h>
#include <direct.h>
#include <string.h>
using namespace std;

char*d(char*s)
{
    for(int i=strlen(s);i>1;i--)
    {
        if(s[i]=='\\')
        {
            s[i+1]='\0';
        }
    }
    return s;
}

void del(char*path,bool flag=true)
{
    _finddata_t *info = new _finddata_t;
    long done=0;
    int fl=0;
   done=_findfirst(path,info);
    fl=done;
    if(flag==false)
    {
     fl=_findnext(done,info);
     fl=_findnext(done,info);
    }

     while(fl!=-1)
    {
       cout<<info->name<<"\n";
       //remove(strcat(path,info->name));
       //if(path[strlen(path)-1]!='\\')

 if((info->attrib==8208))
   {
       if(path[strlen(path)-1]=='\\')
      cout<<strcat(path,info->name)<<"\n";
      if(path[strlen(path)-1]=='*')
      {
         path=d(path);
         cout<<strcat(path,info->name)<<"\n";
      }
      if((info->name!=".*")&&(info->name!="..*")&&(info->name!=".")&&(info->name!=".."))
      {
          cout<<path<<"\n";
         if(_rmdir(path)==-1)
       {
           del(strcat(path,"\\\\*"),false);

       }
      }

   }
   else
   {
    path=d(path);
     remove(strcat(path,info->name));
     path=d(path);
   }
    fl=_findnext(done,info);
    }
    _findclose(fl);
    delete info;
}

int main(int argv, char * argc[])
{
if(argv==2)
del(argc[1]);
else
    cout<<"ne zadanyj kljuch!\n maska: delete.exe d:\\filename";
    return 0;
}
