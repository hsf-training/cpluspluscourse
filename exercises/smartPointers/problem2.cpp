

#include <iostream>
#include <array>
#include <vector>


/* --------------------------------------------------------------------------------------------
 * Collections of smart pointers.
 *
 * Often, one has to store pointers to objects in collections.
 * Fix the memory leaks below by using `std::unique_ptr`.
 *
 * Tasks
 * 1) Compile and run the code below. Notice that the final count is `10`,
 *    which is expected because the new objects are never deallocated.
 * 2) Factory functions should better return smart pointers,
 *    because it clarifies who owns an object.
 *    Change the return type of the function `newLargeObject()` for a `std::unique_ptr()`.
 *    The vector should own the objects, so try to store them using smart pointers.
 *    Since the change function doesn't accept smart pointers, find a solution to pass the objects.
 *    Try to use `std::unique_ptr`, not `std::shared_ptr` !
 * --------------------------------------------------------------------------------------------
 */


// The class LargeObject emulates a large object.
// One should avoid to copy it, and rather use
// a pointer to pass it around.

struct LargeObject {

    std::array<double, 100000> data ;

    // So to check for some potential memory leak,
    // we count the constructions and destructions
    static std::size_t count ;
    LargeObject() { count++ ; }
    ~LargeObject() { count-- ; }

} ;

std::size_t LargeObject::count = 0 ;

// A factory function to create large objects.

LargeObject * newLargeObject() {

    // MAKE YOUR CHANGES IN THIS FUNCTION

    auto object = new LargeObject() ;
    // Imagine there is more setup steps of "object" here
    // ...
    return object ;

}

// A function to do something with the objects.
// Note that since we don't own the object,
// we don't need a smart pointer as argument.

void changeLargeObject( LargeObject & object ) {

    object.data[0] = 1. ;

}

void doStuff() {

    // MAKE YOUR CHANGES IN THIS FUNCTION

    std::vector<LargeObject *> largeObjects ;

    for ( unsigned int i = 0 ; i < 10 ; ++i ) {
        auto newObj = newLargeObject() ;
        // ... additional newObj setup ...
        largeObjects.push_back(newObj) ;
    }

    for ( const auto & obj : largeObjects ) {
        changeLargeObject(*obj) ;
    }
}

int main() {

    doStuff() ;
    std::cout<<"Forgotten large objects: "<<LargeObject::count<<std::endl ;

}
