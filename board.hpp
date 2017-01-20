#ifndef TICTACTOE_BOARD_HPP
#define TICTACTOE_BOARD_HPP

#include <utility>
#include <vector>

using position = std::pair<int, int>;

class board
{
public:
    static constexpr int size = 3;
    char at(const position&) const;
    void set(const position&, char);
    std::vector<position> available_moves() const;
    bool wins() const;
    bool full() const;
private:
    char data[size][size] { ' ' };
    int move { 0 };
    void validate_position(const position&) const;
};

#endif
