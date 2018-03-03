#include <iostream>
#include <cstdlib>
#include<ctime>
#include "Board.h"
#include "Board.ccp"
using namespace std;
Board B; int h=88;
class Player
{
    char ch;
public:
    Player(const char);
    bool isWin();
    //idDraw();
};
Player::Player(const char ch)
{
    this->ch=ch;
}
bool Player::isWin()
{
    return B.rowcheck(ch);
}
class Comp
{
    const char ch;
public:
    Comp():ch('X'){};
    char sign()
    {
        return ch;
    }
    void computer();
    bool isWin();
    bool isWin(char);
};
void Comp::computer()
{
    int num;
    srand(time(0));
    h=B.smart(h);
    if(h==88)
    {
        s:num=(rand() %9 + 1);
        h=num;
        if(!B.add_sign(num,'0')||num>9||num<=0)
            {
                goto s;
            }
    }
}
bool Comp::isWin()
{
    return B.rowcheck('0');
}
bool Comp::isWin(char ch)
{
    return B.rowcheck(ch);
}
int main()
{
    int a;
    cout<<"Enter One Of The Choices Below"<<endl;
    cout<<"1. "<<"Play Against Machine"<<endl;
    cout<<"2. "<<"Play Against A Human"<<endl;
    cin>>a;
    if(a==1)
    {
        B.printboard();
        Comp C;
        int num;
        while(true)
        {
            cout<<"Enter Number Of The Block Where You Want To Put X"<<endl;
            cin>>num;
            s0:if
            (!B.add_sign(num,C.sign())||num>9||num<=0)
            {
                cout<<"Enter Number Again:\t";
                cin>>num;
                goto s0;
            }
            cout<<endl;
            B.printboard();
            if (C.isWin(C.sign()))
                {
                    cout<<"You Wins"<<endl;
                    return 0;
                }
            if (B.isDraw())
                {
                    cout<<"It's A Draw !!"<<endl;
                    return 0;
                }
            C.computer();
            cout<<endl;
            B.printboard();
            if (C.isWin())
                {
                    cout<<"Computer Wins"<<endl;
                    return 0;
                }
            if (B.isDraw())
                {
                    cout<<"It's A Draw !!"<<endl;
                    return 0;
                }
            }
    }
    else if(a=2)
    {
        B.printboard();
        Player P1('X'),P2('0');
        int num;
    while (true)
    {
    cout<<"It's Player 1 Turn Enter Where You Want To Put X:\t";
    cin>>num;
    s1:if (!B.add_sign(num,'X')||num>9||num<=0)
    {
        cout<<"Enter Number Again:\t";
        cin>>num;
        goto s1;
    }
    cout<<endl;
    B.printboard();
    if (P1.isWin())
        {
            cout<<"Player 1 Wins"<<endl;
            return 0;
        }
    if (B.isDraw())
    {
        cout<<"It's A Draw !!"<<endl;
        return 0;
    }
    cout<<"It's  Player 2 Turn Enter Where You Want To Put 0:\t";
    cin>>num;
    s2:if (!B.add_sign(num,'0')||num<=0||num>9)
    {
        cout<<"Enter Number Again:\t";
        cin>>num;
        goto s2;
    }
    cout<<endl;
    B.printboard();
    if (P2.isWin())
        {
            cout<<"Player 2 Wins"<<endl;
            return 0;
        }
    if (B.isDraw())
    {
        cout<<"It's A Draw !!"<<endl;
        return 0;
    }
    }
    }
    return 0;
}
