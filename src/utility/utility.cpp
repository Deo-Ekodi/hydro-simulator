#include "../../include/utility/utility.hpp"
#include "../../include/io/input_handler.hpp"

using namespace util;
using namespace hydro;

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