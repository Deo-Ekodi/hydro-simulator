#ifndef NODE_H
#define NODE_H

#include <cstdint>

class Node
{
public:
    Node() = default;
    
    // core attributes
    uint32_t id;
    double x, y, z;

    void set_id (const uint32_t& _id) {id = _id;}
};

#endif