use std::vec::Vec;
#[path="token.rs"]
mod token;
#[path="error.rs"]
mod error;

type tok = token::Token;

pub struct Lexer {
    pos: usize,
    src: String,
    pub tokens: Vec<token::Token>,
    reserved: Vec<String>, // Maybe hashmap?
}

impl Lexer {
    pub fn new(_src: String) -> Lexer {
        
        Lexer { 
            pos: 0,
            src: _src,
            tokens: vec![],
            reserved: vec!["fn".to_string(), "if".to_string(), "elif".to_string(),
                            "else".to_string(), "switch".to_string(), "case".to_string(),
                            "while".to_string(),
                            "for".to_string(), "true".to_string(), "false".to_string(),
                            "int".to_string(), "char".to_string(), "str".to_string()],
        }
    }

    pub fn scan(&mut self) {
        while !self.is_eof()
        {
            // Skip Whitespaces
            self.skip_whitespace();
            match self.curr() {
                // Comments
                '/' => {
                    if self.spy() == '/' {
                        while self.curr() != '\n' { self.advance(); }
                    } else {
                        // Divisor
                        self.append(tok::DIV);
                    }
                },
                '+' =>  self.append(tok::ADD),
                '-' =>  self.append(tok::SUB),
                '*' =>  self.append(tok::MUL),
                '(' =>  self.append(tok::LPAREN),
                ')' =>  self.append(tok::RPAREN),
                '{' =>  self.append(tok::LBRACE),
                '}' =>  self.append(tok::RBRACE),
                ',' =>  self.append(tok::COMMA),
                '=' =>  self.append(tok::EQUAL),
                ';' =>  self.append(tok::SEMI),
                ':' => {
                    if self.spy() == ':' {
                        self.append(tok::DOUBLECOLON)
                    } else {
                        self.append(tok::COLON)
                    }
                },
                // ''' => { self.scan_char(); break; }
                '"' => { self.scan_str('"'); }
                '`' => { self.scan_str('`'); }
                _ => {
                    if char::is_numeric(self.curr()) {
                        self.scan_number();
                    } else if char::is_alphabetic(self.curr()) {
                        self.scan_ident();
                    } else {
                        error::raise("tests/lextest.clx",5, 8, 15, error::Severity::ERROR, "Unexpected Token: This token is unknown to the lexer.", "This might be a bug, but it might be a simple mistake too. Delete the character.");
                        self.advance();
                    }
                }
                
            }
        }
    }

    // Is EndOfFile
    fn is_eof(&mut self) -> bool {
        self.pos >= self.src.chars().count()
    }

    // Is EndOfFIle in specific positive steps
    fn is_eof_plus(&mut self, plus: usize) -> bool {
        self.pos + plus >= self.src.chars().count()
    }

    // Is EOF backwards
    fn is_eof_minus(&mut self, minus: usize) -> bool {
        self.pos - minus >= self.src.chars().count()
    }

    // Advances
    fn advance(&mut self) { self.pos += 1; }
    
    // Gets the current character by Position
    fn curr(&mut self) -> char {
        if self.is_eof() 
        {
            return '\0' // EOF
        }
        self.src.chars().nth(self.pos).unwrap()
    }

    // Gets the next character
    fn spy(&mut self) -> char {
        if self.is_eof_plus(1) {
            return '\0'
        }
        self.src.chars().nth(self.pos + 1).unwrap()
    }
    
    // Gets the character that is a specific number of steps ahead
    fn spy_ahead(&mut self, plus: usize) -> char {
        if self.is_eof_plus(plus) {
            return '\0'
        }
        self.src.chars().nth(self.pos + plus).unwrap()
    }

    // Spy if something is behind you
    fn spy_back(&mut self, minus: usize) -> char {
        if self.is_eof_minus(minus) || self.pos - minus <= 0 {
            return '\0'
        }
        self.src.chars().nth(self.pos - minus).unwrap()
    }

    // Appends a token to the list
    fn append(&mut self, tok: token::Token) {
        self.append_no_adv(tok);
        self.advance();
    }

    fn append_no_adv(&mut self, tok: token::Token) {
        self.tokens.push(tok);
    }

    fn skip_whitespace(&mut self) {
        while char::is_whitespace(self.curr()) { self.advance() } 
    }

    fn scan_str(&mut self, lookout: char) {
        let mut content = String::from("");
        self.advance();
        while self.curr() != lookout
        {
            content.push(self.curr());
            self.advance();
        }
        self.advance();
        self.append(tok::STRING(content));
    }

    fn scan_number(&mut self) {
        let mut content = String::from("");
        while char::is_numeric(self.curr()) {
            content.push(self.curr());
            self.advance();
        }
        self.append_no_adv(tok::NUMBER(content));
    }

    fn scan_ident(&mut self) {
        let mut content = String::from("");
        while char::is_alphanumeric(self.curr()) || self.curr() == '_'  {
            content.push(self.curr());
            self.advance();
        }
        // TODO: Very unclean way, please fix!
        if self.reserved.contains(&content) {
             match content.as_str() {
                 "fn" => { self.append_no_adv(tok::FN); }
                 "if" => { self.append_no_adv(tok::IF); },
                 "elif" => { self.append_no_adv(tok::ELIF); },
                 "else" => { self.append_no_adv(tok::ELSE); },
                 "switch" => { self.append_no_adv(tok::SWITCH); },
                 "case" => { self.append_no_adv(tok::CASE); },
                 "while" => { self.append_no_adv(tok::WHILE); },
                 "for" => { self.append_no_adv(tok::FOR);  },
                 // Type(s)
                 "true" => { self.append_no_adv(tok::TRUE); },
                 "false" => { self.append_no_adv(tok::FALSE); },
                 "int" => { self.append_no_adv(tok::INT); },
                 "char" => { self.append_no_adv(tok::CHAR);  },
                 "bool" => { self.append_no_adv(tok::BOOL); },
                 _ => error::raise("tests/lextest.clx",5, 8, 15, error::Severity::WARN, "The requested token has not been implemented yet!", "Message me on GitHub / Discord!")

             }
        } else {
            self.append_no_adv(tok::IDENT(content));
        }
    }

    fn scan_char(self) {

    }

}