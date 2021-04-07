use std::process::exit;

use lib::lexer;
use lib::token;
use lib::error;

fn main() {
    let mut lexer = lexer::Lexer::new("$".to_string());
    lexer.scan();
    
    error::raise("tests/lextest.clx",5, 8, 15, error::Severity::ERROR, "This type does not exist", "Create the struct, enum or typedef or look at the type again and see if you mistyped something.");
    error::raise("tests/lextest.clx",5, 8, 15, error::Severity::WARN, "This might fail, due to an error", "I just want to showcase warnings, this isn't an actual warn.");
    error::raise("tests/lextest.clx",5, 8, 15, error::Severity::INFO, "I am an information", "A simple information");
    error::raise("tests/lextest.clx",5, 8, 15, error::Severity::SUCCESS, "Hello, I am a success", "Do not fix me");

    for i in lexer.tokens.iter() {
        println!("{}", i);
    }

    if error::err_warn_summary() {
        exit(1);
    } else {
        exit(0);
    }
}