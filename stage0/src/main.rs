use std::process::exit;

use lib::lexer;
use lib::token;
use lib::error;

fn main() {
    let mut lexer = lexer::Lexer::new("fn HelloWorld()".to_string());
    lexer.scan();
    
    for i in lexer.tokens.iter() {
        println!("{}", i);
    }

    if error::err_warn_summary() {
        exit(1);
    } else {
        exit(0);
    }
}