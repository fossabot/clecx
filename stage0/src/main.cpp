#include "core.hpp"
#include "utils.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        // No file provided
        ERR("You need to provide a filename in order to use this command. Usage: `bclecx <filename>`");
        return 1;
    }
    if (!file_exists(argv[1]))
    {
        // ERR("File does not exist!");
    }

    std::string contents = get_file_contents(argv[1]);
    LOG(contents);

    return 0;

}
