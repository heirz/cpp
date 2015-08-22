#include <iostream>
#include "menu.cpp"
#include <windows.h>
#include <math.h>
using namespace std;

class Point_square
{
protected:
    int lx,ly,rx,ry;
public:

    Point_square()
    {
        lx=ly=rx=ry=0;
    }

    int& GS_RightX()
    {
        return rx;
    }

    int& GS_RightY()
    {
        return ry;
    }

    int& GS_LeftX()
    {
        return lx;
    }

    int& GS_LeftY()
    {
        return ly;
    }
};

class Line_sqare
{
protected:
    int Size;
public:
    Line_sqare()
    {
        Size=0;
    }

    int& GS_LineSize()
    {
        return Size;
    }
};

class Circle
{
protected:
    int radius;
public:
    Circle()
    {
        radius=0;
    }
    int& GS_Radius()
    {
        return radius;
    }
};

class Formula: public Circle, public Point_square, public Line_sqare
{
public:
    void RadiusLine()
    {
        cout<<"Radius: "<<(double)Size/2<<"\n";
    }

    void RadiusPoint()
    {
        double width=sqrt(pow((rx-lx),2)+pow((ry-ly),2));
        width=sqrt(width/2);
        cout<<"Radius: "<<width/2<<"\n";
    }

    void PointLineWidth()
    {

        double width=sqrt(pow((rx-lx),2)+pow((ry-ly),2));
        width=sqrt(width/2);
        cout<<"Dlinna storony kvadrata: "<<width<<"\n";
    }

    void SquareArea()
    {
        cout<<"Ploschad kvadrata: "<<pow((radius*2),2)<<"\n";
    }

    void SquareArea(int)
    {
        double width=sqrt(pow((rx-lx),2)+pow((ry-ly),2));
        width=sqrt(width/2);
        cout<<"Ploschad kvadrata: "<<pow(width,2)<<"\n";
    }

    void CircleArea()
    {
        cout<<"Ploschad kruga: "<<pow((((double)Size/2)*3.14),2)<<"\n";
    }

    void CircleArea(int)
    {
        double width=sqrt(pow((rx-lx),2)+pow((ry-ly),2));
        width=sqrt(width/2);
        cout<<"Ploschad kruga: "<<pow(((width/2)*3.14),2)<<"\n";
    }

};

int main()
{
    Formula F;
    int flag=0;
    while(1)
    {

        flag=menu(10,"vyhod","zadat kvadrat (tochkamy)","zadat kvadrat (dlinnoy storony)", "poshitat radius vpysanogo kruga po dlinne storony","poshitat radius po koordynatah tochok vershyn", "poshitat dlinnu storony za koordynatamu vershyn", "poshitat ploschad kvadrata za storonoju","poshitat ploschad kvadrata za koordynatamy vershyn","poshitat ploschad vpysanogo kruga za dlinnoy storony kvadrata","poshitat ploschad vpysanogo kruga za koordynatamy vershyn kvadrata");
        switch(flag)
        {
        case 0:
            {
                system("cls");
                exit(0);
            }
            break;
        case 1:
            {
                system("cls");
               cout<<"vvedite koordynaty livoji verhney vershyny kvadrata:\n";
               cin>>F.GS_LeftX()>>F.GS_LeftY();
               cout<<"vvedite koordynaty pravoji nyzney vershyny kvadrata:\n";
                cin>>F.GS_RightX()>>F.GS_RightY();
                system("cls");
            }
            break;
        case 2:
            {
                system("cls");
                cout<<"vvedite dlinnu storony kvadrata:\n";
                cin>>F.GS_LineSize();
                system("cls");
            }
            break;
        case 3:
            {
                system("cls");
                F.RadiusLine();
            }
            break;
        case 4:
            {
                system("cls");
                F.RadiusPoint();
            }
            break;
        case 5:
            {
                system("cls");
                F.PointLineWidth();
            }
            break;
        case 6:
            {
                system("cls");
                F.SquareArea();
            }
            break;
        case 7:
            {
                system("cls");
                F.SquareArea(1);
            }
            break;
        case 8:
            {
                system("cls");
                F.CircleArea();
            }
            break;
        case 9:
            {
                system("cls");
                F.CircleArea(1);
            }
            break;
        }
    }

    return 0;
}
