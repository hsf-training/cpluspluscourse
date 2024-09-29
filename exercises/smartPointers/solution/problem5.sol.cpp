
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
    auto getLargeObject() const { return _largeObject ; }

  private:

    std::shared_ptr<LargeObject> _largeObject ;

} ;

class Observer {

  public:

    Observer( const Owner & owner ) : _largeObject(owner.getLargeObject()) {}

    void setValue( double v ) {
        std::shared_ptr<LargeObject> wptr = _largeObject.lock();
        if (wptr) { wptr->data[0] = v ; }
        else { wptr->data[0] = 0. ; }
    }

    double getValue() const {
        std::shared_ptr<LargeObject> wptr = _largeObject.lock();
        if (wptr) { return wptr->data[0] ; }
        else { return -1. ; }
    }

  private:

    std::weak_ptr<LargeObject> _largeObject ;

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
