#ifndef WWM_HH
#define WWM_HH

#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include <iostream>

#include "node.hpp"
#include "pipe.hpp"
#include "inputhandler.hpp"


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

class WasteWaterModelException : public std::runtime_error
{
public:
    explicit WasteWaterModelException(const std::string& msg)
        : std::runtime_error ("WWModel : " + msg) {}
};

class WasteWaterModel
{
public:
    /* set up pipe network */
    void setup_pipe_network(std::unordered_map<std::string, std::vector<variantType>>&);
    /* validate model setup */
    void validate_model() const;
    /* solve flow equations */
    void solve_flow_equations();
    /* update results after simulation */
    void update_results();
    void log_pipes() const;

    // std::vector<std::shared_ptr<Pipe> > pipes;
    std::vector<Pipe> pipes;

    WasteWaterModel(/* args */) = default;

    WasteWaterModel (const WasteWaterModel&) = delete;
    WasteWaterModel& operator= (const WasteWaterModel&) = delete;

    WasteWaterModel (WasteWaterModel&&) noexcept = default;
    WasteWaterModel& operator= (WasteWaterModel&&) noexcept = default;

    /* initialize model parameters */
    // void initialize (const InputHandler&, const ConfigParser&);
    void initialize();
    /* run simulation */
    void run_simulation();

    ~WasteWaterModel() noexcept = default;
};

#endif