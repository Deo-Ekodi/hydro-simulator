#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <iostream>
#include <unordered_map>
#include <variant>
#include <cstdint>
#include <vector>
#include <stdexcept>
#include <sstream>

class InputHandlerException : public std::runtime_error
{
public:
    explicit InputHandlerException(const std::string& msg)
        : std::runtime_error ("input_handler : " + msg) {}
};

using variantType = std::variant<std::string, double, uint32_t, int>;

class InputHandler
{
public:
    /**
     * string e.g. NODE1, NODE2, 
     * variant contains data in columns
     */
    std::unordered_map< std::string, std::vector<variantType>> get_input_data();
    uint32_t rows () const {
        return row_count;
    }
    void log() const;
    void log_columns() const;
    std::vector<variantType> get_column_data(const std::string&);
    friend std::vector<variantType> column_data(const std::string& column, InputHandler& input)
    {
        return input.get_column_data (column);
    }

    InputHandler(const std::string& filename)
        : file_name (filename)
    {
        row_count = 0;
    }
    
    InputHandler (const InputHandler&) = delete;
    InputHandler& operator= (const InputHandler&) = delete;

    InputHandler (InputHandler&&) noexcept = default;
    InputHandler& operator= (InputHandler&&) noexcept = default;

private:
    uint32_t row_count;
    std::string file_name;
    /**
     * column names used as keys
     */
    std::vector<std::string> column_names;
    std::unordered_map< std::string, std::vector<variantType>> input_data;
};

#endif
