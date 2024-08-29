#ifndef BOUNDARY_H
#define BOUNDARY_H

#include <unordered_map>
#include <string>
#include <stdexcept>
#include <vector>
#include <iostream>

#include "../io/input_handler.hpp"
#include "../io/config_parser.hpp"
#include "pipe.hpp"
#include "waste_water_model.hpp"

using namespace io;

namespace core
{
    enum class BoundaryType
    {
        INLET, OUTLET, PRESSURE, FLOWRATE
    };

    struct BoundaryCondition
    {
        BoundaryType type;
        double value;
        std::string& description;
    };
    
    class BoundaryConditionException : public std::runtime_error
    {
    public:
        explicit BoundaryConditionException(const std::string& msg)
            : std::runtime_error("boundary conditions : " + msg) {}
    };

    class BoundaryConditions
    {
    private:
        std::unordered_map<std::string, BoundaryCondition> conditions;
        void validate_condition(const BoundaryCondition&) const;
    public:
        BoundaryConditions(/* args */) = default;

        BoundaryConditions(const BoundaryConditions&) = delete;
        BoundaryConditions& operator= (const BoundaryConditions&) = delete;

        BoundaryConditions (BoundaryConditions&&) noexcept = default;
        BoundaryConditions& operator= (BoundaryConditions&&) noexcept = default;

        void add_condition(const std::string& location, BoundaryType type, double value, std::string description);
        void load_input_from_inputhandler (InputHandler&);
        void load_input_from_configparser (const ConfigParser&);

        const BoundaryConditions& get_condition (const std::string&) const;
        void validate_conditions() const;
        void validate_condition() const;
        void apply_to_model(WasteWaterModel&) const;
        void apply_to_pipe(Pipe&) const;
        ~BoundaryConditions() noexcept = default;
    };

} // namespace core


#endif