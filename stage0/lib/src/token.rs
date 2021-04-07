use std::fmt::{self, Debug, Display};
#[derive(Debug)]
pub enum Token {
    // Operators ---
    ADD,
    SUB,
    MUL,
    DIV,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    COMMA,
    EQUAL,
    SEMI,
    COLON,
    DOUBLECOLON,

    // Other ---
    IDENT(String),


    // Types ---
    NUMBER(String),
    STRING(String),
    CHARLIT(String),
    Bool,

    // Keywords ---

    // General
    FN,

    // Condition Checking
    IF,
    ELIF,
    ELSE,
    SWITCH,
    CASE,
    WHILE,
    FOR,

    // Type-keywords
    TRUE,
    FALSE,

    // Types ---
    INT,
    CHAR,
    BOOL,
    STR
}

// So that we can print it
impl fmt::Display for Token {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{:?}", self)
    }
}
