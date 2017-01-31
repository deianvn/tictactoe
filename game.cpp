#include "game.hpp"
#include <iostream>

void game::play()
{
    std::cout << "Tic Tac Toe\n" << std::endl;
    
    do
    {
        draw_board();
        current_player->move(b);
        switch_player();
    }
    while (!b.full() && !b.wins());
    
    draw_board();
    switch_player();
    
    if (b.wins())
    {
        std::cout << "Player " << current_player->get_sign() << " wins!" << std::endl;
    }
    else
    {
        std::cout << "Game is tie!" << std::endl;
    }
}

void game::switch_player()
{
    if (current_player == &p1)
        current_player = &p2;
    else
        current_player = &p1;
}

void game::draw_hr() const
{
    std::cout << "-------------" << std::endl;
}

void game::draw_board() const
{
    for (int i = 0; i < 3; i++)
    {   
        draw_hr();
        
        for (int j = 0; j < 3; j++)
        {
            std::cout << "| " << b.at(j, i) << " ";
        }
        
        std::cout << "|\n";
    }
    
    draw_hr();
    std::cout << std::endl;
}
