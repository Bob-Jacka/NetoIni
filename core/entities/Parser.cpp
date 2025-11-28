#include "Parser.hpp"

#include "../data/Constants.hpp"
#include "../exceptions/ParserException.hpp"


Parser_n::Parser::Parser(const std::string &filename) {
    this->sections = new std::vector<Section>();
    this->filename = filename;
    parse_lines();
}

/**
 * Get line from main stream and decide for decision.
 */
void Parser_n::Parser::parse_lines() const {
    std::vector<std::string> lines = libio::file::readFile(filename);
    for (int i = 0; i < lines.size(); ++i) {
        const auto line = libio::string::delete_whitespaces(lines[i]);
        if (line.starts_with(start_section)) {
            const auto sec_name = line.substr(1, line.length() - 1);
            auto section = Section(sec_name);

            while (true) {
                ++i;
                const auto &inner_line = lines[i];
                auto split_line = libio::string::split(inner_line, "=");
                if (split_line.size() == 2) {
                    section.add_value(split_line[0], split_line[1]);
                } else if (split_line.size() == 1) {
                    section.add_value(split_line[0], default_value);
                } else {
                    throw ParserException("Incorrect section value");
                }
                break;
            }
            this->sections->push_back(section);
        }
    }
}

/**
 * Get value from section object
 * @tparam T generic param
 * @param section_param string value
 * @return generic parameter value from section
 */
template<typename T>
    requires std::integral<T> || libio::type_constrains::is_string<T>
T Parser_n::Parser::get_value(const std::string &section_param) const {
    if (section_param.contains(".")) {
        const auto split_line = libio::string::split(section_param, "."); //0 - name of the section and 1 - name of the value
        for (const Section &section: this->sections) {
            if (split_line[0] == section.get_name()) {
                allowed_types value = section.get_value_from_map(split_line[1]);
                return std::get<T>(value);
            }
        }
        throw ParserException("No value found");
    }
    throw ParserException("Unknown section name");
}
