#include "Parser.hpp"

Parser_n::ini_parser::ini_parser(const std::string &filename) {
    std::vector<std::string> lines = libio::file::readFile(filename);
    this->sections = parse_ini_from_vector(lines);
}

std::map<std::string, std::map<std::string, std::string>>
Parser_n::ini_parser::parse_ini_from_vector(const std::vector<std::string> &lines) {
    std::map<std::string, std::map<std::string, std::string>> sections_ini;
    std::string current_section;

    for (const auto &line: lines) {
        std::string trimmed = libio::string::trim(line);

        if (trimmed.empty()) {
            continue;
        }

        if (trimmed[0] == comment_start) {
            continue;
        }

        if (trimmed[0] == start_section && trimmed.back() == end_section) {
            current_section = libio::string::trim(trimmed.substr(1, trimmed.size() - 2));
            continue;
        }

        size_t equal_pos = trimmed.find(value_splitter);
        if (equal_pos != std::string::npos) {
            std::string key = libio::string::trim(trimmed.substr(0, equal_pos));
            std::string value_with_comment = libio::string::trim(trimmed.substr(equal_pos + 1));

            size_t semicolon_pos = value_with_comment.find(comment_start);
            std::string value = (semicolon_pos != std::string::npos) ?
                                libio::string::trim(value_with_comment.substr(0, semicolon_pos)) :
                                value_with_comment;

            if (!current_section.empty()) {
                sections_ini[current_section][key] = value;
            }
        }
    }

    return sections_ini;
}
