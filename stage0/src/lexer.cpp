#include "lexer.hpp"
#include "error.hpp"

Lexer::Lexer() {
    // Pushing back tokens
    keywords.insert({"fn", TokenKind::FN});
    keywords.insert({"if", TokenKind::IF});
    keywords.insert({"elseif", TokenKind::ELSE_IF});
    keywords.insert({"else", TokenKind::ELSE});
    keywords.insert({"for", TokenKind::FOR});
    keywords.insert({"while", TokenKind::WHILE});
    keywords.insert({"loop", TokenKind::LOOP});
    keywords.insert({"true", TokenKind::TRUE});
    keywords.insert({"false", TokenKind::FALSE});

    keywords.insert({"int", TokenKind::TYPE_INT});
    keywords.insert({"char", TokenKind::TYPE_CHAR});
    keywords.insert({"bool", TokenKind::TYPE_BOOL});
    keywords.insert({"str", TokenKind::TYPE_STR});

    
}


std::vector<Token> Lexer::scan(const std::string& contents)
{  
    this->src = contents;
    int x = 0;
    while (!is_eof())
    {
        switch (get_curr()) {
            case '-': // Needs to be first, because two characters
                if (peek() == '>')
                {
                    push_token(Token(TokenKind::PTR_ARROW));
                    advance(); // It is two chars long, so we have to advance
                } else {
                    push_token(Token(TokenKind::SUB));
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
                push_token(Token(TokenKind::MUL));
                break;
            case '(':
                push_token(Token(TokenKind::LPAREN));
                break;
            case ')':
                push_token(Token(TokenKind::RPAREN));
                break;
            case '=':
                push_token(Token(TokenKind::EQUAL));
                break;
            case ';':
                push_token(Token(TokenKind::SEMI));
                break;
            case '\'':
                char_lit();
                break;
            case ':':
                if(peek() == ':') {
                    push_token(Token(TokenKind::DOUBLECOLON));
                    advance();
                } else {
                    push_token(Token(TokenKind::COLON));
                }
                break;
            case ',':
                push_token(Token(TokenKind::COMMA));
                break;
            case '#':
                push_token(Token(TokenKind::SHARP));
                break;
            // Implement Pointers TODO
            case '.': 
                push_token(Token(TokenKind::DOT));
                break;
            case '!':
                push_token(Token(TokenKind::EXCLAMATION));
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
                push_token(Token(TokenKind::LBRACE));
                break;
            case '}':
                push_token(Token(TokenKind::RBRACE));
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
                    raise(ErrorDomain::Lexer, ErrorSeverity::Error, "TODO.clx", 0, 0, pos, "Invalid character %s", "Correct the bad character");
                    advance();
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
    while (isalnum(get_curr()) || get_curr() == '_') {
        lexcon += get_curr();
        advance();
    }

    // Is it a reserved keyword?
    if (keywords.count(lexcon) == 1) {
        auto iter = keywords.find(lexcon);
        TokenKind kind = iter->second;
        push_token(Token(kind));
    } else {
        push_token_no_advance(Token(TokenKind::IDENT, lexcon));
    }
}


void Lexer::register_number() {
    // Lexed content
    std::string lexcon;
    while (isdigit(get_curr())) {
        lexcon += get_curr();
        advance();
    }

    push_token_no_advance(Token(TokenKind::NUMBER, lexcon));
}

void Lexer::char_lit()  {
    std::string lexcon;


    advance();
    while (get_curr() != '\'') {
        if (get_curr() == '\\') {
            advance();
            switch (get_curr()) {
                case 'n':
						lexcon += '\n';
						break;
					case 'b':
						lexcon += '\b';
						break;
					case 't':
						lexcon += '\t';
						break;
					default:
						lexcon += peek();
						break;
            }
        } else {
            lexcon += get_curr();
        }
        advance();
    }
    advance();
    if (lexcon.length() > 1) {
        raise(ErrorDomain::Lexer, ErrorSeverity::Error, "TODO.clx", 10, 10, pos, "Unexpected string \"" + lexcon + "\" in character literal (n, t, etc are allowed!)");
    } else {
        push_token(Token(TokenKind::CHAR_LIT, lexcon));
    }
}

void Lexer::register_string(char start)
{
    // Lexed content
    std::string lexcon;
    advance();
    while (get_curr() != start) {
        // Is it an escape code?
        // TODO: What grammar does an escape code have?
        if (get_curr() == '\\') // Sadly, no character has just a '\'
        {
            advance(); // No slash
            switch (get_curr())
            {
                case 'n': lexcon += '\n'; break;
                case 'b': lexcon += '\b'; break;
                case 't': lexcon += '\t'; break;
                // Unknown escape code
                default:
                    lexcon += get_curr();
                    break;
            }
        } else {
                lexcon += get_curr();
        }
        advance();
    }

    advance();
    push_token(Token(TokenKind::STRING_LIT, lexcon));
}