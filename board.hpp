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
    char at(int, int) const;
    bool is_free(int, int);
    bool is_free(const position&);
    void set(const position&, char);
    void set(int, int, char);
    std::vector<position> available_positions() const;
    bool wins() const;
    bool full() const;
private:
    char data[size][size] { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    
    int move { 0 };
    void validate_position(int, int) const;
};

#endif
