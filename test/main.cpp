#include "inputhandler.hpp"

int main()
{
    InputHandler input("data.tsv");
    input.get_input_data();
    // input.log();
    std::string state = "Status";
    std::vector<variantType> vec = input.get_column_data(state);


    for (const auto& val : vec) {
        if (std::holds_alternative<uint32_t>(val)){
            std::visit ([=] (const auto& x) {
                std::cout << x << "\t" << typeid(x).name() << std::endl;
            }, val);
        }
        if (std::holds_alternative<double>(val)) {
            std::visit ([=] (const auto& x) {
                std::cout << x << "\t" << typeid(x).name() << std::endl;
            }, val);
        }
        if (std::holds_alternative<std::string>(val)) {
            std::visit ([=] (const auto& x) {
                std::cout << x << "\t" << typeid(x).name() << std::endl;
            }, val);
        }
    }

    return 0;
}