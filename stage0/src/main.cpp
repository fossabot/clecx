#include "core.hpp"
#include "utils.hpp"
#include "lexer.hpp"
#include <string>
#include <fstream>
#include <streambuf>

int main(int argc, char** argv)
{
    std::ifstream t("file.txt");
    std::string contents((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());
    LOG(contents);
    Lexer* lexer = new Lexer();
    std::vector<Token> tokens = lexer->scan(contents);

    for (auto token : tokens) {
        // Print it!
        print_token(token);
    }

    return 0;

}
