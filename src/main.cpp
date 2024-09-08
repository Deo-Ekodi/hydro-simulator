#include "../include/io/input_handler.hpp"
#include "../include/core/pipe.hpp"
#include "../include/core/waste_water_model.hpp"

int main()
{
    WasteWaterModel model;
    model.run_simulation();
    return 0;
}