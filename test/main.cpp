#include "inputhandler.hpp"
#include "wwm.hpp"

int main()
{
    InputHandler input("data.tsv");
    // input.get_input_data();
    std::unordered_map<std::string, std::vector<variantType>> inp = input.get_input_data();
    WasteWaterModel model;
    model.setup_pipe_network(input);
    model.log_pipes();
    // input.log();
    // std::string state = "ID";
    // std::vector<variantType> vec = input.get_column_data(state);

    // for (const auto& val : vec) {
    //     if (std::holds_alternative<uint32_t>(val)){
    //         // std::visit ([=] (const auto& x) {
    //         //     std::cout << x << "\t" << typeid(x).name() << std::endl;
    //         // }, val);
    //         uint32_t v = std::get<uint32_t>(val);
    //         std::cout << v << std::endl;
    //     }
    //     if (std::holds_alternative<double>(val)) {
    //         std::visit ([=] (const auto& x) {
    //             std::cout << x << "\t" << typeid(x).name() << std::endl;
    //         }, val);
    //     }
    //     if (std::holds_alternative<std::string>(val)) {
    //         std::visit ([=] (const auto& x) {
    //             std::cout << x << "\t" << typeid(x).name() << std::endl;
    //         }, val);
    //     }
    // }

    return 0;
}