#include "board.hpp"

namespace tictactoe
{
    char board::at(int x, int y) const
    {
        validate_position(x, y);
        return data[convert_2d_to_1d_coordinates(x, y)];
    }

    char board::at(const position& pos) const
    {
        return at(pos.first, pos.second);
    }

    bool board::is_free(int x, int y) const
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

    bool board::is_free(const position& pos) const
    {
        is_free(pos.first, pos.second);
    }

    void board::set(int x, int y, char sign)
    {
        validate_position(x, y);
        data[convert_2d_to_1d_coordinates(x, y)] = sign;
        ++move;
    }

    void board::set(const position& pos, char sign)
    {
        return set(pos.first, pos.second, sign);
    }

    std::vector<position> board::available_positions() const
    {
        std::vector<position> v;

        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                if (at(j, i) == ' ')
                    v.push_back(std::make_pair(j, i));

        return v;
    }

    bool board::full() const
    {
        return move >= SIZE * SIZE;
    }

    bool board::wins() const
    {
        char s1, s2, s3;

        for (int i = 0; i < SIZE; i++)
        {
            s1 = at(0, i);
            s2 = at(1, i);
            s3 = at(2, i);

            if (s1 != ' ' && s1 == s2 && s2 == s3) return true;

            s1 = at(i, 0);
            s2 = at(i, 1);
            s3 = at(i, 2);

            if (s1 != ' ' && s1 == s2 && s2 == s3) return true;
        }

        s1 = at(1, 1);

        if (s1 == ' ') return false;

        for (int i = 0; i < SIZE; i+= 2)
        {
            s2 = at(0, i);
            s3 = at(2, 2 - i);

            if (s1 != ' ' && s1 == s2 && s2 == s3) return true;
        }

        return false;
    }

    void board::validate_position(int x, int y) const
    {
        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
        {
            throw std::exception {};
        }
    }

    int board::convert_2d_to_1d_coordinates(int x, int y) const
    {
        return y * SIZE + x;
    }
}
