#ifndef TICTACTOE_SIMPLE_AI_PLAYER_HPP
#define TICTACTOE_SIMPLE_AI_PLAYER_HPP

#include "player.hpp"

class simple_ai_player : public player
{
    void move(board& board) const;
};

#endif
