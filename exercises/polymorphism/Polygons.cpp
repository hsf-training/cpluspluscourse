#include "Polygons.hpp"
#include <iostream>
#include <cmath>

RegularPolygon::RegularPolygon(int n, float radius) : m_nbSides(n), m_radius(radius) {};

float RegularPolygon::computePerimeter() const {
    std::cout << "Polygon::computePerimeter is being called\n";
    return 2 * m_nbSides * std::sin(static_cast<float>(M_PI) / m_nbSides) * m_radius;
}

Pentagon::Pentagon(float radius) : RegularPolygon(5, radius) {}

Hexagon::Hexagon(float radius) : RegularPolygon(6, radius) {}

float Hexagon::computePerimeter() const {
    std::cout << "Hexagon::computePerimeter is being called\n";
    return 6 * m_radius;
}
