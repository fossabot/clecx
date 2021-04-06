#include "core.hpp"
#include "utils.hpp"
#include "lexer.hpp"
#include <string>
#include <fstream>
#include <streambuf>
#include "error.hpp"

int main(int argc, char** argv)
{
    std::ifstream t(argv[1]);
    std::string contents((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());
    Lexer* lexer = new Lexer();
    std::vector<Token> tokens = lexer->scan(contents);

    
    // for (auto& token : tokens) {
    //     // Print it!
    //     print_token(token);
    // }

    return 0;

}