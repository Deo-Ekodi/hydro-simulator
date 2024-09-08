#ifndef PIPE_H
#define PIPE_H

#include "node.hpp"

#include <cstdint>

class Pipe
{
public:
    Pipe()
    {
        id = 0;
        length = 10.5;
        diameter = 10.0;
    }
    // core attributes
    uint32_t id;					/* unique identifier */
    double length;					/* length of pipe */
    double diameter;				/* diameter if pipe*/
    // Node start_node;				/* start node */
    // Node end_node;					/* end node */

    void set_id(const uint32_t& _id) {id = _id;}
    void set_length(const double& _l) {length = _l;}
    void set_diameter (const double& _d) {diameter = _d;}
    // void set_start_node(const Node& node) {start_node = node;}
    // void set_end_node (const Node& node) {end_node = node;}

};

#endif	// PIPE_H