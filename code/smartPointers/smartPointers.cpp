#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <stdexcept>
#include <iostream>
#include <numeric>
#include <vector>


/*
 * Please fix all memory leaks / ownership problems using smart pointers.
 * (Verify by running the program with valgrind!)
 *
 * Remember that:
 * - The ownership of data is expressed using unique_ptr.
 * - "Observer" access without ownership is expressed using raw pointers.
 * - Shared access to data is expressed using shared_ptr.
 */


/* --------------------------------------------------------------------------------------------
 * 1: Always use smart pointers when you use new.
 *
 * A frequent source of leaks is a function that terminates earlier than the programmer thought.
 *
 * - Fix the leak using a smart pointer.
 * - The arguments of sumEntries() don't need to change, as it has only read access.
 * --------------------------------------------------------------------------------------------
 */

// Declare a function to do something with the data. No need to change it.
double sumEntries(const double* data, std::size_t size) {
    if (size > 200)
        throw std::invalid_argument("I only want to sum 200 numbers or less.");

    return std::accumulate(data, data + size, 0);
}

// Often, data are owned by one entity, and only used by others. Fix the leak.
void doStuffWithData() {
    constexpr std::size_t arraySize = 10000;
    auto data = new double[arraySize];

    sumEntries(data, arraySize);

    delete[] data;
}


void problem1() {
   try {
       doStuffWithData();
   } catch (std::exception& e) {
       std::cerr << "problem1(): Do stuff with data terminated with exception:\n" << e.what()
               << "\n We may have a memory leak now." << std::endl;
   }
}



/* --------------------------------------------------------------------------------------------
 * 2: Storing unique_ptr in collections.
 *
 * Often, one has to store pointers to objects in collections. Fix the memory leaks using unique_ptr.
 *
 * Notes:
 * - Factory functions should return objects either directly or using smart pointers.
 *   This is good practice, because it clearly shows who owns an object. Fix the return type of the factory function.
 * - The vector should own the objects, so try to store them using smart pointers.
 * - Since the visitor function doesn't accept smart pointers, find a solution to pass the objects.
 *   Note that this works without shared_ptr!
 * --------------------------------------------------------------------------------------------
 */

// This is a large object. We maybe shouldn't copy it, so using a pointer is advisable to pass it around.
struct LargeObject {
    double fData[100000];
};

// A factory function to create large objects.
LargeObject* createLargeObject() {
    auto object = new LargeObject();
    // Do more setting up of object here
    // ...

    return object;
}

// A function to do something with the objects.
// Note that since we don't own the object, we don't need a smart pointer as argument.
void visitLargeObject(LargeObject* object) {
    object->fData[0] = 1.;
}

void problem2() {
    std::vector<LargeObject*> largeObjects;

    for (unsigned int i=0; i < 10; ++i) {
        auto newObj = createLargeObject();
        largeObjects.push_back(newObj);
    }

    for (const auto& obj : largeObjects) {
        visitLargeObject(obj);
    }
}



/* --------------------------------------------------------------------------------------------
 * 3: Shared ownership.
 *
 * Most of the time, ownership can be solved by having one owner (with unique_ptr) and one or
 * more observers. Sometimes, we need to truly share data, though.
 *
 * Here is an example of a completely messed up ownership model. It leaks about 1/10 of the times
 * it is invoked.
 * - Verify this by running it in a loop using a command like:
 * while true; do valgrind --leak-check=full --track-origins=yes ./smartPointers 2>&1 | grep -B 5 -A 5 problem3 && exit 1; done
 * - Fix the ownership model using shared_ptr!
 *   - Convert the vectors to holding shared_ptr.
 *   - Fix the arguments of the functions.
 *   - Speed optimisation:
 *     Make sure that you don't create & destroy a shared_ptr in the for loop in problem3() and when calling processElement().
 * --------------------------------------------------------------------------------------------
 */

// This removes the element in the middle of the vector.
void removeMiddle(std::vector<LargeObject*>& collection) {
    auto middlePosition = collection.begin() + collection.size()/2;

    // Must not delete element when erasing from collection, because it's also in the copy ...
    collection.erase(middlePosition, middlePosition+1);
}

// This removes a random element.
// Note that this leaks if the element happens to be the same
// that's removed above ...
void removeRandom(std::vector<LargeObject*>& collection) {
    auto pos = collection.begin() + time(nullptr) % collection.size();

    collection.erase(pos, pos+1);
}

// Do something with an element.
// Just a dummy function, for you to figure out how to pass an object
// managed by a shared_ptr to a function.
void processElement(const LargeObject* /*element*/) { }


// We have pointers to objects in two different collections. We work a bit with
// the collections, and then we try to terminate leak free. Without a shared ownership
// model, this becomes a mess.
void problem3() {
    // Let's generate a vector with 10 pointers to LargeObject
    std::vector<LargeObject*> objVector(10);
    for (auto& ptr : objVector) {
        ptr = new LargeObject();
    }

    // Let's copy it
    std::vector<LargeObject*> objVectorCopy(objVector);


    // Now we work with the objects:
    removeMiddle(objVector);
    removeRandom(objVectorCopy);
    // ...
    // ...
    for (auto elm : objVector) {
        processElement(elm);
    }


    // Now try to figure out what has to be deleted. It's a mess ...
    // Fix using shared_ptr, so the following code becomes unnecessary:
    for (auto objPtr : objVector) {
        delete objPtr;
    }

    for (auto objPtr : objVectorCopy) {
        // If the element is in the original collection, it was already deleted.
        if (std::find(objVector.begin(), objVector.end(), objPtr) == objVector.end()) {
            delete objPtr;
        }
    }
}



/* --------------------------------------------------------------------------------------------
 * 4: Smart pointers as class members.
 *
 * Class members that are pointers can quickly become a problem.
 * Firstly, if only raw pointers are used, the intended ownerships are unclear.
 * Secondly, it's easy to overlook that a member has to be deleted.
 * Thirdly, pointer members usually require to implement copy or move constructors or assignment
 * operators.
 * Since C++-11, one can solve those problems using smart pointers.
 *
 * 4.1:
 * The class "Owner" owns some data, but it is broken. If you copy it like in
 * problem4_1(), you have two pointers pointing to the same data, but both think
 * that they own the data.
 * - Comment in problem4_1() in main().
 * - Verify that it crashes. Try running valgrind ./smartPointers, it should give you some hints as to
 *   what's happening.
 * - Fix the Owner class by using a shared_ptr for its _largeObj, which we can copy as much as we want.
 * - Note: Now you even don't need a destructor.
 *
 * 4.2: **BONUS**
 * We go beyond the scope of the lecture now, and use a weak pointer.
 * These are used to observe a shared_ptr, but unlike the shared_ptr, they don't prevent the deletion
 * of the underlying object if all shared_ptr go out of scope.
 * To *use* the observed data, one has to create a shared_ptr from the weak_ptr, so that it is guaranteed that
 * the underlying object is alive.
 *
 * In our case, the observer class wants to observe the data of the owner, but it doesn't need to own it.
 * To do this, we use a weak pointer.
 *
 * Tasks:
 * - Comment in the line in problem4_2() that crashes the program.
 * - Rewrite the interface of Owner::getData() such that the observer can see the shared_ptr to the large object.
 * - Set up the Observer such that it stores a weak pointer that observes the large object.
 * - In Observer::processData(), access the weak pointer, and use the data *only* if the memory is still alive.
 *   Note: What you need is weak_ptr::lock(). Check out the documentation and the example at the bottom:
 *   https://en.cppreference.com/w/cpp/memory/weak_ptr/lock
 * --------------------------------------------------------------------------------------------
 */

class Owner {
public:
    Owner() :
        _largeObj(new LargeObject()) { }

    ~Owner() {
        std::cout << "problem4(): I think I'm the owner. I'm deallocating " << _largeObj << " now." << std::endl;
        delete _largeObj;
    }

    const LargeObject* getData() const {
        return _largeObj;
    }

private:
    LargeObject* _largeObj;
};


void problem4_1() {
    std::vector<Owner> owners;

    for (unsigned int i=0; i < 5; ++i) {
        Owner owner;
        owners.push_back(owner);
    }

    /* Starting from here, we have a problem:
     * We created all these data owners, but the ones in the vector are copies of the owner objects in the loop.
     * When those originals are destroyed, the memory is deallocated. The copies now
     * point to the deallocated memory!
     * We can fix this using copy constructors (but we don't want to copy the data),
     * using move semantics or using shared_ptr.
     */
}


class Observer {
public:
    Observer(const Owner& owner) :
        _largeObj(owner.getData()) { }

    double processData() const {
        if (_largeObj) {
            return _largeObj->fData[0];
        }

        return -1.;
    }

private:
    const LargeObject* _largeObj; // We don't own this.
};



void problem4_2() {
    // We directly construct 5 owners inside the vector to get around problem4_1:
    std::vector<Owner> owners(5);
    std::vector<Observer> observers;

    observers.reserve(owners.size());
    for (const auto& owner : owners) {
        observers.emplace_back(owner);
    }

    // Now let's destroy the owners:
    owners.clear();

    for (const auto& observer : observers) {
        // Problem: We don't know if the data is alive ...
        // TODO: Fix Observer!
        // observer.processData();
    }
}


int main() {
    problem1();
    problem2();
    problem3();
//    problem4_1();
    problem4_2();
}
