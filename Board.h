#include <iostream>
using namespace std;
class Board
{
    char arr[9]={'_','_','_',
                 '_','_','_',
                 '_','_','_'};
public:
    void printboard() ;
    bool add_sign(const int,const char);
    bool rowcheck(const char ch);
    bool isDraw();
    int smart(int);
};
