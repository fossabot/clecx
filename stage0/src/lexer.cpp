#include "lexer.hpp";


Lexer::Lexer() {
    // Pushing back tokens
    reserved_kw.push_back("let");
    reserved_kw.push_back("if");
    reserved_kw.push_back("else");
    reserved_kw.push_back("switch");
    reserved_kw.push_back("res_print_DO_NOT_USE()");
    reserved_kw.push_back("import");
    reserved_kw.push_back("include");
    reserved_kw.push_back("define");
}


std::vector<Token> Lexer::scan(std::string contents)
{  
    this->src = contents;
    int x = 0;
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
                if (peek() == '*')
                {
                    // Block Comments
                    advance();
                    advance();
                    while (peek() != '/' && get_curr() != '*')
                    {
                        advance();
                    }
                    advance();
                    advance();
                    break;
                }
                else if (peek() == '/')
                {
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
                break;
            case '*':
                push_token(Token(TokenKind::MUL, ""));
                break;
            case '(':
                push_token(Token(TokenKind::LPAREN, ""));
                break;
            case ')':
                push_token(Token(TokenKind::RPAREN, ""));
                break;
            case '=':
                push_token(Token(TokenKind::EQUAL, ""));
                break;
            case ';':
                push_token(Token(TokenKind::SEMI, ""));
                break;
            case ':':
                if(peek() == ':') {
                    push_token(Token(TokenKind::DOUBLECOLON, ""));
                    advance();
                } else {
                    push_token(Token(TokenKind::COLON, ""));
                }
                break;
            case ',':
                push_token(Token(TokenKind::COMMA, ""));
                break;
            case '#':
                push_token(Token(TokenKind::SHARP, ""));
                break;
            // Implement Pointers TODO
            case '.': 
                push_token(Token(TokenKind::DOT, ""));
                break;
            case '!':
                push_token(Token(TokenKind::EXCLAMATION, ""));
                break;
            case '"':
                register_string('"');
                break;
            case '`':
                register_string('`');
                break;
            //case '"':
            //    push_token(Token(TokenKind::QUOTE, ""));
            case '{':
                push_token(Token(TokenKind::LBRACE, ""));
                break;
            case '}':
                push_token(Token(TokenKind::RBRACE, ""));
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
                else {
                    push_token(Token(TokenKind::UNEXPECTED_TOK, std::string(1, get_curr())));
                }
                break;
                
        }
        x++;
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

void Lexer::register_string(char start)
{
    // Lexed content
    std::string lexcon;
    advance();
    while (get_curr() != start) {
        lexcon += get_curr();
        advance();
    }

    advance();
    push_token(Token(TokenKind::ATOM_STRING, lexcon));
}