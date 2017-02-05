#include "self_learning_ai_player.hpp"
#include "string_utils.hpp"

#include <iostream>
#include <fstream>
#include <string>

namespace tictactoe
{
    void self_learning_ai_player::move(board& board) const
    {

    }

    void self_learning_ai_player::load_brain_data()
    {
        std::ifstream fin(brain_data_path);

        if (fin.is_open())
        {

        }
    }

    void self_learning_ai_player::save_brain_data() const
    {

    }
}
