#include "basic_io.hpp"

bool is_int(std::string& str)
{
    auto it = std::begin(str);
    auto end = std::end(str);
    
    while (it != end)
    {
        if (!std::isdigit(*it++)) return false;
    }
    
    return true;
}

bool next_int(std::istream& input_stream, int& arg)
{
    std::string line;
    std::getline(input_stream, line);
    
    if (is_int(line))
    {
        arg = std::stoi(line);
        return true;
    }
    
    return false;
}
