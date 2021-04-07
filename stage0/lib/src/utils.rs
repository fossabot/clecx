use std::{fs, path::Path};

pub fn get_file_contents(path: &str) -> String {
    let contents = fs::read_to_string(path)
        .expect("Could not find file!");
    // TODO: Add better error handling (!)
    return contents;
}

pub fn does_file_exist(path: &str) -> bool {
    return Path::new(path).exists();
}