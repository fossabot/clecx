#pragma once

#include <ctype.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "token.hpp"
#include "core.hpp"

class Lexer
{
public:
    Lexer();

    inline bool is_eof() { return pos >= src.length(); }
    inline void advance() {  pos++; }
    inline void push_token(Token tok) {
        tokens.push_back(tok);
        advance();
    }

    inline void push_token_no_advance(Token tok) {
        tokens.push_back(tok);
    }

    inline char get_curr() {
        if (is_eof()) return '\0';
        return src[pos];
    }
    inline char peek() {
        if (pos + 1 >= src.length()) return '\0';
        return src[pos + 1];
    }

    std::vector<Token> scan(std::string contents);
    
    inline bool expect_next(int index, TokenKind kind) {
        if (tokens[index + 1].kind == kind) { return true; }
        return false;
    }

    inline bool expect_last(int index, TokenKind kind) {
        if (tokens[index - 1].kind == kind) { return true; }
        return false;
    }

    void register_number();
    void register_ident();
    bool has_errors;
private:
    size_t pos = 0;
    std::string src;
    std::vector<std::string> reserved_kw; // Reserved Keywords
    std::vector<Token> tokens;
};