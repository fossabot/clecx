#include "error.hpp"

static const std::string domain_names[] {
    "Lexical", "Parser", "Analyzer"
};

static const std::string severity_names[] {
    "info", "warning", "error"
}; 

//static std::vector<Error>& errors;

// With fix
void raise(ErrorDomain domain, ErrorSeverity severity, std::string file, size_t start_line, size_t end_line, size_t error_col, std::string problem, std::string fix)
{
    Error err;
    err.domain = domain;
    err.severity = severity;

    ErrorLocation loc;
    loc.file = file;
    loc.start_line = start_line;
    loc.end_line = end_line;
    loc.error_col = error_col;

    err.location = loc;
    err.problem = problem;
    err.fix = fix;

    err.print();

    // errors.push_back(err);

    return;
}

void raise(ErrorDomain domain, ErrorSeverity severity, std::string file, size_t line, size_t error_col, std::string problem, std::string fix)
{
    raise(domain, severity, file, line, line, error_col, problem, fix);
}

void raise(ErrorDomain domain, ErrorSeverity severity, std::string file, size_t line, std::string problem, std::string fix)
{
    raise(domain, severity, file, line, line, 1, problem, fix);
}

void raise(ErrorDomain domain, ErrorSeverity severity, std::string problem, std::string fix)
{
    raise(domain, severity, "", 0, 0, 1, problem, fix);
}

void raise(ErrorSeverity severity, std::string problem, std::string fix)
{
    raise(ErrorDomain::General, severity, "", 0, 0,  1, problem, fix);
}

// Without fix

void raise(ErrorDomain domain, ErrorSeverity severity, std::string file, size_t start_line, size_t end_line, size_t error_col, std::string problem)
{
    raise(domain, severity, file, start_line, end_line, error_col, problem, "");
}

void raise(ErrorDomain domain, ErrorSeverity severity, std::string file, size_t line, size_t error_col, std::string problem)
{
    raise(domain, severity, file, line, line, error_col, problem, "");
}

void raise(ErrorDomain domain, ErrorSeverity severity, std::string file, size_t line, std::string problem)
{
    raise(domain, severity, file, line, line, 1, problem, "");
}

void raise(ErrorDomain domain, ErrorSeverity severity, std::string problem)
{
    raise(domain, severity, "", 0, 0, 1, problem, "");
}

void raise(ErrorSeverity severity, std::string problem)
{
    raise(ErrorDomain::General, severity, "", 0, 0,  1, problem, "");
}


void Error::print()
{
    std::cerr << domain_names[static_cast<int>(this->domain)];
    std::cerr << ' ';
    std::cerr << severity_names[static_cast<int>(this->severity)] << "[E001]: " << this->problem << std::endl;
    std::cerr << "    --> " << this->location.file << ":" << this->location.start_line << ":" << this->location.error_col << std::endl;
    std::cerr << "     |" << std::endl;
    std::cerr << "  " << this->location.start_line << " |" << "     " << "TODO: Get file contents" << std::endl;
    std::cerr << "     |" << std::endl;
    std::cerr << "     |" << std::endl;
    if (this->fix != "")
    {
        std::cerr << "     | " << this->fix << std::endl;
    } else {
        std::cerr << "     |" << std::endl;
    }
    std::cerr << "" << std::endl;


}