#include <iostream>
#include "menu.cpp"
#include <windows.h>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Table
{
private:
    vector <int> tab[10];
public:
    Table()
    {
        for(int i=0;i<10;i++)
        {
            tab[i].resize(10,1);
        }
    }

    void CreateTab()
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                tab[i][j]=i*j;
            }
        }
    }

    void Print()
    {
        for(int i=1;i<10;i++)
        {
           copy(++tab[i].begin(), tab[i].end(), ostream_iterator <int>(cout,"\t"));
            cout<<"\n";
        }
    }

};

int main()
{
Table T;
T.CreateTab();
T.Print();
    return 0;
}
