#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include <string>
#include <unordered_map>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <iostream>

namespace hydro
{
    class ConfigParserException : public std::runtime_error
    {
    public:
        explicit ConfigParserException(const std::string& msg)
            : std::runtime_error("config_parser : " + msg) {}
    };

    /**
     * handles configuration files and parsing to boundary conditions and inputhandler
     */
    class ConfigParser
    {
    public:
        ConfigParser(const std::string&);

        ConfigParser(const ConfigParser&) = delete;
        ConfigParser& operator= (const ConfigParser&) = delete;

        ConfigParser (ConfigParser&&) noexcept = default;
        ConfigParser& operator= (ConfigParser&&) noexcept = default;

        void parse_csv();
        void parse_tsv();

        double get_configuration_value(const std::string& key) const;
        void validate_parameters() const;

        ~ConfigParser() noexcept = default;

    private:
        /* name of configuration file */
        std::string file_name;
        /* map to store configuration parameters */
        std::unordered_map<std::string, double> config;
        /* parsing a single line in the configuration file */
        std::pair<std::string, double> parse_line(const std::string& line);
    };

} // namespace hydro



#endif