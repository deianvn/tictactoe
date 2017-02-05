#ifndef TICTACTOE_STRING_UTILS_HPP
#define TICTACTOE_STRING_UTILS_HPP

#include <string>
#include <algorithm>

namespace tictactoe
{
    bool ends_with(const std::string& haystack, const std::string& needle)
    {
        if (needle.size() > haystack.size()) return false;
        return std::equal(std::crbegin(needle), std::crend(needle), std::crbegin(haystack));
    }

    bool starts_with(const std::string& haystack, const std::string& needle)
    {
        if (needle.size() > haystack.size()) return false;
        return std::equal(std::cbegin(needle), std::cend(needle), std::cbegin(haystack));
    }
}

#endif //TICTACTOE_STRING_UTILS_HPP
