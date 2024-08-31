#include "../../include/io/input_handler.hpp"
#include "../../include/utility/utility.hpp"

#include <iomanip>
#include <fstream>
#include <sstream>

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

    // read header keys
    std::getline(file, line);
    std::istringstream headerstream(line);
    std::string key;

    while (std::getline(headerstream, key, '\t'))
    {
        input_data[key] = std::vector<variantType>();
        column_names.push_back(key);
    }

    // read data
    while (std::getline(file, line))
    {
        std::istringstream linestream(line);
        std::string value;
        uint32_t index = 0;

        while (std::getline(linestream, value, '\t'))
        {
            if (index < column_names.size())
            {
                if (util::_isdouble(value))
                {
                    input_data[column_names[index]].emplace_back(std::stod(value));
                }
                if (util::_isuint32_t(value))
                {
                    input_data[column_names[index]].emplace_back(static_cast<uint32_t>(std::stoul(value)));
                }
                else
                {
                    input_data[column_names[index]].emplace_back(value);
                }
                ++index;
            }
        }
    }
    return input_data;
}

void io::InputHandler::log() const
{
    // validate input_data before logging - tbd

    for (const auto &[key, _] : input_data)
    {
        std::cout << std::setw(9) << key << "\t";
    }

    std::cout << std::endl;

    // number of rows
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