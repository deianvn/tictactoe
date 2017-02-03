#include "human_player.hpp"
#include "basic_io.hpp"

void human_player::move(board& board) const
{
    int move, x, y;
    
    while (true)
    {
        std::cout << "Enter move 1-9\n> ";
        
        if (!next_int(std::cin, move) || move < 1 || move > 9)
        {
            std::cout << "Invalid move!" << std::endl;
            continue;
        };
        
        if (board.is_free(x = (move - 1) % 3, y = (move - 1) / 3)) break;
        
        std::cout << "Position is taken!" << std::endl;
    }
    
    board.set(x, y, get_sign());
    std::cout << "\nHuman player " << get_sign() << " moves:\n" << std::endl;
}
