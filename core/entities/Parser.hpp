#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>

#include "Section.hpp"

import Libio;

namespace Parser_n {
    /**
     * Main class of the app.
     * Parse ini file.
     */
    class Parser {
        std::string filename;
        std::vector<Section> *sections;

        void parse_lines() const;

    public:
        explicit Parser(const std::string &);

        Parser() = delete;

        ~Parser() = default;

        Parser(const Parser &) = delete;

        template<typename T>
            requires std::is_integral_v<T> || libio::type_constrains::is_string<T>
        T get_value(const std::string &) const;
    };
}

#endif
