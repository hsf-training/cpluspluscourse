

#include <iostream>
#include <array>
#include <vector>
#include <random>
#include <algorithm>


/* --------------------------------------------------------------------------------------------
 * Shared ownership.
 *
 * Most of the time, ownership can be solved by having one owner (with `std::unique_ptr`) and
 * one or more observers (raw pointers or references). Sometimes, we need to truly share data,
 * though. Here is an example of a completely messed up ownership model, which could be fixed using shared_ptr.
 *
 * Tasks
 * 1) Verify the mess by repeatedly running it using such a command like:
 *   `while true; do ./problem3 2>&1 ; done`
 *    You should notice that the program regularly leaks.
 * 2) Fix the ownership model using `std::shared_ptr` !
 *   - Convert the vectors to holding `std::shared_ptr`.
 *   - Fix the arguments of the functions.
 * 3) Speed optimisation: make sure that you don't create & destroy useless `std::shared_ptr`,
 *    which is slow, for example in the for loop of `doStuff()` and when
 *    calling `changeLargeObject()`.
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

// This removes an element from a non-owning vector,
// in the middle or in a random place. Such elements
// can by known in several vectors, so they must not
// be deleted.

void removeMiddle( std::vector<LargeObject *> & collection ) {

    // MAKE YOUR CHANGES IN THIS FUNCTION

    auto middlePosition = collection.begin() + collection.size()/2 ;
    collection.erase(middlePosition) ;

}

void removeRandom( std::vector<LargeObject *> & collection, std::default_random_engine & engine ) {

    // MAKE YOUR CHANGES IN THIS FUNCTION

    auto pos = collection.begin() + engine() % collection.size() ;
    collection.erase(pos);

}

// A function to do something with a large object.
// Note that since we don't own the object,
// we don't need a smart pointer as argument.

void changeLargeObject( LargeObject & object ) {

    object.data[0] = 1. ;

}

// Global stuff: we have pointers to objects duplicated in two different collections.
// We work a bit with the collections, and then we try to clean up  without neither
// memory leak nor segmentation fault. Without a shared ownership model, this becomes a mess.

void doStuff() {

    // MAKE YOUR CHANGES IN THIS FUNCTION

    // Prepare a non deterministic random engine

    std::random_device device ;
    std::default_random_engine engine(device()) ;

    // Original collection

    std::vector<LargeObject*> objVector(10);
    for ( auto & ptr : objVector ) {
        ptr = new LargeObject();
    }

    // Let's copy the whole collection

    auto objVectorCopy(objVector);

    // Random work with the objects

    removeMiddle(objVector);
    removeRandom(objVectorCopy,engine);
    removeRandom(objVectorCopy,engine);
    // ...
    for (auto objPtr : objVector ) {
        changeLargeObject(*objPtr) ;
    }

    // ONCE YOU FIXED CODE ABOVE WITH SHARED POINTERS
    // THE UGLY CODE BELOW SHOULD BECOME UNNECESSARY

    for ( auto objPtr : objVector ) {
        delete objPtr ;
    }
    for ( auto objPtr : objVectorCopy ) {
        // If the element is in the original collection, it was already deleted.
        if (std::find(objVector.begin(), objVector.end(), objPtr) == objVector.end()) {
            delete objPtr;
        }
    }

}

int main() {

    doStuff() ;
    std::cout<<"Forgotten large objects: "<<LargeObject::count<<std::endl ;

}
