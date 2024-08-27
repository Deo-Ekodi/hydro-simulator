#ifndef NODE_H
#define NODE_H

#include <initializer_list>
#include <cstdint>
#include <exception>

namespace util
{
	/**
	 * Node(initializer_list<x, y, z>, id)
	 * @param x cartesian coordinate : must parse
	 * @param y cartesian coordinate : must parse
	 * @param z cartesian coordinate : may not be parsed
	 * @param id must parse
	 */
	class Node
	{
	private:
		double x;
		double y;
		double z;
        double pressure;        /* pressure at node */
		uint32_t id;
	public:
		Node(const double& X, const double& Y, const double& Z = -1.0, uint32_t _id)
			: x(X), y(Y), z(Z),id(_id) {}

        double get_x() noexcept {return x;}
        double get_y() noexcept {return y;}
        double get_z() noexcept {return z;}
        uint32_t get_id() noexcept {return id;}
	};
} // namespace util


#endif