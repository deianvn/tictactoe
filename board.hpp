#ifndef TICTACTOE_BOARD_HPP
#define TICTACTOE_BOARD_HPP

#include <utility>
#include <vector>

namespace tictactoe
{
    using position = std::pair<int, int>;

    class board
    {
    public:
        static constexpr int size = 3;
        char at(const position& pos) const;
        char at(int x, int y) const;
        bool is_free(int x, int y);
        bool is_free(const position& pos);
        void set(const position& pos, char sign);
        void set(int x, int y, char sign);
        std::vector<position> available_positions() const;
        bool wins() const;
        bool full() const;
    private:
        char data[size][size] { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
        
        int move { 0 };
        void validate_position(int, int) const;
    };
}

#endif
