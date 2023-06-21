#pragma once

class RegularPolygon {
public:
    RegularPolygon(int n, float radius);
    float computePerimeter() const;
protected:
    int m_nbSides;
    float m_radius;
};

class Pentagon : public RegularPolygon {
public:
    Pentagon(float radius);
};

class Hexagon : public RegularPolygon {
public:
    Hexagon(float radius);
    // 6*radius is easier than generic case
    float computePerimeter() const;
};
