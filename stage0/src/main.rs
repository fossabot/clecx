use lib::lexer;
use lib::token;

fn main() {
    let mut lexer = lexer::Lexer::new("// Hello World!".to_string());
    lexer.scan();
    
    for i in lexer.tokens.iter() {
        println!("{}", i);
    }

}