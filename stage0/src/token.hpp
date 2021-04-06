#ifndef A5D1C17E_49FA_48ED_B356_D04C4CBF64E3
#define A5D1C17E_49FA_48ED_B356_D04C4CBF64E3

#include <iostream>
#include <string>
#include "core.hpp"


enum TokenKind
{
    // Operators
    ADD,
    SUB,
    DIV,
    MUL,
    RPAREN,
    LPAREN,
    EQUAL,
    SEMI,
    COLON,
    SHARP,
    DOT,
    PTR_ARROW, // ->
    EXCLAMATION,
    QUOTE,
    LBRACE,
    DOUBLECOLON,
    RBRACE,
    COMMA,

    // Other
    NUMBER,
    IDENT,
    STRING_LIT,
    CHAR_LIT,
    BOOL,


    // Keywords
    FN,
    IF,
    ELSE_IF,
    ELSE,
    FOR,
    WHILE,
    LOOP,
    TRUE,
    FALSE,

    // Types
    TYPE_INT,
    TYPE_CHAR,
    TYPE_BOOL,
    TYPE_STR,
};

struct Token
{
    Token(int _kind) : kind(_kind), data("") {}
    Token(int _kind, std::string content) : kind(_kind), data(content) {}
    int kind;
    std::string data;
};

inline void print_token(Token tok) {
    std::string kind;

    switch (tok.kind)
    {
        // Operators
        case TokenKind::ADD: kind = "ADD"; break;
        case TokenKind::SUB: kind = "SUB"; break;
        case TokenKind::DIV: kind = "DIV"; break;
        case TokenKind::MUL: kind = "MUL"; break;
        case TokenKind::RPAREN: kind = "RPAREN"; break;
        case TokenKind::LPAREN: kind = "LPAREN"; break;
        case TokenKind::EQUAL: kind = "EQUAL"; break;
        case TokenKind::SEMI: kind = "SEMI"; break;
        case TokenKind::COLON: kind = "COLON"; break;
        case TokenKind::SHARP: kind = "SHARP"; break;
        case TokenKind::DOT: kind = "DOT"; break;
        case TokenKind::PTR_ARROW: kind = "PTR_ARROW"; break;
        case TokenKind::EXCLAMATION: kind = "EXCLAMATION"; break;
        case TokenKind::QUOTE: kind = "QUOTE"; break;
        case TokenKind::LBRACE: kind = "LBRACE"; break;
        case TokenKind::RBRACE: kind = "RBRACE"; break;
        case TokenKind::DOUBLECOLON: kind = "DOUBLECOLON"; break;
        case TokenKind::COMMA: kind = "COMMA"; break;

        // Other
        case TokenKind::NUMBER: kind = "NUMBER"; break;
        case TokenKind::IDENT: kind = "IDENT"; break;
        case TokenKind::STRING_LIT: kind = "STRING_LIT"; break;
        case TokenKind::CHAR_LIT: kind = "CHAR_LIT"; break;
        case TokenKind::BOOL: kind = "BOOL"; break;

        // Keywords
        case TokenKind::FN: kind = "FN"; break;
        case TokenKind::IF: kind = "IF"; break;
        case TokenKind::ELSE_IF: kind = "ELSEIF"; break;
        case TokenKind::ELSE: kind = "ELSE"; break;
        case TokenKind::FOR: kind = "FOR"; break;
        case TokenKind::WHILE: kind = "WHILE"; break;
        case TokenKind::LOOP: kind = "LOOP"; break;
        case TokenKind::TRUE: kind = "TRUE"; break;
        case TokenKind::FALSE: kind = "FALSE"; break;

        // Types
        case TokenKind::TYPE_INT: kind = "INT"; break;
        case TokenKind::TYPE_CHAR: kind = "CHAR"; break;
        case TokenKind::TYPE_BOOL: kind = "BOOL"; break;
        case TokenKind::TYPE_STR: kind = "STRING"; break;
        
        default:
            kind = "UNKNOWN"; // Throw syntax error TODO
            break;
    }
    if (tok.data.length() > 0) { // no empty strings
        std::cout << kind << " (Data: " << tok.data << " )" << std::endl;
    } else {
        std::cout << kind << std::endl;
    }
}



#endif /* A5D1C17E_49FA_48ED_B356_D04C4CBF64E3 */
