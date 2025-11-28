#include "Section.hpp"


Parser_n::Section::Section(const std::string &name) {
    this->name = name;
    this->section_values = new std::map<std::string, std::variant<std::string, int> >();
}

Parser_n::Section::Section(const Section &other) {
    this->name = other.name;
    this->section_values = new std::map<std::string, std::variant<std::string, int> >();
}

std::string Parser_n::Section::get_name() const {
    return this->name;
}

std::map<std::string, std::variant<std::string, int> > *Parser_n::Section::get_values() const {
    return this->section_values;
}

std::variant<std::string, int> Parser_n::Section::get_value_from_map(const std::string &value_key) const {
    return this->section_values->at(value_key);
}

void Parser_n::Section::add_value(const std::string &, const std::variant<std::string, int> &) {
    this->section_values->emplace(this->name, std::variant<std::string, int>());
}
