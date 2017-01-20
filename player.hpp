#ifndef TICTACTOE_PLAYER_HPP
#define TICTACTOE_PLAYER_HPP

#include "board.hpp"

class player
{
public:
    player(char sign) : sign(sign) {};
    char get_sign() const { return sign; }
    virtual void move(board&) const = 0;
private:
    char sign;
};

#endif
