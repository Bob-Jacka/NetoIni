#include "ParserException.hpp"

#include <iostream>

Parser_n::ParserException::ParserException(const std::string &msg, const std::source_location location) {
    std::cout << location.file_name() << ":" << location.line() << ":" << location.column() << " (" << location.function_name() << "): " <<
            msg << "." << "\n";
}