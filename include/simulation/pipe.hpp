#pragma once

/**
 * PIPE
 */

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

using namespace util;

namespace core
{

	constexpr double gravity = 9.81;
	class Pipe
	{
	public:
		Pipe(uint32_t _id, double _length, double _diameter, double _roughness, double _slope)
			: id(_id), length(_length),diameter(_diameter), roughness(_roughness), slope(_slope)
			{
				initialize_default_values();
			}
		~Pipe();

		/**
		 * core attributes
		 */
		uint32_t id;					/* unique identifier */
		double length;					/* length of pipe */
		double roughness;				/* rouhness coefficient */
		double slope;					/* gradient */
		double diameter;				/* diameter if pipe*/

		/**
		 * flow attributes
		 */
		double flowrate;
		double velocity;
		double pressure;
		double headloss;
		double reynoldsnumber;

		/**
		 * quality attributes
		 */
		std::vector<double> pollutantconcentration;			/* mg/L */
		double temperature;
		double pH;
		double dissolvedoxygen;
		double BOD;
		double COD;

		/**
		 * structural attributes
		 */
		double wallthickness;
		double maximumpressure;
		double corrosionrate;
		double age;
		std::string material;
		bool is_corroded;

		/**
		 * Maintenance Attributes
		 */
		bool needs_inspection;          /* Flag for inspection necessity */
		double lastinspectiondate;     /* Date of last inspection (Julian date) */
		double repaircostestimate;     /* Estimated cost for repair ($) */
		bool is_underrepair;            /* Repair status (true/false) */

		/**
		 * initialize to default values
		 */
		void initialize_default_values()
		{
			flowrate = 0.0;
			velocity = 0.0;
			pressure = 0.0;
			headloss = 0.0;
			reynoldsnumber = 0.0;
			temperature = 0.0;
			pH = 7.0;
			dissolvedoxygen = 8.0;		/* typical D.O (mg/l) */
			BOD = 0.0;
			COD = 0.0;
			wallthickness = 0.0;
			maximumpressure = 0.0;
			is_corroded = false;
			corrosionrate = 0.0;
			age = 0.0;
			needs_inspection = false;
			lastinspectiondate = 0.0;
			repaircostestimate = 0.0;
			is_underrepair = false;
		}

		void calculate_velocity()
		{
			if(diameter > 0.0){
				// A = pi.d^2 / 4
				// v = Q / A
				velocity = (4 * flowrate) / (std::numbers::pi * std::pow(diameter, 2));
			}
			else
			{
				throw std::runtime_error("invalid diameter of pipe!");
			}
		}

		/**
		 * Reynods Number
		 * a dimensionless quantity that helps predict fluid flow patterns in different situations 
		 * by measuring the ratio between inertial and viscous forces. 
		 * 
		 * @param kinematic_viscosity μ, the fluid kinematic viscosity
		 * @param density ρ, the fluid density
		 * 
		 * Re = (ρ * v * d) / μ
		 * 
		 * Re > 4000 : Turbulent
		 * Re < 4000 : Laminar flow
		 */
		void calculate_reynoldsnumber(double& kinematic_viscosity, double& density)
		{
			if(kinematic_viscosity > 0.0){
				reynoldsnumber = (density * velocity * diameter) / kinematic_viscosity;
			}
			else{
				throw std::runtime_error("invalid kinemativ viscosity!");
			}
		}

		/**
		 * Head Loss
		 * Darcy-Weishach Formula (Laminar)
		 * hl = (l / d) * (v^2 / (2g))
		 */
		void calculate_headloss()
		{
			if(reynoldsnumber > 0){
				double frictionfactor = calculate_frictionfactor();
				headloss = (frictionfactor * length * std::pow(velocity, 2)) / (2 * diameter * gravity);
			}
			else{
				throw std::runtime_error("calculate reynolds number first!");
			}
		}

		/**
		 * friction factor
		 * Colebrook-White equation
		 * 
		 */
		double calculate_frictionfactor()
		{
			if(reynoldsnumber < 4000){
				return 64.0 / reynoldsnumber;	/* laminar */
			}
			else{ 								/* turbulent */
				double initial_guess = 0.02;
				double tolerance = 1e-6;
				double frictionfactor = initial_guess;
				for(uint32_t i{0}; i < 1000; ++i){
					double previous = frictionfactor;
					frictionfactor = 1.0 / std::pow(-2.0 * std::log10((roughness / (3.7 * diameter)) + (2.51 / (reynoldsnumber * std::sqrt(previous)))), 2);

					if(std::fabs(frictionfactor - previous) < tolerance)
						break;
				}

				return frictionfactor;
			}
		}
	};

} // namespace core