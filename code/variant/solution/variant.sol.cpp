#include <iostream>
#include <vector>
#include <variant>

struct Electron
 { void print(){ std::cout<<"E"<<std::endl ; } } ;

struct Proton
 { void print(){ std::cout<<"P"<<std::endl ; } } ;

struct Neutron
 { void print(){ std::cout<<"N"<<std::endl ; } } ;

using Particle = std::variant<Electron,Proton,Neutron> ;

template< typename T >
void print_if( Particle & p )
 {
  auto * ptr = std::get_if<T>(&p) ;
  if (ptr) ptr->print() ;
 }

int main()
 {
  std::vector<Particle> ps =
   { Electron(), Proton(), Neutron() } ;

  for ( auto p : ps )
   {
    print_if<Electron>(p) ;
    print_if<Proton>(p) ;
    print_if<Neutron>(p) ;
   }
 }
