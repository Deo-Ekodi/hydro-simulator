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

using variantType = std::variant<std::string, double, uint32_t>;

class InputHandler
{
public:
    /**
     * string e.g. NODE1, NODE2, 
     * variant contains data in columns
     */
    std::unordered_map< std::string, std::vector<variantType>> get_input_data();
    /**
     * column names used as keys
     */
    std::vector<std::string> column_names;
    std::unordered_map< std::string, std::vector<variantType>> input_data;
    void log() const;

    InputHandler(const std::string& filename)
        : file_name (filename) {}
    
    InputHandler (const InputHandler&) = delete;
    InputHandler& operator= (const InputHandler&) = delete;

    InputHandler (InputHandler&&) noexcept = default;
    InputHandler& operator= (InputHandler&&) noexcept = default;

    std::string file_name;

};

#endif
