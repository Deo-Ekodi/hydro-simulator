#include "../../include/io/input_handler.hpp"
#include "../../include/utility/utility.hpp"

#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace io;

io::InputHandler::InputHandler(const std::string& filename)
    : file_name (filename) {}

std::unordered_map<std::string, std::vector<io::variantType>> io::InputHandler::get_input_data()
{
    std::ifstream file(file_name);
    if (!file.is_open())
    {
        throw InputHandlerException("failed to open " + file_name);
    }

    std::string line;

    // read header keys - columns
    std::getline(file, line);
    std::istringstream headerstream(line);
    std::string key;

    while (std::getline(headerstream, key, '\t'))
    {
        key.erase(std::remove(key.begin(), key.end(), '\r'), key.end());
        input_data[key] = std::vector<variantType>();
        column_names.push_back(key);
    }

    // read data
    while (std::getline(file, line))
    {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        std::istringstream linestream(line);
        std::string value;
        uint32_t index = 0;

        while (std::getline(linestream, value, '\t'))
        {
            if (index < column_names.size())
            {
                if (util::is_double(value))
                {
                    input_data[column_names[index]].emplace_back(std::stod(value));
                }
                if (util::is_uint(value) && !util::is_double(value))
                {
                    input_data[column_names[index]].emplace_back(static_cast<uint32_t>(std::stoul(value)));
                }
                if (!util::is_double(value) && !(util::is_uint(value)))
                {
                    input_data[column_names[index]].emplace_back(value);
                }
                ++index;
            }
        }
    }

    file.close();
    return input_data;
}

void io::InputHandler::log() const
{
    // validate input_data before logging

    if (!is_valid(input_data)) {
        throw InputHandlerException ("failed to validate data. Make sure to fill empty labelled columns");
    }

    // log keys
    for (const auto &[key, _] : input_data)
    {
        std::cout << std::setw(9) << key << "\t";
    }

    std::cout << std::endl;

    // logging rows
    uint32_t rows = input_data.begin()->second.size();

    for (uint32_t i{0}; i < rows; ++i)
    {
        for (const auto &[key, values] : input_data)
        {
            std::visit([](const auto &val)
                       { std::cout << std::setw(9) << val << "\t"; }, values[i]);
        }
        std::cout << std::endl;
    }
}

void io::InputHandler::log_columns () const
{
    for (const auto& pair : input_data) {
        std::cout << pair.first << std::endl;  // pair.first gives the key (std::string)
    }

    std::cout << std::endl;
}

std::vector<variantType> io::InputHandler::get_column_data(const std::string &key) const
{
    if (std::count(column_names.begin(), column_names.end(), key) > 0){
        std::vector<variantType> vec = input_data[key];
        return vec;
    }
    else {
        throw InputHandlerException ("failed to read column [" + key + "]");
    }
}

bool io::InputHandler::is_valid(const std::unordered_map<std::string, std::vector<variantType>>& data) const
{
    for (const auto& pair : data) {
        if (pair.second.empty()) {
            return false;
        }
    }
    return true;
}