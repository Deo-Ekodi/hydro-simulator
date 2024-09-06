#include "../../include/io/config_parser.hpp"

using namespace hydro;

ConfigParser::ConfigParser(const std::string& filename)
    : file_name(filename) {}

void ConfigParser::parse_csv()
{
    std::ifstream file(file_name);
    if (!file.is_open()){
        throw ConfigParserException ("failed to open file : " + file_name);
    }

    std::string line;
    while(std::getline(file, line)) {
        auto parsed_line = parse_line(line);
        config.emplace(parsed_line.first, parsed_line.second);
    }

    file.close();
}

void ConfigParser::parse_tsv()
{
    ;
}

double ConfigParser::get_configuration_value(const std::string& key) const {
    auto it = config.find(key);
    if(it != config.end()){
        return it->second;
    } 
    else {
        throw ConfigParserException ("config key not found : " + key);
    }
}

void ConfigParser::validate_parameters() const 
{
    for (const auto& [key, value] : config){
        if (value < 0){
            throw ConfigParserException ("invalid value for : " + key);
        }
    }
}

std::pair<std::string, double> ConfigParser::parse_line(const std::string& line)
{
    std::istringstream ss(line);
    std::string key;
    double value;

    if(std::getline(ss, key, '\t')) {
        if(ss >> value) {
            return std::make_pair(key, value);
        }
        else{
            throw ConfigParserException ("failed to parse value for key : " + key);
        }
    }
    else {
        throw ConfigParserException ("failed to parse key in line : " + line);
    }
}