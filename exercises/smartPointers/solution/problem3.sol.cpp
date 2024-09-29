
#include <iostream>
#include <array>
#include <vector>
#include <random>
#include <algorithm>
#include <memory>

struct LargeObject {

    std::array<double, 100000> data ;

    // So to check for some potential memory leak,
    // we count the constructions and destructions
    static std::size_t count ;
    LargeObject() { count++ ; }
    ~LargeObject() { count-- ; }

} ;

std::size_t LargeObject::count = 0 ;

void removeMiddle(std::vector<std::shared_ptr<LargeObject>>& collection) {

    auto middlePosition = collection.begin() + collection.size()/2;
    collection.erase(middlePosition);

}

void removeRandom(std::vector<std::shared_ptr<LargeObject>>& collection, std::default_random_engine & engine) {

    auto pos = collection.begin() + engine() % collection.size();
    collection.erase(pos);

}

void changeLargeObject( LargeObject & object ) {

    object.data[0] = 1. ;

}

void doStuff() {

    // Prepare a non deterministic random engine

    std::random_device device ;
    std::default_random_engine engine(device()) ;

    // Original collection

    std::vector<std::shared_ptr<LargeObject>> objVector(10);
    for ( auto & ptr : objVector ) {
        ptr = std::make_shared<LargeObject>();
    }

    // Less copies :
    // std::vector<std::shared_ptr<LargeObject>> objVector ;
    // objVector.reserve(10);
    // for ( unsigned int i = 0 ; i < 10 ; ++i ) {
    //     objVector.emplace_back(new LargeObject()) ;
    // }

    // Let's copy the whole collection

    auto objVectorCopy(objVector);

    // Random work with the objects

    removeMiddle(objVector);
    removeRandom(objVectorCopy,engine);
    removeRandom(objVectorCopy,engine);
    // ...
    // ...
    for ( auto const & objPtr : objVector ) {
        changeLargeObject(*objPtr) ;
    }

}

int main() {

   doStuff() ;
   std::cout<<"Forgotten large objects: "<<LargeObject::count<<std::endl ;

}
