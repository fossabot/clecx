use lib::lexer;
use lib::token;
use lib::error;

fn main() {
    let mut lexer = lexer::Lexer::new("+".to_string());
    lexer.scan();
    
    error::raise("tests/lextest.clx",5, 8, 15, error::Severity::ERROR, "This type does not exist", "Create the struct, enum or typedef or look at the type again and see if you mistyped something.");
    for i in lexer.tokens.iter() {
        println!("{}", i);
    }

}