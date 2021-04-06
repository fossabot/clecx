#include "utils.hpp"
#include <vector>
#include "iostream"

namespace fs = std::filesystem;


std::string get_file_contents(std::filesystem::path path)
{
    return "int main() { print('Hello, World'); } ";
}