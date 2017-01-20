#include "simple_ai_player.hpp"

#include <chrono>
#include <random>

void simple_ai_player::move(board& board) const
{
    static std::mt19937 mt { static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) };
    std::vector<position> available_moves = board.available_moves();
    std::uniform_int_distribution<int> gen(0, available_moves.size() - 1);
    board.set(available_moves[gen(mt)], get_sign());
}
