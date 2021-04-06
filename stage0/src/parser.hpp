#ifndef B08BD91F_D23E_4710_8FC1_9E03153B5F10
#define B08BD91F_D23E_4710_8FC1_9E03153B5F10

#include <stdio.h>
#include <iostream>
#include <exception>
#include <algorithm>
#include <string>
#include <vector>
#include "token.hpp"

class Parser 
{
public:
    inline void advance() { pos++; }
    // Is end of tokens
    inline bool is_eot() { return pos >= tokens.size(); }

    inline Token get_curr() {
        if (is_eot()) throw std::runtime_error("Something went wrong. TODO: Implement something");
        return tokens[pos];
    }
    inline Token peek() {
        if (pos + 1 >= token.size()) throw std::runtime_error("Something went wrong. TODO: Implement something 2");
        return tokens[pos + 1];
    }

    inline Token consume() {
        // Peek, advance, consume
        auto next_token = get_curr();
        advance();

        return next_token;
    }

private:
    size_t pos = 0;
    std::vector<Token> tokens;
}

#endif /* B08BD91F_D23E_4710_8FC1_9E03153B5F10 */
