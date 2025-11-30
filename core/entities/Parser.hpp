#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>

#include <map>
#include <exception>
#include "../exceptions/ParserException.hpp"
#include "../data/Constants.hpp"

import Libio;

namespace Parser_n {
    /**
     * Main class of the app.
     * Parse ini file.
     */
    class ini_parser {

        using sections_type = std::map<std::string, std::map<std::string, std::string>>;

        sections_type sections;

        sections_type parse_ini_from_vector(const std::vector<std::string> &lines);

    public:
        explicit ini_parser(const std::string &);

        ini_parser() = delete;

        ~ini_parser() = default;

        ini_parser(const ini_parser &) = delete;

        template<typename T>
        requires std::is_integral_v<T> || libio::type_constrains::is_string<T>
        T get_value(const std::string &) const;
    };
}

/**
 * Get value from section object
 * @tparam T generic param
 * @param section_param string value
 * @return generic parameter value from section
 */
template<typename T>
requires std::is_integral_v<T> || libio::type_constrains::is_string<T>
T Parser_n::ini_parser::get_value(const std::string &section_param) const {
    if (section_param.contains(".")) {
        const auto split_line = libio::string::split(section_param,
                                                     '.'); //0 - name of the section and 1 - name of the value
        for (const auto &section: sections) { //key is section name, value is section
            if (split_line[0] == section.first) {
                try {
                    if (section.second.contains(split_line[1])) {
                        auto to_return = libio::string::convert_to_t<T>(section.second.at(split_line[1]));
                        return to_return;
                    }

                } catch (const std::exception &e) {
                    throw ParserException("Error retrieving value: " + std::string(e.what()));
                }
            }
        }
        for (const auto &kv: sections.at(split_line[0])) {
            libio::output::println("  " + kv.first + "=" + kv.second);
        }
        libio::output::println();

        throw ParserException("No value, but maybe you mistyped, upper you will see some values from section");
    }
    throw ParserException("Unknown section name");
}

#endif
