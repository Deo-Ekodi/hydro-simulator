#include "inputhandler.hpp"
#include <fstream>
#include <iomanip>

bool is_double(const std::string &str)
{
    std::istringstream iss(str);
    double d;
    return iss >> d >> std::ws && iss.eof();
}

bool isUint32_t(const std::string &str)
{
    std::istringstream iss(str);
    uint32_t u;
    return iss >> u >> std::ws && iss.eof();
}

std::unordered_map<std::string, std::vector<variantType>> InputHandler::get_input_data()
{
    // std::unordered_map<std::string, std::vector<variantType>> input_data;

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
                if (is_double(value))
                {
                    input_data[column_names[index]].emplace_back(std::stod(value));
                }
                if (isUint32_t(value))
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

    // std::string line;
    // bool is_first_line = true;

    // while (std::getline(file, line))
    // {
    //     if (is_first_line)
    //     {
    //         // check more on stringstream
    //         std::stringstream ss(line);
    //         std::string column_name;

    //         while (std::getline(ss, column_name, '\t'))
    //         {
    //             column_names.emplace_back(column_name);
    //         }
    //         is_first_line = false;
    //     }
    //     if (!is_first_line) {
    //         std::stringstream ss(line);
    //         std::string cell;
    //         uint32_t column_index = 0;
    //         uint32_t max_column_index = column_names.size();

    //         while (std::getline(ss, cell, '\t'))
    //         {
    //             if (column_index < max_column_index)
    //             {
    //                 if (isUint32_t(cell)) {
    //                     input_data[column_names[column_index]].emplace_back(static_cast<double>(std::stoul(cell)));
    //                 }
    //                 if (is_double(cell)) {
    //                     input_data[column_names[column_index]].emplace_back(static_cast<double>(std::stod(cell)));
    //                 }
    //                 else {
    //                     input_data[column_names[column_index]].emplace_back(cell);
    //                 }

    //                 ++column_index;
    //             }
    //             else {
    //                 throw InputHandlerException ("col: " + column_names[column_index] + "more rows than columns!");
    //             }
    //         }
    //     }
    //     else
    //     {
    //         throw InputHandlerException("more cells than columns in line : " + line);
    //     }
    // }

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
                       { std::cout << std::setw(9) << val << "\t"; }, values[i]);
        }
        std::cout << std::endl;
    }

    // for(const auto& [key, values] : input_data) {

    //     for (const auto& value : values) {

    //         std::visit ([](const auto& val) {
    //             std::cout << val << '\t';
    //         }, value);
    //     }
    // }
}