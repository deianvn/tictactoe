#include "board.hpp"

char board::at(const position& pos) const
{
    validate_position(pos);
    return data[pos.first][pos.second];
}

void board::set(const position& pos, char sign)
{
    validate_position(pos);
    data[pos.first][pos.second] = sign;
    ++move;
}

std::vector<position> board::available_moves() const
{
    std::vector<position> v;
    
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (data[i][j] != ' ')
                v.push_back(std::make_pair(i, j));
    
    return std::move(v);
}

bool board::full() const
{
    return move >= size * size;
}

bool board::wins() const
{
    // brute force win checking
    return
        (data[0][0] != ' ' &&
            (data[0][0] == data[0][1] && data[0][1] == data[0][2]) ||
            (data[0][0] == data[1][1] && data[1][1] == data[2][2]) ||
            (data[0][0] == data[1][0] && data[1][0] == data[2][0])) ||
        (data[2][2] != ' ' &&
            (data[2][2] == data[1][2] && data[1][2] == data[0][2]) ||
            (data[2][2] == data[2][1] && data[2][1] == data[2][0])) ||
        (data[1][1] != ' ' && data[0][2] == data[1][1] && data[1][1] == data[2][0]);
}

void board::validate_position(const position& pos) const
{
    if (pos.first < 0 || pos.first >= size || pos.second < 0 || pos.second >= size)
    {
        throw std::exception {};
    }
}
