#ifndef A84AF205_296D_4407_906E_62BF6CEEEF99
#define A84AF205_296D_4407_906E_62BF6CEEEF99

#include <vector>
#include <iostream>
#include <string>
#include <optional>
#include <functional>


enum class ErrorDomain
{
    Lexer,
    Parser,
    Analyzer,
    General
};

enum class ErrorSeverity
{
    Info,
    Warning,
    Error
};
struct ErrorLocation
{
    std::string file;
    size_t start_line;
    size_t end_line;
    size_t error_col;
};

// Code by @*nullptr#2122 on Discord
struct Error
{
    ErrorDomain domain;
    ErrorSeverity severity;
    std::string problem;
    std::string fix;
    ErrorLocation location;

    void print();
};


// With fix
void raise(ErrorDomain domain, ErrorSeverity severity, std::string file, size_t start_line, size_t end_line, size_t error_col, std::string problem, std::string fix);
void raise(ErrorDomain domain, ErrorSeverity severity, std::string file, size_t line, size_t error_col, std::string problem, std::string fix);
void raise(ErrorDomain domain, ErrorSeverity severity, std::string file, size_t line, std::string problem, std::string fix);
void raise(ErrorDomain domain, ErrorSeverity severity, std::string problem, std::string fix);
void raise(ErrorSeverity severity, std::string problem, std::string fix);

// Without fix

void raise(ErrorDomain domain, ErrorSeverity severity, std::string file, size_t start_line, size_t end_line, size_t error_col, std::string problem);
void raise(ErrorDomain domain, ErrorSeverity severity, std::string file, size_t line, size_t error_col, std::string problem);
void raise(ErrorDomain domain, ErrorSeverity severity, std::string file, size_t line, std::string problem);
void raise(ErrorDomain domain, ErrorSeverity severity, std::string problem);
void raise(ErrorSeverity severity, std::string problem);


#endif /* A84AF205_296D_4407_906E_62BF6CEEEF99 */
