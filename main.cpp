#include "core/entities/Parser.hpp"

import Libio;

int main() {
    const Parser_n::Parser parser(R"(C:\Users\user\Downloads\NetoINI\test.ini)");

    const auto value = parser.get_value<int>("Section2.var2");
    libio::output::println(value);
}
