#include "../include/io/input_handler.hpp"
#include "../include/core/pipe.hpp"
#include "../include/core/waste_water_model.hpp"

using namespace hydro;

int main()
{
    InputHandler input("data.tsv");
    input.get_input_data();
    WasteWaterModel model;
    model.setup_pipes(input);
    model.log_pipes();
    return 0;
}