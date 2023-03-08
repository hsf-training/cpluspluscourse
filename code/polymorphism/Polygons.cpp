#include "Polygons.hpp"
#include <iostream>
#include <cmath>

Polygon::Polygon(int n, float radius) : m_nbSides(n), m_radius(radius) {};

float Polygon::computePerimeter() const {
    std::cout << "Polygon::computePerimeter is being called\n";
    return 2*m_nbSides*std::sin(static_cast<float>(M_PI)/m_nbSides)*m_radius;
}

Pentagon::Pentagon(float radius) : Polygon(5, radius) {}

Hexagon::Hexagon(float radius) : Polygon(6, radius) {}

float Hexagon::computePerimeter() const {
    std::cout << "Hexagon::computePerimeter is being called\n";
    return 6 * m_radius;
}
