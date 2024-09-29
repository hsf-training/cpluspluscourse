

#include <iostream>
#include <array>


/* --------------------------------------------------------------------------------------------
 * Unique ownership.
 *
 * Always use smart pointers instead of `new`. A frequent source of memory leaks is a function
 * that terminates in an unexpected way.
 *
 * Tasks
 * 1) Compile and run the code below. Notice that the final count is `1`,
 *    showing that the instance of LargeObject has not been deallocated.
 * 2) Modify `doStuff()` (only) so to use a `std::unique_ptr` instead of a raw pointer.
 *    The final count should be `0`, and the memory leak solved.
 * --------------------------------------------------------------------------------------------
 */


// The class LargeObject emulates a large object.
// One should avoid to copy it, and rather use
// a pointer to pass it around.

struct LargeObject {

    std::array<double, 100000> data ;

    // So to check for some potential memory leak,
    // we count the constructions and destructions
    inline static std::size_t count = 0;
    LargeObject() { count++ ; }
    ~LargeObject() { count-- ; }

} ;


// A function to do something with a large object.
// Here we simulate that an error happens.

void changeLargeObject( LargeObject & object ) {

    object.data[0] = 1. ;
    throw std::invalid_argument("Error when changing object data.") ;

}

// Often, data are owned by one entity, and merely used by others.
// In this case, we hand the data to changeLargeObject(),
// and unfortunately, something goes wrong...

void doStuff() {

    // MAKE YOUR CHANGES IN THIS FUNCTION

    auto obj = new LargeObject ;
    changeLargeObject(*obj) ;
    delete obj ;

}

int main() {

    try {
        doStuff() ;
    } catch ( const std::exception & e ) {
        std::cerr<< "Terminated with exception: " << e.what() << "\n" ;
    }

    std::cout<<"Forgotten large objects: "<<LargeObject::count<<std::endl ;

}
