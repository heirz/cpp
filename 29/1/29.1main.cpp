#include <iostream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <io.h>
#include "menu.cpp"
#include <direct.h>
#include <dirent.h>
#include <dir.h>
#include <shlobj.h>
using namespace std;

char* del(char*s)
{
    for(int i=strlen(s);i>1;i--)
    {
        if((s[i]=='/')||(s[i]=='\\'))
        {
            s[i+1]='\0';
            break;
        }
    }

    return s;
}



void copydf(char*path, char* sour, char* dest)
{
    _finddata_t *info= new _finddata_t;
    DIR *d;
    char *name;
    int fl=0;
    strcat(path,sour);
        long done = _findfirst(path,info);
    fl=done;
    while(fl!=-1)
    {
    if(info->attrib==8208)
    {
     path=del(path);
     strcat(dest,info->name);

     CreateDirectory(dest, NULL);
     strcat(dest,"\\");
     strcat(path,info->name);
     strcat(path,"\\");
     //cout<<info->size;
    // if(info->size>0)
    cout<<path<<"\n";
      for(int i=strlen(path);i>1;i--)
      {
          if(path[i]=='\\')
          {
              path[i+1]='\\';
              path[i+2]='\0';
          }
      }

      cout<<path;
     copydf(path,"*.*",dest);

      fl=_findnext(done,info);
    }
    else
    {
        if(info->attrib==8225)
        {
            int flg=menu(4,"perezapysat","propustyt","perezapysat dlja vseh", "zamena");
            switch(flg)
            {
            case 0:
                {
                            path=del(path);
            strcat(path,info->name);
            strcat(dest,info->name);
            d=opendir(dest);
            if(d==NULL)
                _mkdir(dest);
            else
                closedir(d);
                    strcmp(path,dest);
                     CopyFile(path,dest,false);
                }
                break;
            case 1:
                {
                   continue;
                }
                break;
            case 2:
                {
                  int f=0;
                 while(f!=-1)
                 {
                      strcmp(path,info->name);
                     CopyFile(path,dest,false);
                     f=_findnext(done,info);
                 }
                 return;
                }
                break;
            case 3:
                {
                    return;
                }
                break;
            }
        }
        else
        path=del(path);
            strcat(path,info->name);
            strcat(dest,info->name);
         d=opendir(dest);
            if(d==NULL)
            {

                  CreateDirectory(dest, NULL);
            }

            else
                closedir(d);

    CopyFile(path,dest,false)?cout<<"OK"<<"\n":cout<<"NO"<<"\n";
    fl=_findnext(done,info);
    }
     }
     _findclose(done);
     delete info;
}

int main(int argc, char * argv[])
{

if(argc==4)
{
  copydf(argv[1],argv[2],argv[3]);
}
else
    cout<<"ne vse kljuch!\nmaska: copy.exe d:\\dir1\\ filename d:\\dir2\\\n";


    return 0;
}
