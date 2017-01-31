#include "simple_ai_player.hpp"

#include <iostream>
#include <chrono>
#include <random>

void simple_ai_player::move(board& board) const
{
    static std::mt19937 mt { static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) };
    std::vector<position> available_positions = board.available_positions();
    std::uniform_int_distribution<int> gen(0, available_positions.size() - 1);
    board.set(available_positions[gen(mt)], get_sign());
    std::cout << "\nSimple AI player " << get_sign() << " moves:" << std::endl;
}
