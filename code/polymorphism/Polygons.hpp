#pragma once

class Polygon {
public:
    Polygon(int n, float radius);
    float computePerimeter() const;
protected:
    int m_nbSides;
    float m_radius;
};

class Pentagon : public Polygon {
public:
    Pentagon(float radius);
};

class Hexagon : public Polygon {
public:
    Hexagon(float radius);
    // 6*radius is easier than generic case
    float computePerimeter() const;
};
