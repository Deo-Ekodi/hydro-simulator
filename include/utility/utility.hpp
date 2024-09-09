#ifndef UTILITYH_H
#define UtILITYH_H

#include "../io/input_handler.hpp"
#include "../util.hpp"
#include <unordered_map>

#include <string>
#include <cstdint>
#include <sstream>

namespace hydro
{
    bool is_double(const std::string&);
    bool is_uint(const std::string&);
    // validate input data from input stream
    bool is_valid(const std::unordered_map<std::string, std::vector<variantType>>&);
};

#endif