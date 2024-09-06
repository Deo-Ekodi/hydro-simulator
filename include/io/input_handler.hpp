#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <iostream>
#include <cstdint>
#include <variant>

namespace hydro
{
    class InputHandlerException : public std::runtime_error
    {
    public:
        explicit InputHandlerException(const std::string& msg)
            : std::runtime_error(msg) {}
    };

    using variantType = std::variant<std::string, uint32_t, double>;

    class InputHandler
    {
    public:
        explicit InputHandler(const std::string& filename);

        InputHandler(const InputHandler&) = delete;
        InputHandler& operator= (const InputHandler&) = delete;

        InputHandler(InputHandler&&) noexcept = default;
        InputHandler& operator= (InputHandler&&) noexcept = default;

        std::unordered_map<std::string, std::vector<variantType>> get_input_data();

        // InputHandler get_boundary_conditions () const;

        ~InputHandler() noexcept = default;

        /* name of file parsed */
        std::string file_name;
        /* holding parsed data */
        std::unordered_map<std::string, std::vector<variantType>> input_data;
        /* list of column names */
        std::vector<std::string> column_names;
        void log() const;
        void log_columns() const;
        std::vector<variantType> get_column_data(const std::string&) const;
        bool is_valid(const std::unordered_map<std::string, std::vector<variantType>>&) const;
    };
    

    
    
} // namespace hydro


#endif