

#include <iostream>
#include <array>
#include <vector>
#include <memory>


struct LargeObject {

    std::array<double, 100000> data ;

} ;

class Owner {

  public:

    Owner() : _largeObject( new LargeObject() ) {}
    LargeObject * getLargeObject() const { return _largeObject.get() ; }

  private:

    std::shared_ptr<LargeObject> _largeObject ;

} ;

void doStuff() {

    std::vector<Owner> owners ;

    for ( int i = 0 ; i < 5 ; ++i ) {
        Owner owner ;
        // ... additional owner setup ...
        owners.push_back(owner) ;
    }
}

int main() {

    doStuff() ;

}
