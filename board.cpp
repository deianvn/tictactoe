#include "board.hpp"

namespace tictactoe
{
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
        
        return v;
    }

    bool board::full() const
    {
        return move >= size * size;
    }

    bool board::wins() const
    {
        char s1, s2, s3;
        
        for (int i = 0; i < 3; i++)
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
        
        for (int i = 0; i < 3; i+= 2)
        {
            s2 = at(0, i);
            s3 = at(2, 2 - i);
            
            if (s1 != ' ' && s1 == s2 && s2 == s3) return true;
        }
        
        return false;
    }

    void board::validate_position(int x, int y) const
    {
        if (x < 0 || x >= size || y < 0 || y >= size)
        {
            throw std::exception {};
        }
    }
}
