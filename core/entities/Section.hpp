#ifndef SECTION_HPP
#define SECTION_HPP

#include <map>
#include <string>
#include <variant>

/**
* Private namespace for section in ini file
*/
namespace Parser_n {
    using allowed_types = std::variant<std::string, int>;

    /**
     * Struct representing section in ini file.
     * Contains values.
     */
    struct Section {
    private:
        std::string name;
        std::map<std::string, allowed_types> *section_values;

    public:
        explicit Section(const std::string &);

        Section() = delete;

        Section(const Section &);

        ~Section() = default;

        [[nodiscard]] std::string get_name() const;

        [[nodiscard]] std::map<std::string, std::variant<std::string, int> > *get_values() const;

        [[nodiscard]] std::variant<std::string, int> get_value_from_map(const std::string &) const;

        void add_value(const std::string &, const std::variant<std::string, int> &);
    };
}

#endif
