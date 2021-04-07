use std::fs;

pub fn get_file_contents(path: &str) -> String {
    let contents = fs::read_to_string(path)
        .expect("Could not find file!");
    // TODO: Add better error handling (!)
    return contents;
}