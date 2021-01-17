#include <algorithm>
#include <cstdlib>
#include <ctime>
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
 * 1: Fix the leak using a smart pointer.
 *
 * Note that the arguments of sumEntries() don't need to change, as it has only read access.
 * --------------------------------------------------------------------------------------------
 */

// Declare a function to do something with the data. No need to change it.
double sumEntries(const double* data, std::size_t size) {
    return std::accumulate(data, data + size, 0);
}

// Often, data are owned by one entity, and only used by others. Fix the leak.
void problem1() {
    constexpr std::size_t arraySize = 10000;
    auto data = new double[arraySize];

    // Fill array with random stuff.
    for (std::size_t i = 0; i < arraySize; ++i) {
        data[i] = static_cast<double>(rand()) / RAND_MAX;
    }

    sumEntries(data, arraySize);
}



/* --------------------------------------------------------------------------------------------
 * 2: Storing unique_ptr in collections.
 *
 * Often, one has to store pointers to objects in collections. Fix the memory leaks using unique_ptr.
 * Notes:
 * - Factory functions should return objects either directly or using smart pointers, so users are forced to
 *   sort out object ownership properly. Fix the return type of the factory function.
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
    return new LargeObject();
}

// A function to do something with the objects.
void visitLargeObject(LargeObject* object) {
    object->fData[0] = 1.;
}

void problem2() {
    std::vector<LargeObject*> largeObjects;

    for (unsigned int i=0; i < 10; ++i) {
        auto newObj = createLargeObject();
        largeObjects.push_back(newObj);
    }

    for (auto obj : largeObjects) {
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
 * CONT=true; while $CONT; do valgrind --leak-check=full --track-origins=yes ./smartPointers 2>&1 | grep -B 5 -A 5 problem3 && CONT=false; done
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
 * 4: Smart pointers to solve ownership problems in class members.
 * *** This one is difficult. ***
 *
 * Class members that are pointers can become a problem.
 * Firstly, if only raw pointers are used, the intended ownerships are unclear.
 * Secondly, it's easy to overlook that a member has to be deleted. Here, we have an example where
 * the leak may not be obvious.
 *
 * Tasks:
 * - Why do we have a memory leak?
 *   Hint: Use valgrind to track down what exactly leaks here, and where it was allocated.
 *   Hint 2: The author made a mistake when inheriting from Base.
 * - Clarify the ownership using unique_ptr.
 * - Fix the mistake that was made when using inheritance.
 * --------------------------------------------------------------------------------------------
 */

// This class doesn't have a leak.
class Base {
public:
    Base(std::size_t size) :
        fData(new double[size]) { }

    ~Base() {
        delete[] fData;
    }

private:
    double* fData; // Do we own this or not? You have to check the destructor.
};


// At first sight, this also doesn't leak.
class Derived : public Base {
public:
    Derived(std::size_t size) :
        Base(size),
        _moreData(new LargeObject()) { }

    ~Derived() {
        delete _moreData;
    }

private:
    LargeObject* _moreData;
};


// Let's trigger a leak.
void problem4() {
    Base baseObject(10000);
    Derived derivedObject(10000);
    Base* whyDoesThisLeak = new Derived(10000);

    delete whyDoesThisLeak;
}





int main() {
    problem1();
    problem2();
    problem3();
    problem4();
}
