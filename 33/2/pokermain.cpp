#include <iostream>
#include "menu.cpp"
#include <time.h>
#include <windows.h>
using namespace std;

class Player
{
private:
    int Cards[2];
    int Cash;
public:
    Player()
    {

        Cash = 750;
    }

    void SetCards()
    {
        for(int i = 0; i < 2; i++)
        {
            srand(time(NULL));
            Sleep(500);
            Cards[i] = 2+rand()%13;
        }
    }

    int GetFirstCard()
    {
        return Cards[0];
    }

    int GetSecondCard()
    {
        return Cards[1];
    }
    int& GS_Cash()
    {
        return Cash;
    }
};

class Game
{
private:
    int GenCard[5];
    int Rot;
    Player People;
    Player Komp;
public:
    Game()
    {
        for(int i = 0; i < 5; i++)
        {
           GenCard[i] = 0;
        }
        Rot = 0;
    }

    void SetCards()
    {
      for(int i = 0; i < 5; i++)
        {
            srand(time(NULL));
            Sleep(500);
            GenCard[i] = 2 + rand()%13;

        }
        People.SetCards();
        Komp.SetCards();
    }

    int Round()
    {
        int tmp = 0;
        bool IsEndRound = false;
        bool dv = false;
        bool pv = false;
        srand(time(NULL));
        Sleep(500);
        tmp = 1 + rand()%10;

        switch(tmp)
        {
        case 1:
            {
                cout<<"Diller - pas!\n";
                return 1;
            }
            break;
        case 2:
            {
                if(Komp.GS_Cash() < 50)
                    return 3;
                cout<<"Diller idet v vabank!\n";
                Rot = Rot + Komp.GS_Cash();
                Komp.GS_Cash() = 0;
                dv=true;
            }
            break;
        case 3:
        case 4:
            {
                cout<<"Diller zakancivaet hod!\n";
                IsEndRound = true;
            }
            break;
        default:
            {
                if(Komp.GS_Cash() < 50)
                    return 3;
                cout<<"Diller - stavka!\n";
                Rot = Rot + 50;
                Komp.GS_Cash() = Komp.GS_Cash() - 50;
            }
            break;
        }
        cout<<"Vyberite:\n";
        tmp = menu(4,"Pas","Vabank","Stavka","Konec hoda");
        switch(tmp)
        {
        case 0:
            {
                cout<<"Vy - pas!\n";
                return -1;
            }
            break;
        case 1:
            {
                if(People.GS_Cash() < 50)
                    return -3;
                cout<<"Vy idete v vabank!\n";
                Rot = Rot + People.GS_Cash();
                People.GS_Cash() = 0;
                pv=true;
            }
            break;
        case 2:
            {
                if(People.GS_Cash() < 50)
                    return -3;
                cout<<"Vy - stavka!\n";
                Rot = Rot + 50;
                People.GS_Cash() = People.GS_Cash() - 50;
            }
            break;
        case 3:
            {
                cout<<"Vy zakonchyly hod!\n";
                IsEndRound = true;
            }
            break;
        }
        if (dv)
            return 4;
        if(pv)
            return -4;
        if(IsEndRound)
            return 2;
        return 0;
    }

    void Flop()
    {
        system("cls");
        cout<<"Flop:\n\t";
        for(int i = 0; i < 3; i++)
        {
            cout<<GenCard[i]<<"\t";
        }
        cout<<"\n";
    }

    void River()
    {
        system("cls");
        cout<<"River:\n\t";
        for(int i = 0; i < 4; i++)
        {
            cout<<GenCard[i]<<"\t";
        }
        cout<<"\n";
    }

    void Turn()
    {
        system("cls");
        cout<<"Turn:\n\t";
        for(int i = 0; i < 5; i++)
        {
            cout<<GenCard[i]<<"\t";
        }
        cout<<"\n";
    }

    bool Unique(Player Plr)
    {
        int tmp[7];

        for(int i = 0; i < 7; i++)
        {
            tmp[i] = 0;
        }

        tmp[0] = Plr.GetFirstCard();
        tmp[1] = Plr.GetSecondCard();

        for(int i = 2; i < 5; i++)
        {
            tmp[i] = GenCard[i-2];
        }

        for(int i = 0; i < 7; i++)
        {
            for(int j = 0; j < 7; j++)
            {
                if(i != j)
                {
                    if(tmp[i] == tmp[j])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    int Max(int a[])
    {
        int _max = 0;
        for(int i = 0; i < 7; i++)
        {
            if(a[i] > _max)
            {
                _max = a[i];
            }
        }
        return _max;
    }

    int CardCombination(int a[])
    {
        int Counters[7], bal=0;
        for(int i=0;i<7;i++)
            Counters[i] = 0;
        for(int i=0; i<7; i++)
        {
            for(int j=0; j<7;j++)
            {
                if(a[i]==a[j])
                {
                    Counters[i]++;
                }
            }
        }

        for(int i=0;i<7;i++)
        {
            if(Counters[i]==2)
            {
              bal++;
            }
            else if(Counters[i]==3)
            {
                bal++;
            }
            else if(Counters[i]==4)
            {
                bal++;
            }
        }

        switch(bal)
        {
        case 1:
        case 2:
            {
                cout<<"'para'!\n";

            }
            break;
        case 3:
        case 5:
        case 4:
            {
                cout<<"'dve pary'!\n";
            }
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            {
                cout<<"'trijka'!\n";
            }
            break;
        case 10:
        case 11:
            {
                cout<<"'full house'!\n";
            }
            break;
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
            {
                cout<<"'kare'!\n";
            }
            break;
        default:
            {
                if(bal == 18)
                {
                    cout<<"'trijka'!\n";
                    bal=9;
                }
                else if(bal>16)
                {
                    cout<<"'kare'!\n";
                    bal=16;
                }
            }
        }

       return bal;
    }

    bool Royal(int a[])
    {
     int c=0, mas[] = {10,11,12,13,14};
     for(int i=0;i<7;i++)
     {
         if(a[i]==mas[c])
         {
             c++;
             i=0;
             if(c==5)
             {
                 return true;
             }
         }
     }
        return false;
    }

    void FindWinner()
    {

        int KC[7], PC[7], PC1 = 0, KC1=0;
        KC[0] = Komp.GetFirstCard();
        KC[1] = Komp.GetSecondCard();

        for(int i = 2; i < 5; i++)
        {
            KC[i] = GenCard[i-2];
        }
        PC[0] = People.GetFirstCard();
        PC[1] = People.GetSecondCard();

        for(int i = 2; i < 5; i++)
        {
            PC[i] = GenCard[i-2];
        }
        int t=0;
        if((this->Unique(Komp)) && (this->Unique(Komp)))
        {


            if(Royal(KC))
            {
                cout<<"U dillera 'Rojal'!\n";
                KC1=100;
            }
            else
            {
                cout<<"U dillera 'Starshaya karta!'\n";
                KC1=1;
            }


             if(Royal(PC))
            {
                cout<<"U vas 'Rojal'!\n";
                PC1=100;
            }
            else
            {
                cout<<"U vas 'Starshaya karta!'\n";
                PC1=1;
            }

            if(PC1>KC1)
            {
                People.GS_Cash() = People.GS_Cash()+Rot;
                cout<<"Vy vygraly!\n";
                Rot = 0;
            }
            else
            {
                Komp.GS_Cash() = Komp.GS_Cash()+Rot;
                cout<<"Diller vygral!\n";
                Rot = 0;
            }
        }
        else if(!(this->Unique(People))&& !(this->Unique(Komp)))
        {
            KC1 = CardCombination(KC);
            PC1 = CardCombination(PC);
            cout<<"kc pc "<<KC1<<"\t"<<PC1<<"\n";
            if(KC1<PC1)
            {
                People.GS_Cash() = People.GS_Cash()+Rot;
                cout<<"Vy vygraly!\n";
                Rot = 0;
            }
            else
            {
                Komp.GS_Cash() = Komp.GS_Cash()+Rot;
                cout<<"Diller vygrav!\n";
                Rot = 0;
            }
        }
        else
        {
            if(this->Unique(Komp))
            {
             if(Royal(KC))
            {
                cout<<"U dillera 'Rojal'!\n";
                KC1=100;
            }
            else
            {
                cout<<"U dillera 'Starsha karta!'\n";
                KC1=1;
            }
            cout<<"U vas ";
            PC1 = CardCombination(PC);
            }
            else
            {
             if(Royal(PC))
            {
                cout<<"U vas 'Rojal'!\n";
                PC1=100;
            }
            else
            {
                cout<<"U vas 'Starshaya karta!'\n";
                PC1=1;
            }
            cout<<"U dillera ";
            KC1 = CardCombination(KC);
            }

             if(KC1<PC1)
            {
                People.GS_Cash() = People.GS_Cash()+Rot;
                Rot = 0;
                cout<<"Vy vygraly!\n";
            }
            else
            {
                Komp.GS_Cash() = Komp.GS_Cash()+Rot;
                Rot = 0;
                cout<<"Diller vygral!\n";
            }
        }
    }

    void Show()
    {
        cout<<"Vashi karty "<<People.GetFirstCard()<<"\t"<<People.GetSecondCard()<<"\n";
        cout<<"U vas "<<People.GS_Cash()<<"$\n";
        cout<<"Rot: "<<Rot<<"$\n";
    }
};

int main()
{
    int flag=0, rnd=0, ctr=0;
    Game g;
while(1)
{
    flag = menu(3,"Igra","Help","Vyhod");
    switch(flag)
    {
    case 0:
        {
            system("cls");
            g.SetCards();
            while(1)
            {

                rnd = g.Round();
                switch(rnd)
                {
                case 1:
                case -1:
                case 3:
                case -3:
                    {
                        exit(0);
                    }
                    break;
                case 4:
                case -4:
                    {
                        g.FindWinner();
                        exit(0);
                    }
                    break;
                default:
                    {

                     if(ctr==1)
                     {
                         g.Flop();
                         g.Show();
                     }
                     else if(ctr==2)
                     {
                         g.River();
                         g.Show();
                     }
                     else if(ctr>2)
                     {
                         g.Turn();
                         g.Show();
                         g.FindWinner();
                         exit(0);
                     }
                     ctr++;
                    }
                }
            }
        }
        break;
    case 1:
        {
            system("cls");
            cout<<"Rozmetka:\nKarty ot 11-14  starshie karty ot valeta do tuza. \nDrugie karty sovpadaut.\n";
        }
        break;
    case 2:
        {
            system("cls");
            exit(0);
        }

    }
}
    return 0;
}
