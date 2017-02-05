#ifndef TICTACTOE_SELF_LEARNING_AI_PLAYER_HPP
#define TICTACTOE_SELF_LEARNING_AI_PLAYER_HPP

#include "player.hpp"

#include <string>
#include <queue>

namespace tictactoe
{
    class self_learning_ai_player : public player
    {
    public:
        self_learning_ai_player(char sign, std::string brain_data_path) : player(sign), brain_data_path(brain_data_path)
        {
            load_brain_data();
        }

        virtual void move(board& board) const override;
    private:
        void load_brain_data();
        void save_brain_data() const;

        std::string brain_data_path;
        std::priority_queue<std::string> brain {};
    };
}

#endif //TICTACTOE_SELF_LEARNING_AI_PLAYER_HPP
