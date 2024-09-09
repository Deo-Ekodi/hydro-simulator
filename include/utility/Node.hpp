#ifndef NODE_H
#define NODE_H

#include <cstdint>
#include <exception>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>

#include "../util.hpp"
namespace hydro
{
	/**
	 * NODE represent points where pipes meet, change direction, 
	 * or connect to other infrastructure like tanks or reservoirs. 
	 * They can also represent points where water demand or supply occurs.
	 * 
	 * Node(x, y, z, id)
	 * @param x cartesian coordinate : must parse
	 * @param y cartesian coordinate : must parse
	 * @param z cartesian coordinate : may not be parsed
	 * @param id must parse
	 */

	class Node
	{
	public:
		Node () = default;
		Node(uint32_t& _id)	
			: id(_id)
		{}
			// initialize_default_values();
		// }
		// Node(double _x = 0.0, double _y = 0.0, double _z = 0.0, uint32_t _id)
		// 	: x(_x), y(_y), z(_z), id(_id)
		// {
		// 	initialize_default_values();
		// }

		// // core attributes
		uint32_t id;
		// double x, y, z;
		// std::string description;

		// // hydraulic properties
		// double pressure;
		// double flow;
		// double head;
		// double demand;
		// bool is_reservoirconnected;
		// bool is_tankconnected;
		// bool is_pipeconnected;

		// // water quality
		// double pollutantconcentration;
		// double temperature;
		// double pH;
		// double dissolvedoxygen;
		// double BOD;				/* Biological Oxygen demand */
		// double COD;				/* chemical oxygen demand */

		// // connectivity
		// std::vector<uint32_t&> connected_pipes;		/* ids of connectd pipes */
		// std::vector<uint32_t&> adjacent_nodes;		/* ids of adjacent nodes */
		// bool is_inlet;
		// bool is_outlet;

		// // simulation management
		// bool is_visited;			/* visited flag for traverasal */
		// std::string status;			/* operation status : active, inactive ... */
		// double leakage;				/* leakage rate */
		// double lastinispectiondate;	/* julian date of last inspection */
		// double healthindex;			/* summary health index : arbitrary units */

		// // initialize to defaults
		// void initialize_default_values()
		// {
		// 	pressure = 0.0;
		// 	flow = 0.0;
		// 	head = 0.0;
		// 	demand = 0.0;
		// 	is_reservoirconnected = false;
		// 	is_tankconnected = false;
		// 	pollutantconcentration = 0.0;
		// 	temperature = ROOM_TEMPERATURE;				/* default room temp */
		// 	pH = PH_NEUTRAL;
		// 	dissolvedoxygen = 0.0;
		// 	BOD = DEFAULT;
		// 	COD = DEFAULT;
		// 	is_inlet = false;
		// 	is_outlet = false;
		// 	is_visited = false;
		// 	status = "active";
		// 	leakage = 0.0;
		// 	lastinispectiondate = DEFAULT;
		// 	healthindex = PERFECT;
		// }

		// void calculate_head()
		// {
		// 	head = z + (pressure / (GRAVITY * WATER_DENSITY));
		// }

		// void update_waterquality(double& timestep)
		// {
		// 	// to be advanced
		// 	pollutantconcentration *= std::exp(-BOD_DECAY_RATE * timestep);
		// }

		// void balance_flow()
		// {
		// 	// ensure inflow equals outflow for conservetion of mass law!
		// }

		// void connect_pipe(uint32_t& pipe_id)
		// {
		// 	connected_pipes.push_back(pipe_id);
		// }

		// void disconnect_pipe(uint32_t& pipe_id)
		// {
		// 	connected_pipes.erase(std::remove(connected_pipes.begin(), connected_pipes.end(), pipe_id), connected_pipes.end());
		// }

		// void check_leak()
		// {
		// 	if (leakage > ALL_OK){
		// 		// leakage effects
		// 	}
		// }

		// void inspect_node()
		// {
		// 	healthindex = calculate_health_index();
		// 	lastinispectiondate = get_current_julian_date();
		// }

		// // to be checked
		// double get_current_julian_date(){return 2459580.5;}
		// double calculate_health_index(){return 1.0;}

		// void log_nodeinfo()
		// {
		// 	;
		// }

	};
	
} // namespace hydro


#endif