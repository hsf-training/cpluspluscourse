

#include <iostream>
#include <array>
#include <vector>
#include <memory>


/* --------------------------------------------------------------------------------------------
 * Weak pointers.
 *
 * Let's construct some `std::weak_ptr` so to observe some `std::shared_ptr`.
 * This weak pointers can be used to retreive the object pointed by the corresponding `std::shared_ptr`,
 * but it does not increase the reference count of the objects, and does not prevent
 * the deletion of the underlying objects if all shared pointers go out of scope.
 * To *use* the observed data, one has to create a `std::shared_ptr` from the `std::weak_ptr`,
 * so that it is guaranteed that the underlying object is alive.
 *
 * In our case, the `Observer` class wants to act on the data of the `Owner`,
 * but it doesn't need to own it. To do this, we use a weak pointer.
 *
 * Tasks
 * 1) Investigate the crash. Optionally use a debugger, run in valgrind,
 *    compile with -fsanitize=address ...
 * 2) Rewrite the interface of Owner::getData() such that the observer can see the
 *    `std::shared_ptr` pointing to the large object.
 *    Review the class `Observer` such that it stores a `std::weak pointer`.
 *    In `setValue`and `getValue`, access the weak pointer, and use the data *only* if the memory is still alive.
 *    Note: What you need is weak_ptr::lock(). Check out the documentation and the example at the bottom:
 *    https://en.cppreference.com/w/cpp/memory/weak_ptr/lock
 *
 * --------------------------------------------------------------------------------------------
 */

struct LargeObject {

    std::array<double, 100000> data ;

} ;

class Owner {

  // SOME CHANGES NEEDED IN THIS CLASS

  public:

    Owner() : _largeObject( new LargeObject() ) {}
    LargeObject * getLargeObject() const { return _largeObject.get() ; }

  private:

    std::shared_ptr<LargeObject> _largeObject ;

} ;

class Observer {

  // SOME CHANGES NEEDED IN THIS CLASS

  public:

    Observer( const Owner & owner ) : _largeObject(owner.getLargeObject()) {}

    void setValue( double v ) {
        if (_largeObject) { _largeObject->data[0] = v ; }
        else { _largeObject->data[0] = 0. ; }
    }

    double getValue() const {
        if (_largeObject) { return _largeObject->data[0] ; }
        else { return -1. ; }
    }

  private:

    LargeObject * _largeObject ;

} ;

void doStuff() {

    // Owners and observers

    std::vector<Owner> owners(5) ;
    std::vector<Observer> observers ;
    for ( auto & owner : owners ) {
        observers.emplace_back(owner) ;
    }

    // Write through observers

    for ( auto & observer : observers ) {
        observer.setValue(1.) ;
    }

    // Let's destroy the 2 last owners

    owners.resize(3) ;

    // Read through observers

    std::cout << "Values:";
    for ( auto const & observer : observers ) {
        std::cout<<" "<<observer.getValue()<<std::flush ;
    }
    std::cout<<std::endl ;
}

int main() {

    doStuff() ;

}
