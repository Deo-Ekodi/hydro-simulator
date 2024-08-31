#include "../../include/utility/utility.hpp"

using namespace util;

bool _isdouble (const std::string& str) {
    std::istringstream iss(str);
    double d;
    return iss >> d >> std::ws && iss.eof();
}

bool _isuint32_t(const std::string& str) {
    std::istringstream iss (str);
    uint32_t u;
    return iss >> u >> std::ws && iss.eof();
}