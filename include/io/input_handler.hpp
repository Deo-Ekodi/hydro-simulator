#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <cstdint>

namespace io
{
    class InputHandlerException : public std::runtime_error
    {
    public:
        explicit InputHandlerException(const std::string& msg)
            : std::runtime_error(msg) {}
    };

    class InputHandler
    {
    public:
        explicit InputHandler(const std::string& filename);

        InputHandler(const InputHandler&) = delete;
        InputHandler& operator= (const InputHandler&) = delete;

        InputHandler(InputHandler&&) noexcept = default;
        InputHandler& operator= (InputHandler&&) noexcept = default;

        void read_tsv();
        void read_csv();

        std::vector<std::string> get_column_data(const std::string& column_name) const;
        std::string get_cell_data(uint32_t row, const std::string& column_name) const;

        ~InputHandler() noexcept = default;
    private:
        /* name of file parsed */
        std::string file_name;
        /* holding parsed data */
        std::vector<std::unordered_map<std::string, std::string> > data;
        /* list of column names */
        std::vector<std::string> column_names;
        /* parse single line */
        std::unordered_map<std::string, std::string> parse_line(const std:: string& line);
    };
    

    
    
} // namespace io


#endif