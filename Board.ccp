void Board::printboard()
{
    system("CLS");
    cout<<arr[0]<<"|"<<arr[1]<<"|"<<arr[2]<<endl;
    cout<<arr[3]<<"|"<<arr[4]<<"|"<<arr[5]<<endl;
    cout<<arr[6]<<"|"<<arr[7]<<"|"<<arr[8]<<endl;
}
int Board::smart(int h)
{
    for(int j=1;j<=9;++j)
    {
        if(add_sign(j,'0'))
            {
                if(rowcheck('0'))
                    {
                        arr[j-1]='0';
                        return j;
                    }
                arr[j-1]='_';
            }

    }
    for(int j=1;j<=9;++j)
    {
        if(add_sign(j,'X'))
            {
                if(rowcheck('X'))
                    {
                        arr[j-1]='0';
                        return j;
                    }
                arr[j-1]='_';
            }

    }
    if (h!=88)
    {
        int i;
        int choice[4]={h+1,h+3,h-3,h-1};
        sx:i=rand()%4;
        if (!add_sign(choice[i],'0') && choice[i]<=0 && choice[i]>9)
            goto sx;
        return choice[i];
    }
    return 88;
}
bool Board::add_sign(const int x,const char ch)
{
    if (arr[x-1]=='X'|| arr[x-1]=='0') {return false;}
    else
    {
        arr[x-1]=ch;
        return true;
    }
}
bool Board::rowcheck(const char ch)
{
    if ((arr[0]==ch && arr[1]==ch && arr[2]==ch) || (arr[3]==ch && arr[4]==ch && arr[5]==ch) || (arr[6]==ch && arr[7]==ch && arr[8]==ch)|| (arr[0]==ch && arr[3]==ch && arr[6]==ch) || (arr[1]==ch && arr[4]==ch && arr[7]==ch) || (arr[2]==ch && arr[5]==ch && arr[8]==ch) || (arr[0]==ch && arr[4]==ch && arr[8]==ch) || (arr[2]==ch && arr[4]==ch && arr[6]==ch))
        return true;
    else
        return false;
}
bool Board::isDraw()
{
    if(arr[0]=='_'||arr[1]=='_'||arr[2]=='__'||arr[3]=='_'||arr[4]=='_'||arr[5]=='_'||arr[6]=='_'||arr[7]=='_'||arr[8]=='_')
    {
        return false;
    }
    return true;
}

