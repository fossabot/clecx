use std::fmt;
#[path="utils.rs"]
mod utils;

use colored::*;


#[derive(Debug)]
pub enum Severity {
    ERROR,
    INFO,
    WARN,
    SUCCESS,
}
// Doesnt look good
// impl fmt::Display for Severity {
//     fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
//         write!(f, "{:?}", self)
//     }
// }

impl Severity {
    pub fn to_beautiful_string(&self) -> ColoredString {
        let result = match self {
            Self::ERROR => "error".red().bold(),
            Self::WARN => "warning".yellow().bold(),
            Self::INFO => "info".white().bold(),
            Self::SUCCESS => "success".green().bold(),
        };
        result
    } 
}


static mut ERROR_NUM: i32 = 0;
static mut WARN_NUM: i32 = 0;

pub fn err_warn_summary() -> bool {
    unsafe {
        if ERROR_NUM >= 1 {
            println!("{}{}{}{}{}{}", 
            "error".red().bold(),
            ": aborting due to ".white().bold(), 
            ERROR_NUM.to_string().white().bold(), 
            " error(s); ".white().bold().white().bold(), 
            WARN_NUM.to_string().white().bold(), 
            " warnings emitted".white().bold());
            return true;
        } else if WARN_NUM >= 1 {
            println!("{}{}{}{}", 
            "warning".yellow().bold(),
            ": ".white().bold(), 
            WARN_NUM.to_string().white().bold(), 
            " warning(s) emitted; ".white().bold().white().bold());
            return false;
        }
    }
    return false;
}

/// # Raise
/// ## Information
/// Raises an information message:
/// ## Parameters
/// - file: The filename | Any string
/// - line: The line on which it happened | Any Number
/// - charst: CharStart. The character at which the error starts | Any number
/// - charen - CharEnd. The character at which the error ends | Any number
/// - sev: The Severity | ERROR, WARN, INFO, SUCCESS
/// - problem: The problem that occurred | Any string
/// - fix: The fix to the problem | Any string
/// ## Example
/// This code
/// ```
/// error::raise("tests/lextest.clx", 23, 8, error::Severity::ERROR, "Something bad went wrong!", "Fix it by using this!");
/// ```
/// Produces this output: (Colors are wrong)
/// ``` 
/// error: Something bad went wrong!
///   --> hello.cpp:23:8
///    |
/// 23 | fn todo() { println!('Get line Content!'); }
///    | ^^^^^^^^^^^^
///    |
///   =  fix: Fix it by using this!
/// ```
pub fn raise(file: &str, line: i32, charst: i32, charen: i32, sev: Severity, problem: &str, fix: &str) {
    println!("{}{}{}", sev.to_beautiful_string(), ": ".white().bold(), problem.white().bold());

    let mut howmuch = charen - charst + 1;
    if howmuch <= 0 { howmuch = 1; }
    // Adjusting spaces
    let (spaces, arrow_spaces) =  if line < 10 {
        ("  ", " ")
    } else if line < 100 {
        ("   ", "  ")
    } else if line < 1000 {
        ("    ", "   ")
    } else if line < 10000 {
        ("     ", "     ")
    } else if line < 100000 {
        ("     ", "    ")
    } else if line < 1000000 {
        ("       ", "      ")
    } else {
        ("        ", "       ")
    };
    let mut uptick_spaces = String::from(" ");

    for i in 1..charst {
        uptick_spaces.push(' ');
    }

    let mut upticks: String =  String::from("^");
    for i in 1..howmuch {
        upticks.push('^');
    }
    let upticks_col = match sev {
        Severity::ERROR => upticks.red().bold(),
        Severity::INFO => upticks.white().bold(),
        Severity::SUCCESS => upticks.green().bold(),
        Severity::WARN => upticks.yellow().bold(),
    };

    let mut _useless = 1;
    unsafe {
        match sev {
            Severity::ERROR => ERROR_NUM += 1,
            Severity::WARN => WARN_NUM += 1,
            _ => _useless += 1,
        }
    }

    let file_contents = utils::get_file_contents(file);
    let split = file_contents.lines();
    let vec = split.collect::<Vec<&str>>();


    println!("{}{}{}{}{}{}{}", arrow_spaces, "--> ".cyan().bold(), file, ":",line, ":", charst);
    println!("{}{}", spaces, "|".cyan().bold());
    println!("{} {}{}", line.to_string().cyan().bold(), "| ".cyan().bold(), vec[(line - 1) as usize]);
    println!("{}{}{}{}", spaces, "|".cyan().bold(), uptick_spaces, upticks_col);
    println!("{}{}", spaces, "|".cyan().bold());
    println!("{}{}{}{}", spaces, "= ".cyan().bold(), "fix: ".white().bold(), fix);
    println!("");


}