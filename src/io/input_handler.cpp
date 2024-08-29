#include "../../include/io/input_handler.hpp"

using namespace io;

InputHandler::InputHandler(const std::string& filename)
    : file_name (filename) {}

void InputHandler::read_csv()
{
    ;
}

void InputHandler::read_tsv()
{
    std::ifstream file(file_name);
    if(!file.is_open()){
        throw InputHandlerException ("failed to open file : " + file_name);
    }

    std::string line;
    bool is_firstline = true;

    while(std::getline(file, line)) {
        if(is_firstline){
            // first line : column headers
            std::stringstream ss(line);
            std::string column_name;

            while(std::getline(ss, column_name, '\t')) {
                column_names.emplace_back(column_name);
            }

            is_firstline = false;
        }

        else {
            // not first line i.e. has data
            data.emplace_back(parse_line(line));
        }
    }

    file.close();
}

std::vector<std::string> InputHandler::get_column_data(const std::string& column_name) const
{
    std::vector<std::string> columndata;
    for(const auto& row : data){
        auto it = row.find(column_name);
        if(it != row.end()) {
            columndata.emplace_back(it->second);
        }
        else{
            throw InputHandlerException ("column not found : " + column_name);
        }
    }
    return columndata;
}

std::string InputHandler::get_cell_data(uint32_t row, const std::string& column_name) const
{
    if (row >= data.size()) {
        throw InputHandlerException ("row out of bounds : " + std::to_string(row));
    }

    auto it = data[row].find(column_name);
    if (it != data[row].end()) {
        return it->second;
    }
    else {
        throw InputHandlerException ("column not found : " + column_name);
    }
}

std::unordered_map<std::string, std::string> InputHandler::parse_line(const std::string& line)
{
    std::unordered_map<std::string, std::string> row_data;
    std::stringstream ss(line);
    std::string cell;
    uint32_t column_index = 0;

    while (std::getline(ss, cell, '\t')) {
        if (column_index < column_names.size()) {
            row_data[column_names[column_index]] = cell;
            ++column_index;
        }
        else {
            throw InputHandlerException ("more cells than columns in line : " + line);
        }
    }

    return row_data;
}