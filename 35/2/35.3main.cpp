#include <iostream>
#include <windows.h>
#include <vector>
#include "menu.cpp"
#include <string>
#include <algorithm>

using namespace std;

class Student;
class Student_List;
ostream& operator<<(ostream& os, Student& s);

class Student
{
private:
    friend class Student_List;
    friend ostream& operator<<(ostream& os, Student& s);
string Name;
string Sur;
int Course;
public:
    Student()
    {
        Name = "name";
        Sur = "sur";
        Course = 0;
    }

    void SetValue()
    {

        cout<<"Vvedit imja studenta:\n";
        cin>>Name;
        cout<<"Vvedit familiu studenta:\n";
        cin>>Sur;
        cout<<"Vvedit kurs:\n";
        cin>>Course;
    }

  const char* GetName()
  {
      return Name.c_str();
  }

const char* GetSur()
  {
      return Sur.c_str();
  }

int GetCourse()
  {
      return Course;
  }
};



 ostream& operator<<(ostream& os,  Student& s)
    {

      os<<s.GetName();
      os<<"\t";
      os<<s.GetSur();
      os<<"\t";
      os<<s.GetCourse();
      os<<"\n";
    return os;
    }

class Student_List
{
private:
    friend class Student;
    vector<Student> List;
    unsigned int Counter;
public:
    void Add()
    {
     Student s;
        s.SetValue();
        List.push_back(s);
    }

   void SortByName()
    {
       Student buf;
       for(int j=0;j<List.size()-1;j++)
      {
        for(int i=0;i<List.size()-1;i++)
        {
            if(List[i].Name>List[i+1].Name)
            {
                swap(List[i],List[i+1]);
            }
        }
       }
 cout<<"Complete!\n";
    }

    void Print()
    {
        cout<<"Imja\tPrizv.\tKurs\n";
        for(int i=0;i<List.size();i++)
        {
            cout<<List[i];
        }
    }

    void SortBySur()
    {
        Student buf;
        for(int j=0;j<List.size()-1;j++)
        {
          for(int i=0;i<List.size()-1;i++)
        {
            if(List[i].Sur > List[i+1].Sur)
            {
               swap(List[i],List[i+1]);
            }
        }
        }

        cout<<"Complete!\n";
    }

    void SortByCourse()
    {
          for(int j=0;j<List.size();j++)
                {
                 for(int i=0;i<List.size();i++)
        {
            if(List[i].Course>List[i+1].Course)
            {
                swap(List[i],List[i+1]);
            }
        }
                }

         cout<<"Complete!\n";
    }
};


int main()
{
int flag=0;
Student_List ST_List;
while(1)
{
    flag = menu(6,"Dobavit element","Sortirovat po imjam", "Sortirovat po familiyam", "Sortirovat po kursam", "Vyvesty danie na ekran", "Vyhod");
    switch(flag)
    {
    case 0:
        {
            system("cls");
           ST_List.Add();
           system("cls");
        }
        break;
    case 1:
        {
            system("cls");
            ST_List.SortByName();
        }
        break;
    case 2:
        {
            system("cls");
           ST_List.SortBySur();
        }
        break;
    case 3:
        {
            system("cls");
            ST_List.SortByCourse();
        }
        break;
    case 4:
        {
            system("cls");
            ST_List.Print();
        }
        break;
    case 5:
        {
            exit(0);
        }
        break;
    }
}
    return 0;
}
