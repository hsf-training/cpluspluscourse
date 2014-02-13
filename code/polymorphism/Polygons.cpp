#include "Polygons.hpp"
#include <iostream>
#include <cmath>

#define PI 3.14159265

Polygon::Polygon(int n, float radius) : m_nbSides(n), m_radius(radius) {};

float Polygon::computePerimeter() {
    std::cout << "Generic computePerimeter for polygons" << std::endl;
    return 2*m_nbSides*sin(PI/m_nbSides)*m_radius;
}

Pentagon::Pentagon(float radius) : Polygon(5, radius) {}

Hexagon::Hexagon(float radius) : Polygon(6, radius) {}

float Hexagon::computePerimeter() {
    std::cout << "Optimized computePerimeter for hexagons" << std::endl;
    return 6 * m_radius;
}
