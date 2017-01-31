#include "board.hpp"

char board::at(int x, int y) const
{
    validate_position(x, y);
    return data[y][x];
}

char board::at(const position& pos) const
{
    return at(pos.first, pos.second);
}

bool board::is_free(int x, int y)
{
    try
    {
        validate_position(x, y);
    }
    catch (std::exception& e)
    {
        return false;
    }
    
    return at(x, y) == ' ';
}

bool board::is_free(const position& pos)
{
    is_free(pos.first, pos.second);
}

void board::set(int x, int y, char sign)
{
    validate_position(x, y);
    data[y][x] = sign;
    ++move;
}

void board::set(const position& pos, char sign)
{
    return set(pos.first, pos.second, sign);
}

std::vector<position> board::available_positions() const
{
    std::vector<position> v;
    
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (data[i][j] == ' ')
                v.push_back(std::make_pair(j, i));
    
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
            ((data[0][0] == data[0][1] && data[0][1] == data[0][2]) ||
            (data[0][0] == data[1][1] && data[1][1] == data[2][2]) ||
            (data[0][0] == data[1][0] && data[1][0] == data[2][0]))) ||
        (data[2][2] != ' ' &&
            ((data[2][2] == data[1][2] && data[1][2] == data[0][2]) ||
            (data[2][2] == data[2][1] && data[2][1] == data[2][0]))) ||
        (data[1][1] != ' ' &&
            ((data[0][2] == data[1][1] && data[1][1] == data[2][0]) ||
            (data[1][1] == data[0][1] && data[1][1] == data[2][1]) ||
            (data[1][1] == data[1][0] && data[1][1] == data[2][1])));
}

void board::validate_position(int x, int y) const
{
    if (x < 0 || x >= size || y < 0 || y >= size)
    {
        throw std::exception {};
    }
}
