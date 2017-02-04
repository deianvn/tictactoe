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
        static constexpr int SIZE = 3;
        
        char at(const position& pos) const;
        char at(int x, int y) const;
        bool is_free(int x, int y) const;
        bool is_free(const position& pos) const;
        void set(const position& pos, char sign);
        void set(int x, int y, char sign);
        std::vector<position> available_positions() const;
        bool wins() const;
        bool full() const;
    private:
        char data[SIZE * SIZE] { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
        
        int move { 0 };
        void validate_position(int x, int y) const;
		int convert_2d_to_1d_coordinates(int x, int y) const;
    };
}

#endif

