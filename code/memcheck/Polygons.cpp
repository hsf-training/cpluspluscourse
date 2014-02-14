#include "Polygons.hpp"
#include <iostream>
#include <cmath>
#include <string.h>
#include <stdlib.h>

#define PI 3.14159265

Polygon::Polygon(int n, float radius) : m_nbSides(n), m_radius(radius) {};

float Polygon::computePerimeter() {
    std::cout << "Generic computePerimeter for polygons" << std::endl;
    return 2*m_nbSides*sin(PI/m_nbSides)*m_radius;
}

Hexagon::Hexagon(char* name, float radius) : Polygon(6, radius) {
    m_name = strdup(name);
}

Hexagon::~Hexagon() {
    free(m_name);
    m_name = 0;
}
