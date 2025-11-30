#include "core/entities/Parser.hpp"

int main() {
    setlocale(LC_ALL, "Russian");

    const Parser_n::ini_parser parser("test.ini"); //Write down your path!!
    const auto value1 = parser.get_value<int>("Section1.var1");
    const auto value2 = parser.get_value<std::string>("Section1.var2");
    const auto value3 = parser.get_value<std::string>("Section4.Mode");

    //View random values from ini file
    libio::output::print<std::string>("value #1 - ");
    libio::output::println(value1);

    libio::output::print<std::string>("value #2 - ");
    libio::output::println(value2);

    libio::output::print<std::string>("value #3 - ");
    libio::output::println(value3);

//#define WRONG_EXAMPLE

#ifdef WRONG_EXAMPLE
    const auto value4 = parser.get_value<std::string>("Section4.Mod");
#endif
}
