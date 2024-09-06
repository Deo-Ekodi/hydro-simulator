#include "inputhandler.hpp"
#include <fstream>
#include <iomanip>
#include <cctype>
#include <algorithm>

bool is_uint(const std::string& str){
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

bool is_double(const std::string& str){
    std::istringstream iss(str);
    double d;
    iss >> std::noskipws >> d;
    return iss.eof() && !iss.fail();
}

bool is_alphabetic(const std::string& str){
    for (const auto& x : str) {
        if (!isalpha((int)x)) {
            return false;
        }
    }
    return true;
}

void printVariant(const variantType& var) {
    std::visit([](const auto& value) {
        std::cout << value << " ";  // Print the value stored in the variant
    }, var);
}

std::unordered_map<std::string, std::vector<variantType>> InputHandler::get_input_data()
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
                // double can be narrow converted to uint32_t
                if (is_double(value) && !is_uint(value))
                {
                    input_data[column_names[index]].emplace_back(std::stod(value));
                }
                // uint32_t can't be read as a double
                if (is_uint(value))
                {
                    input_data[column_names[index]].emplace_back(static_cast<uint32_t>(std::stoul(value)));
                }
                // std::string is neither double nor uint
                if (!is_double(value) && !(is_uint(value)))
                {
                    input_data[column_names[index]].emplace_back(value);
                }
                ++index;
            }
        }
    }
    // for (const auto& [key, vec]: input_data){
    //     std::cout << key << "\t" << vec.size() << std::endl;
    // }
    file.close();
    return input_data;
}

void InputHandler::log() const
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
                       { std::cout << std::setw(9) << typeid(val).name() << "\t"; }, values[i]);
        }
        std::cout << std::endl;
    }
}

void InputHandler::log_columns () const
{
    for (const auto& pair : input_data) {
        std::cout << pair.first << std::endl;  // pair.first gives the key (std::string)
    }

    std::cout << std::endl;
}

std::vector<variantType> InputHandler::get_column_data(const std::string &key)
{
    if (std::count(column_names.begin(), column_names.end(), key) > 0){
        std::vector<variantType> vec = input_data[key];
        return vec;
    }
    else {
        throw InputHandlerException ("failed to read column [" + key + "]");
    }
}
