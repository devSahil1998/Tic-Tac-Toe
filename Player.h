#include "Board.h"
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

