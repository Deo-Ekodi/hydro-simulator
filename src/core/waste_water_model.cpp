#include "../../include/core/waste_water_model.hpp"

using namespace core;
using namespace io;

void WasteWaterModel::initialize(const InputHandler& input_handler, const ConfigParser& config_parser)
{
    setup_pipe__network(input_handler);
    boundary_conditions = std::make_shared<BoundaryConditions>();
    boundary_conditions->load_input_from_configparser(config_parser);
    simulation_time = 0.0;
    
    // setup timestep from ConfigParser or InputHandler
    validate_model();
}

void WasteWaterModel::run_simulation()
{
    std::cout << "[ in WWM ]" << std::endl;
    while (1)   /* simulation time < config_parser's total simulation time */
    {
        apply_boundary_conditions(*boundary_conditions);
        solve_flow_equations();
        update_results();

        simulation_time += timestep;
        std::cout << "WWM: running ..." << std::endl;
    }
    
}

void WasteWaterModel::apply_boundary_conditions(const BoundaryConditions& condition)
{
    for (auto& pipe : pipes) {
        boundary_conditions->apply_to_pipe(*pipe);
    }
}

const Results& WasteWaterModel::get_results () const {
    return simulation_results;
}

void WasteWaterModel::modify_results (OutputHandler& from_output_stream)
{
    // output handler can modify results
}

void WasteWaterModel::setup_pipe__network(const InputHandler& inp)
{
    ;
}

void WasteWaterModel::validate_model () const
{
    // validate params
}

void WasteWaterModel::solve_flow_equations()
{
    /* core computational fluid dynamics (CFD) algorithm */
}

void WasteWaterModel::update_results ()
{
    ;
}