#include "lexer.hpp";


Lexer::Lexer() {
    // Pushing back tokens
    reserved_kw.push_back("let");
    reserved_kw.push_back("if");
    reserved_kw.push_back("else");
    reserved_kw.push_back("switch");
    reserved_kw.push_back("res_print_DO_NOT_USE()");
    reserved_kw.push_back("#import");
    reserved_kw.push_back("#include");
    reserved_kw.push_back("#define");
}

std::vector<Token> Lexer::scan(std::string contents)
{  
    this->src = contents;

    while (!is_eof())
    {
        switch (get_curr()) {
            case '-': // Needs to be first, because two characters
                if (peek() == '>')
                {
                    push_token(Token(TokenKind::PTR_ARROW, ""));
                    advance(); // It is two chars long, so we have to advance
                } else {
                    push_token(Token(TokenKind::SUB, ""));
                }
                break;
            case ' ': // Whitespace
                advance();
                break;
            case '\n':
                advance();
                break;
            case '/':
                if (peek() == '/')
                {
                    push_token(Token(TokenKind::COMMENT_START, ""));
                    while (get_curr() != '\n') // GOTO: End of line
                    {
                        advance();
                    }
                    break;
                } else {
                    push_token(Token(TokenKind::DIV, ""));
                    break;
                }
                break;
            case '+':
                push_token(Token(TokenKind::ADD, ""));
                break;
            case '*':
                push_token(Token(TokenKind::MUL, ""));
                break;
            case '(':
                LOG("L");
                push_token(Token(TokenKind::LPAREN, ""));
                break;
            case ')':
                LOG("R");
                push_token(Token(TokenKind::RPAREN, ""));
                break;
            case '=':
                push_token(Token(TokenKind::EQUAL, ""));
                break;
            case ';':
                push_token(Token(TokenKind::SEMI, ""));
                break;
            case ':':
                push_token(Token(TokenKind::COLON, ""));
                break;
            case '#':
                push_token(Token(TokenKind::SHARP, ""));
                break;
            // Implement Pointers TODO
            case '.': 
                push_token(Token(TokenKind::DOT, ""));
                break;
            default:
                if (isdigit(get_curr()))
                {
                    register_number();                    
                }

                else if (isalpha(get_curr()))
                {
                    register_ident();                    
                }
                else
                    SYNTERR(10, 20, "hello.cpp", "Syntax error!");
                break;
                
        }
    }

    return tokens;
}


void Lexer::register_ident() {
    // Lexed content
    std::string lexcon;
    while (isalpha(get_curr())) {
        lexcon += get_curr();
        advance();
    }
    // Is it a reserved keyword?
    if (std::find(reserved_kw.begin(), reserved_kw.end(), lexcon) != reserved_kw.end()) {
        push_token(Token(TokenKind::KEYWORD, lexcon));
    } else {
        push_token_no_advance(Token(TokenKind::ATOM_IDENT, lexcon));
    }
}

void Lexer::register_number() {
    // Lexed content
    std::string lexcon;
    while (isdigit(get_curr())) {
        lexcon += get_curr();
        advance();
    }

    push_token_no_advance(Token(TokenKind::ATOM_NUM, lexcon));
}