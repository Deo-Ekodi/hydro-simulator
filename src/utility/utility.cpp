#include "../../include/utility/utility.hpp"
#include "../../include/io/input_handler.hpp"

using namespace hydro;
namespace hydro
{
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

bool is_valid(const std::unordered_map<std::string, std::vector<variantType>>& data)
{
    for (const auto& pair : data) {
        if (pair.second.empty()) {
            return false;
        }
    }
    return true;
}

} // namespace hydro