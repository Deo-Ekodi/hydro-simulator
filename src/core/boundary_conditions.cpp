#include "../../include/core/boundary_conditions.hpp"

using namespace hydro;
using namespace hydro;

void BoundaryConditions::add_condition(const std::string& location, BoundaryType type, double value, std::string description = "")
{
    if(conditions.find(location) != conditions.end())  {
        throw BoundaryConditionException ("boundary condition already exists for : " + location);
    }

    BoundaryCondition condition {type, value, description};
    conditions.emplace(location, condition);
}

void BoundaryConditions::load_input_from_inputhandler(InputHandler& input)
{
    // 
}

void BoundaryConditions::load_input_from_configparser(const ConfigParser& cfg)
{
    // 
}

const BoundaryConditions& BoundaryConditions::get_condition (const std::string&) const
{
    return;
}

void BoundaryConditions::validate_conditions() const
{
    ;
}

void BoundaryConditions::apply_to_model(WasteWaterModel& model) const
{
    ;
}

void BoundaryConditions::apply_to_pipe(Pipe& pipe) const
{
    ;
}

void BoundaryConditions::validate_condition () const
{
    /**
     * BoundaryType::inlet
     * BoundaryType::outlet
     * BoundaryType::pressure
     * BoundaryType::flowrate
     */
}