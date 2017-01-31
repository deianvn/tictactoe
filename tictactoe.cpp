#include "simple_ai_player.hpp"
#include "human_player.hpp"
#include "game.hpp"
#include <iostream>

int main()
{
    simple_ai_player p1 { 'X' };
    human_player p2 { 'O' };
    game g { p1, p2 };
    g.play();
    
    return 0;
}
