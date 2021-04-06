#ifndef A5D1C17E_49FA_48ED_B356_D04C4CBF64E3
#define A5D1C17E_49FA_48ED_B356_D04C4CBF64E3

#include <iostream>
#include <string>
#include "core.hpp"


enum TokenKind
{
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
    POINTER,
    DOT,
    PTR_ARROW, // ->
    COMMENT_START,
    KEYWORD,
    TYPE,
    ATOM_IDENT,
    ATOM_NUM,
    ERROR,
    UNEXPECTED_TOK,
    EXCLAMATION,
    QUOTE,
    LBRACE,
    DOUBLECOLON,
    RBRACE,
    COMMA,
    ATOM_STRING,
    ATOM_BOOL,
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
        case TokenKind::POINTER: kind = "POINTER"; break;
        case TokenKind::KEYWORD: kind = "KEYWORD"; break;
        case TokenKind::DOT: kind = "DOT"; break;
        case TokenKind::PTR_ARROW: kind = "PTR_ARROW"; break;
        case TokenKind::COMMENT_START: kind = "COMMENT_START"; break;
        case TokenKind::ATOM_IDENT: kind = "IDENT"; break;
        case TokenKind::ATOM_NUM: kind = "NUM"; break;
        case TokenKind::ERROR: kind = "ERROR: "; break;
        case TokenKind::UNEXPECTED_TOK: kind = "ERROR: Unexpected Token"; break;
        case TokenKind::EXCLAMATION: kind = "EXCLAMATION"; break;
        case TokenKind::QUOTE: kind = "QUOTE"; break;
        case TokenKind::LBRACE: kind = "LBRACE"; break;
        case TokenKind::RBRACE: kind = "RBRACE"; break;
        case TokenKind::DOUBLECOLON: kind = "DOUBLECOLON"; break;
        case TokenKind::COMMA: kind = "COMMA"; break;
        case TokenKind::ATOM_STRING: kind = "STRING"; break;
        case TokenKind::ATOM_BOOL: kind = "BOOL"; break;
        case TokenKind::TYPE: kind = "TYPE"; break;
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
