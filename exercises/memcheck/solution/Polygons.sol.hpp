#pragma once

class Polygon {
public:
    Polygon(int n, float radius);
    virtual ~Polygon(){};
    float computePerimeter();
protected:
    int m_nbSides;
    float m_radius;
};

class Hexagon : public Polygon {
public:
    Hexagon(char* name, float radius);
    Hexagon(const Hexagon&) = delete;
    Hexagon& operator=(const Hexagon&) = delete;
    ~Hexagon();
    char* name() const {return m_name;};
private:
    char* m_name;
};
