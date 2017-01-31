#ifndef TICTACTOE_GAME_HPP
#define TICTACTOE_GAME_HPP

#include "player.hpp"

class game
{
public:
    inline game(player& p1, player& p2) : p1(p1), p2(p2)
    {
        current_player = &p1;
    };
    
    void play();
private:
    void switch_player();
    void draw_hr() const;
    void draw_board() const;
    
    player &p1, &p2, *current_player;
    board b;
};

#endif //TICTACTOE_GAME_HPP
