use std::process::exit;

use lib::lexer;
use lib::token;
use lib::error;
use std::env;
use lib::utils;
use colored::*;

fn main() {
    // Getting the Args
    if std::env::args().count() < 2 {
        println!("{}{}", "error".red().bold(), ": You need to provide a file. Usage: `clecxc <filename>".bold().white());
        exit(1);
    }

    let file = std::env::args().nth(1).unwrap();
    let content = utils::get_file_contents(file.as_str());

    if !utils::does_file_exist(file.as_str()) {
        println!("{}{}{}{}", "error".red().bold(), ": the provided file (".bold().white(), file.yellow().bold(), ") does not exist.".bold().white());   
        exit(1);
    }


    // Lexing
    let mut lexer = lexer::Lexer::new(content);
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