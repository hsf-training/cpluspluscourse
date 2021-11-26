#include <cstdlib> // pour std::rand()
#include <iostream>
#include <string>

class Particle
 {
  public  :
    Particle( double mass ) : mass_(mass) {}
    double mass() { return mass_ ; }
    virtual std::string name() { return "Particle" ; }
    virtual ~Particle() {}
  private  :
    Particle( const Particle & ) ; // non copiable
    double mass_ ;
 } ;

class ChargedParticle : public Particle
 {
  public  :
    ChargedParticle( double mass, double charge )
     : Particle(mass), charge_(charge) {}
    double charge() { return charge_ ; }
    virtual std::string name() { return "ChargedParticle" ; }
  private  :
    double charge_ ;
 } ;

void print( Particle & p  )
 {
  std::cout << p.name() << '\n' ;
  std::cout << "  mass = " << p.mass() << '\n' ;
 }

int main()
 {
  for ( int i = 0 ; i < 5 ; ++i )
   {
    if ( std::rand() < (0.5 *  double(RAND_MAX)) )
     {
      Particle p(2) ;
      print(p) ;
     }
    else
     {
      ChargedParticle p(1,1) ;
      print(p) ;
      std::cout << "  charge = " << p.charge() << '\n' ;
     }
   }
 }
