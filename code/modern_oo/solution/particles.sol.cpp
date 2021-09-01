#include <cstdlib> // pour std::rand()
#include <iostream>
#include <string>

class Particle
 {
  public  :
    Particle( double mass ) : mass_(mass) {}
    Particle( const Particle & ) = delete ;
    virtual ~Particle() = default ;
    double mass() { return mass_ ; }
    virtual std::string name() { return "Particle" ; }
  private  :
    double mass_ ;
 } ;

class ChargedParticle : public Particle
 {
  public  :
    ChargedParticle( double mass, double charge )
     : Particle(mass), charge_(charge) {}
    double charge() { return charge_ ; }
    std::string name() override { return "ChargedParticle" ; }
  private  :
    double charge_ = 0.0 ;
 } ;

void display( Particle & p  )
 {
  std::cout << p.name() << std::endl ;
  std::cout << "  mass = " << p.mass() << std::endl ;
 }

int main()
 {
  for ( int i = 0 ; i < 5 ; ++i )
   {
    if ( std::rand() < (0.5 *  double(RAND_MAX)) )
     {
      Particle p(2) ;
      display(p) ;
     }
    else
     {
      ChargedParticle p(1,1) ;
      display(p) ;
      std::cout << "  charge = " << p.charge() << std::endl ;
     }
   }
 }
