#pragma once

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
    class WasteWaterModel
    {
    private:
        /* data */
    public:
        WasteWaterModel(/* args */);
        ~WasteWaterModel();
    };

} // namespace core
