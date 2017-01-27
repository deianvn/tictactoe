#include "board.hpp"
#include "simple_ai_player.hpp"

#include <iostream>

void print_board(const board&);
void switch_players(simple_ai_player*&, simple_ai_player&, simple_ai_player&);

int main()
{
    board board;
    simple_ai_player p1 { 'X' }, p2 { 'O' };
    simple_ai_player* current_player = &p1;
    
    do
    {
        print_board(board);
        current_player->move(board);
        switch_players(current_player, p1, p2);
    }
    while (!board.full() && !board.wins());
    
    print_board(board);
    
    return 0;
}

void print_board(const board& board)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << ' ' << board.at(i, j);
        }
        
        std::cout << "\n";
    }
    
    std::cout << std::endl;
}

void switch_players(simple_ai_player*& current_player, simple_ai_player& p1, simple_ai_player& p2)
{
    if (current_player == &p1)
        current_player = &p2;
    else
        current_player = &p1;
}
