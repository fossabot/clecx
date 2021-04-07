use crate::token;
use crate::ast;
struct Parser {
    pub tokens: Vec<token::Token>,
    pos: usize,
}

type tok = token::Token;

impl Parser {
    pub fn new(toks: Vec<token::Token>) {
        
    }
    fn advance(&mut self) { 
        self.pos += 1;
    }

    // Is EOT?
    fn eot(&mut self) -> bool {
        return self.pos >= self.tokens.len();
    }

    fn curr(&mut self) -> token::Token {
        if self.eot() { println!("Bad EOT!"); }
        return self.tokens[self.pos];
    }


    // Is EndOfFIle in specific positive steps
    fn is_eot_plus(&mut self, plus: usize) -> bool {
        self.pos + plus >= self.tokens.len()
    }

    // Is EOF backwards
    fn is_eot_minus(&mut self, minus: usize) -> bool {
        self.pos - minus >= self.tokens.len()
    }
    
    // Gets the next character
    fn spy(&mut self) -> tok {
        if self.is_eot_plus(1) {
            // Some Error TODO
        }
        self.tokens[self.pos + 1]
    }
    
    // Gets the character that is a specific number of steps ahead
    fn spy_ahead(&mut self, plus: usize) -> tok {
        if self.is_eot_plus(plus) {
        }
        self.tokens[self.pos + plus]
    }

    // Spy if something is behind you
    fn spy_back(&mut self, minus: usize) -> tok {
        if self.is_eot_minus(minus) || self.pos - minus <= 0 {
        }
        self.tokens[self.pos - minus]
    }

    fn parse_ident(&mut self) {
        let value = self.curr();
        let node = ast::IdentNode::new(value);
        self.advance();
        return node;
    } 
}