
#include <iostream>
#include <array>
#include <vector>
#include <memory>


struct LargeObject {

    std::array<double, 100000> data ;

    // So to check for some potential memory leak,
    // we count the constructions and destructions
    inline static std::size_t count = 0 ;
    LargeObject() { count++ ; }
    ~LargeObject() { count-- ; }

} ;

std::unique_ptr<LargeObject> newLargeObject() {

    auto object = std::make_unique<LargeObject>() ;
    // Imagine there is more setup steps of "object" here
    // ...
    return object ;
}

void changeLargeObject( LargeObject & object ) {

    object.data[0] = 1. ;

}

void doStuff() {

    std::vector<std::unique_ptr<LargeObject>> largeObjects ;

    for ( unsigned int i = 0 ; i < 10 ; ++i ) {
        largeObjects.push_back(newLargeObject());
        // ... additional largeObjects.back() setup ...

        // Alternatively, when the object is ready,
        // one can "give up" newObj
        // by moving it into the vector.
        // auto newObj = createLargeObject() ;
        // ... additional newObj setup ...
        // largeObjects.push_back(std::move(newObj));

    }

    for (const auto& obj : largeObjects) {
        changeLargeObject(*obj);
    }
}

int main() {
   doStuff() ;
   std::cout<<"Leaked large objects: "<<LargeObject::count<<std::endl ;
}
