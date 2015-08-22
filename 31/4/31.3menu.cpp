#include <iostream>
#include <stdarg.h>
#include <windows.h>
using namespace std;
int menu(int numerosity, ...)
{
    int flag=0;
    va_list param;
    va_start(param,numerosity);
    while(1)
    {

    cout<<"==========MENU==========\n";
    for(int i=0;i<numerosity;i++)
    {
        cout<<i<<"\t"<<va_arg(param,char*)<<"\n";
    }
    cin>>flag;
    if((flag>-1)&&(flag<numerosity))
    {
        va_end(param);
        return flag;
    }

    }
}

