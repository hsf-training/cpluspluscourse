

#include <iostream>
#include <array>
#include <vector>


/* --------------------------------------------------------------------------------------------
 * Smart pointers as class members.
 *
 * Class members that are pointers can quickly become a problem.
 * Firstly, if only raw pointers are used, the intended ownership is unclear.
 * Secondly, it's easy to overlook that a member has to be deleted.
 * Thirdly, pointer members usually require you to implement copy or move constructors
 * and assignment operators (--> rule of 3, rule of 5).
 * Since C++-11, one can solve a few of those problems using smart pointers.
 *
 * The class "Owner" owns some data, but it is broken. If you copy it like in
 * doStuff(), you have two pointers pointing to the same data, but both instances
 * think that they own the data.
 *
 * Tasks
 * 1) It likely crashes. Verify this. You can also try running `valgrind ./problem4`,
 *    it should give you some hints as to what's happening.
 * 2) Fix the Owner class by using a `std::shared_ptr` for its data, which we can
 *    copy as much as we want. Run the fixed program.
 *    Note: Once `std::shared_ptr` is in use, you can also use the default destructor.
 *
 * --------------------------------------------------------------------------------------------
 */

struct LargeObject {

    std::array<double, 100000> data ;

} ;

class Owner {

  // MAKE YOUR CHANGES IN THIS CLASS

  public:

    Owner() : _largeObject( new LargeObject() ) {}
    LargeObject * getLargeObject() { return _largeObject ; }
    ~Owner() { delete _largeObject ; }

  private:

    LargeObject * _largeObject ;

} ;

void doStuff() {

    std::vector<Owner> owners ;

    for ( int i = 0 ; i < 5 ; ++i ) {
        Owner owner ;
        // ... additional owner setup ...
        owners.push_back(owner) ;
    }

    /* Now we have a problem:
     * We created Owner instances on the stack, and copied them into the vector.
     * When the instances on the stack are destroyed, the memory is deallocated.
     * All copies in the vector now point to the deallocated memory!
     * We could fix this using copy constructors (but we don't want to copy the data),
     * using move semantics or using shared_ptr.
     * Here, we want to go for shared_ptr.
     */

}

int main() {

    doStuff() ;

}
