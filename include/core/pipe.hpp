#ifndef PIPE_H
#define PIPE_H

#include "../util.hpp"
#include "../utility/Node.hpp"

#include <cstdint>
#include <string>
#include <initializer_list>
#include <vector>
#include <cstdbool>
#include <iostream>
#include <numbers>
#include <cmath>
#include <exception>

using namespace hydro;

namespace hydro
{

	// constexpr double gravity = 9.81;
	class Pipe
	{
	public:
		Pipe() = default;
		// Pipe(
		// 	uint32_t _id, double _length, 
		// 	double _diameter, double _roughness = 0.0, 
		// 	double _slope = 0.0, Node* _start, Node* _end)
		// 	: id(_id), 
		// 	length(_length),
		// 	diameter(_diameter), 
		// 	roughness(_roughness), 
		// 	slope(_slope), 
		// 	start_node(_start), 
		// 	end_node(_end)
		// 	{
		// 		// initialize_default_values();
		// 	}

		// core attributes
		uint32_t id;					/* unique identifier */
		double length;					/* length of pipe */
		// double roughnesss				/* gradient */
		double diameter;				/* diameter if pipe*/
		// Node* start_node;				/* start node */
		// Node* end_node;					/* end node */

		// // flow attributes
		// double flowrate;
		// double velocity;
		// double pressure;
		// double headloss;
		// double reynoldsnumber;
		// double maxflowrate;
		// bool is_flowreversed;

		// // quality attributes
		// std::vector<double> pollutantconcentration;			/* mg/L */
		// double temperature;
		// double pH;
		// double dissolvedoxygen;
		// double BOD;
		// double COD;
		// double decaycoefficient;		/* pollutant decay */

		// // structural attributes
		// double wallthickness;
		// double maximumpressure;
		// double corrosionrate;
		// double age;
		// double leakagerate;
		// double healthindex;
		// std::string material;
		// bool is_corroded;

		// // Maintenance attributes
		// bool needs_inspection;          /* Flag for inspection necessity */
		// double lastinspectiondate;     /* Date of last inspection (Julian date) */
		// double repaircostestimate;     /* Estimated cost for repair ($) */
		// bool is_underrepair;            /* Repair status (true/false) */

		// // initialize to default values
		// void initialize_default_values()
		// {
		// 	flowrate = 0.0;
		// 	velocity = 0.0;
		// 	pressure = 0.0;
		// 	headloss = 0.0;
		// 	maxflowrate = calculate_max_flowrate();
		// 	reynoldsnumber = 0.0;
		// 	temperature = 0.0;
		// 	pH = 7.0;
		// 	dissolvedoxygen = 8.0;		/* typical D.O (mg/l) */
		// 	BOD = 0.0;
		// 	COD = 0.0;
		// 	wallthickness = 0.0;
		// 	maximumpressure = 0.0;
		// 	is_corroded = false;
		// 	corrosionrate = 0.0;
		// 	age = 0.0;
		// 	needs_inspection = false;
		// 	lastinspectiondate = 0.0;
		// 	repaircostestimate = 0.0;
		// 	is_underrepair = false;
		// 	healthindex = PERFECT;
		// 	leakagerate = 0.0;
		// 	decaycoefficient = POLLUTANT_DECAY_RATE;
		// 	is_flowreversed = false;
		// }

		// double calculate_max_flowrate()
		// {
		// 	return std::pow(diameter, 2) * slope * roughness;
		// }

		// // to be ckecked
		// void connect_to_network()
		// {
		// 	start_node->connect_pipe(id);
		// 	end_node->connect_pipe(id);
		// }

		// void disconnect_from_network()
		// {
		// 	start_node->disconnect_pipe(id);
		// 	end_node->disconnect_pipe(id);
		// }

		// void calculate_velocity()
		// {
		// 	if(diameter > 0.0){
		// 		// A = pi.d^2 / 4
		// 		// v = Q / A
		// 		velocity = (4 * flowrate) / (std::numbers::pi * std::pow(diameter, 2));
		// 	}
		// 	else{
		// 		throw std::runtime_error("invalid diameter of pipe!");
		// 	}
		// }

		// /**
		//  * Reynods Number
		//  * a dimensionless quantity that helps predict fluid flow patterns in different situations 
		//  * by measuring the ratio between inertial and viscous forces. 
		//  * 
		//  * @param kinematic_viscosity μ, the fluid kinematic viscosity
		//  * @param density ρ, the fluid density
		//  * 
		//  * Re = (ρ * v * d) / μ
		//  * 
		//  * Re > 4000 : Turbulent
		//  * Re < 4000 : Laminar flow
		//  */
		// void calculate_reynoldsnumber(double& kinematic_viscosity, double& density)
		// {
		// 	if(kinematic_viscosity > 0.0){
		// 		reynoldsnumber = (density * velocity * diameter) / kinematic_viscosity;
		// 	}
		// 	else{
		// 		throw std::runtime_error("invalid kinemativ viscosity!");
		// 	}
		// }

		// /**
		//  * Head Loss
		//  * Darcy-Weishach Formula (Laminar)
		//  * hl = (l / d) * (v^2 / (2g))
		//  */
		// void calculate_headloss()
		// {
		// 	if(reynoldsnumber > 0){
		// 		double frictionfactor = calculate_frictionfactor();
		// 		headloss = (frictionfactor * length * std::pow(velocity, 2)) / (2 * diameter * gravity);
		// 	}
		// 	else{
		// 		throw std::runtime_error("calculate reynolds number first!");
		// 	}
		// }

		// /**
		//  * friction factor
		//  * Colebrook-White equation
		//  */
		// double calculate_frictionfactor()
		// {
		// 	if(reynoldsnumber < 4000){
		// 		return 64.0 / reynoldsnumber;	/* laminar */
		// 	}
		// 	else{ 								/* turbulent */
		// 		double initial_guess = 0.02;
		// 		double tolerance = 1e-6;
		// 		double frictionfactor = initial_guess;
		// 		for(uint32_t i{0}; i < 1000; ++i){
		// 			double previous = frictionfactor;
		// 			frictionfactor = 1.0 / std::pow(-2.0 * std::log10((roughness / (3.7 * diameter)) + (2.51 / (reynoldsnumber * std::sqrt(previous)))), 2);

		// 			if(std::fabs(frictionfactor - previous) < tolerance)
		// 				break;
		// 		}

		// 		return frictionfactor;
		// 	}
		// }

		// void check_flowdirection()
		// {
		// 	// pressure relativity check
		// 	is_flowreversed = start_node->pressure < end_node->pressure;
		// 	if(is_flowreversed){
		// 		std::swap(start_node, end_node);
		// 	}
		// }

		// // apply pressure change (e.g. due to pump or valve)
		// void pressurechange(double& delta_pressure)
		// {
		// 	pressure += delta_pressure;
		// }

		// /**
		//  * update water quality parameters based on chemical reactions 
		//  * @param BOD Biochemical Oxygen Demand
		//  * @param TSS Total Suspended Solids
		//  * @param ... other water quality parameters to be defined here
		//  */
		// void update_waterquality(double& timestep)
		// {
		// 	double decay_rate = BOD_DECAY_RATE; 	/* decay rate per day */
		// 	BOD *= std::exp(-decay_rate * timestep);
		// }

		// void assess_condition()
		// {
		// 	// deducting points
		// 	if (is_corroded){
		// 		healthindex -= 5.0;
		// 	}
		// 	if (leakagerate > 0.0){
		// 		healthindex -= 5.0;
		// 	}
		// }

		// bool check_inspection_necessity()
		// {
		// 	if(age > PIPE_AGE_MAX || is_corroded || needs_repair()){
		// 		needs_inspection = true;
		// 	}
		// 	return needs_inspection;
		// }

		// bool needs_repair()
		// {
		// 	return (pressure > maximumpressure) || (is_corroded && corrosionrate > CORROSION_RATE_MAX);
		// }

		// double estimate_repaircost()
		// {
		// 	double material_factor = (material == "PVC") ? MATERIAL_COST_FACTOR_PVC : MATERIAL_COST_FACTOR_GENERIC;
		// 	repaircostestimate = material_factor * length * diameter * (is_corroded ? REPAIR_FACTOR_CORRODED : REPAIR_FACTOR_NON_CORRODED);
		// 	return repaircostestimate;
		// }

		// void inspect()
		// {
		// 	is_corroded = check_corrosion();
		// 	lastinspectiondate = get_current_julian_date();
		// }

		// bool check_corrosion()
		// {
		// 	return (age > PIPE_AGE_MAX && pH < MIN_ALLOWABLE_PH);
		// }
		
		// double get_current_julian_date(){
		// 	return 2459580.5;	/* magic number - to be worked on */
		// }

		// void log_pipeinfo() const
		// {
		// 	;;;;
		// }
	};

} // namespace hydro


#endif	// PIPE_H