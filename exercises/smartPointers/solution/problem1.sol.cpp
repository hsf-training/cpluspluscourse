
#include <iostream>
#include <array>
#include <memory>

struct LargeObject {

    std::array<double, 100000> data ;

    // So to check for some potential memory leak,
    // we count the constructions and destructions
    inline static std::size_t count = 0 ;
    LargeObject() { count++ ; }
    ~LargeObject() { count-- ; }

} ;

void changeLargeObject( LargeObject & object ) {

    object.data[0] = 1. ;
    throw std::invalid_argument("Error when changing object data.") ;

}

void doStuff() {

    auto obj = std::make_unique<LargeObject>() ;
    changeLargeObject(*obj) ;

}

int main() {

    try {
        doStuff() ;
    } catch ( const std::exception & e ) {
        std::cerr<< "Terminated with exception: " << e.what() << "\n" ;
    }

    std::cout<<"Leaked large objects: "<<LargeObject::count<<std::endl ;

}
