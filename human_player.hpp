#ifndef TICTACTOE_HUMAN_PLAYER_HPP
#define TICTACTOE_HUMAN_PLAYER_HPP

#include "player.hpp"

namespace tictactoe
{
    class human_player : public player
    {
    public:
        human_player(char sign) : player(sign) {}
        virtual void move(board& board) const override;
    };
}

#endif //TICTACTOE_SIMPLE_AI_PLAYER_HPP
