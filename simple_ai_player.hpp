#ifndef TICTACTOE_SIMPLE_AI_PLAYER_HPP
#define TICTACTOE_SIMPLE_AI_PLAYER_HPP

#include "player.hpp"

namespace tictactoe
{
    class simple_ai_player : public player
    {
    public:
        simple_ai_player(char sign) : player(sign) {}
        virtual void move(board& board) const override;
    };
}

#endif //TICTACTOE_SIMPLE_AI_PLAYER_HPP
