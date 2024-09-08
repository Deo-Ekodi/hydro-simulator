#include "../../include/core/waste_water_model.hpp"
#include <chrono>
#include <thread>

using namespace hydro;
using namespace hydro;

// void WasteWaterModel::initialize(const InputHandler& input_handler, const ConfigParser& config_parser)
void WasteWaterModel::initialize()
{
    /**
     * new instance of input handler
     */
    InputHandler input("data.tsv");

    setup_pipe__network(input);
    // boundary_conditions = std::make_shared<BoundaryConditions>();
    // boundary_conditions->load_input_from_configparser(config_parser);
    // simulation_time = 0.0;
    
    // setup timestep from ConfigParser or InputHandler
    // validate_model();
}

void WasteWaterModel::run_simulation()
{
    std::cout << "[ in WWM ]" << std::endl;
    std::cout << "Initializing model..." << std::endl;
    // animate sth here
    initialize();
    while (1)   /* simulation time < config_parser's total simulation time */
    {
        // apply_boundary_conditions(*boundary_conditions);
        // solve_flow_equations();
        // update_results();

        // simulation_time += timestep;
        std::cout << "WWM: [running] ";
        int dots = 5;
        int delay = 400;
        for (int i = 0; i < dots; ++i) {
            for (int j = 0; j < i; ++j) {
                std::cout << ".";
            }
            std::cout << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }
    }
    
}

// void WasteWaterModel::apply_boundary_conditions(const BoundaryConditions& condition)
// {
//     for (auto& pipe : pipes) {
//         boundary_conditions->apply_to_pipe(*pipe);
//     }
// }

// const Results& WasteWaterModel::get_results () const {
//     return simulation_results;
// }

// void WasteWaterModel::modify_results (OutputHandler& from_output_stream)
// {
//     // output handler can modify results
// }

void WasteWaterModel::setup_pipe__network(InputHandler& input)
{
    uint32_t index = 0;
    uint32_t number_of_pipes = input.rows();

    std::unordered_map<std::string, std::vector<variantType>> data = input.get_input_data();

    // get vectors for pipe data here - get_column_data(string) in InputHandler
    // initalize pipes here
    std::string ID = "ID", Diameter = "Diameter", Node1 = "Node1", Node2 = "Node2", Length = "Length";

    std::vector<variantType> id = input.get_column_data(ID);
    std::vector<variantType> length = input.get_column_data(Length);
    std::vector<variantType> node1 = input.get_column_data(Node1);
    std::vector<variantType> node2 = input.get_column_data(Node2);
    std::vector<variantType> diameter = input.get_column_data(Diameter);

    while (index < number_of_pipes) {
        Pipe pipe;
        pipe.id = std::get<uint32_t>(id.at(index));
        pipe.diameter = std::get<double>(diameter.at(index));
        pipe.length = std::get<double>(length.at(index));
        pipe.start_node->id = std::get<uint32_t>(node1.at(index));
        pipe.end_node->id = std::get<uint32_t>(node2.at(index));

        pipes.push_back(pipe);
        ++index;
    }
}

// void WasteWaterModel::validate_model () const
// {
//     // validate params
// }

// void WasteWaterModel::solve_flow_equations()
// {
//     /* core computational fluid dynamics (CFD) algorithm */
// }

// void WasteWaterModel::update_results ()
// {
//     ;
// }