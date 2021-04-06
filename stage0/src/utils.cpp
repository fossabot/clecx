#include "utils.hpp"
#include <vector>

namespace fs = std::filesystem;


std::string get_file_contents(std::filesystem::path path)
{
    std::ifstream f(path);
    const auto size = fs::file_size(path);
    std::string result(size, '\0');
    f.read(result.data(), size);
    return result;
}