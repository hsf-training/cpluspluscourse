#include "Polygons.hpp"
#include <iostream>

int main() {
    // create a Pentagon, call its perimeter method
    Pentagon penta{1.0};
    std::cout << "Penta : perimeter = " << penta.computePerimeter() << "\n\n";


    // create a Hexagon, call its perimeter method
    Hexagon hexta{1.0};
    std::cout << "Hexta : perimeter = " << hexta.computePerimeter() << "\n\n";


    // create a Hexagon, call the perimeter method through a reference to Polygon
    Hexagon hexta2{1.0};
    RegularPolygon &poly = hexta2;
    std::cout << "Hexa : perimeter = " << hexta2.computePerimeter() << '\n'
              << "Hexa as Poly : perimeter = " << poly.computePerimeter() << '\n';


    // retry virtual method

}
