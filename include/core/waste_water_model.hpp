#ifndef WWM_H
#define WWM_H

#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include <iostream>

#include "../io/output_handler.hpp"
#include "../io/config_parser.hpp"
#include "../io/input_handler.hpp"
#include "boundary_conditions.hpp"
#include "output_handler.hpp"
#include "results.hpp"
#include "pipe.hpp"


/**
 * WasteWaterModel (alias WWM)
 * 1. Initialization
 * 2. Run Simulation loop
 * 3. Collect and store results
 * 4. Interraction with other classes
 *      - @class InputHandler
 *      - @class ConfigParser
 *      - @class Pipe
 *      - @class FLowSolver 
 *      - @class QualitySolver
 *      - @class BoundaryConditions
 *      - @class Results
 *      - @class CommandLineUI
 *      - @class OutputHandler
 */


namespace core
{
    class WasteWaterModelException : public std::runtime_error
    {
    public:
        explicit WasteWaterModelException(const std::string& msg)
            : std::runtime_error (msg) {}
    };
    
    class WasteWaterModel
    {
    private:
        /* set up pipe network */
        void setup_pipe__network(const InputHandler&);
        /* validate model setup */
        void validate_model() const;
        /* solve flow equations */
        void solve_flow_equations();
        /* update results after simulation */
        void update_results();

        std::vector<std::shared_ptr<Pipe> > pipes;
        Results simulation_results;
        std::shared_ptr<BoundaryConditions> boundary_conditions;
        double simulation_time;
        double timestep;
    public:
        WasteWaterModel(/* args */) = default;

        WasteWaterModel (const WasteWaterModel&) = delete;
        WasteWaterModel& operator= (const WasteWaterModel&) = delete;

        WasteWaterModel (WasteWaterModel&&) noexcept = default;
        WasteWaterModel& operator= (WasteWaterModel&&) noexcept = default;

        /* initialize model parameters */
        void initialize (const InputHandler&, const ConfigParser&);
        /* run simulation */
        void run_simulation();
        /* boundary conditions - if any */
        void apply_boundary_conditions(const BoundaryConditions&);
        /* retrieve results */
        const Results& get_results() const;
        /* real-time modification of results */
        void modify_results(OutputHandler&);

        ~WasteWaterModel() noexcept = default;
    };

} // namespace core


#endif