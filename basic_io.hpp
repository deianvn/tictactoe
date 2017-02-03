#ifndef TICTACTOE_BASIC_IO_HPP
#define TICTACTOE_BASIC_IO_HPP

#include <iostream>
#include <string>

namespace tictactoe
{
    bool is_int(std::string& str);

    bool next_int(std::istream& input_stream, int& arg);
}

#endif //TICTACTOE_BASIC_IO_HPP
