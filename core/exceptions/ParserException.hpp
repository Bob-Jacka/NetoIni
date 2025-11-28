#ifndef BASE_EXCEPTION_HPP
#define BASE_EXCEPTION_HPP

#include <source_location>
#include <string>

/**
 * Namespace for exceptions in Parser
 */
namespace Parser_n {
    class ParserException final : public std::exception {
    public:
        explicit ParserException(const std::string &, std::source_location = std::source_location::current());

        ~ParserException() override = default;
    };
}

#endif
