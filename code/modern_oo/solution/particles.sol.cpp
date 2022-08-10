#include <random>
#include <iostream>
#include <string>

class Particle
 {
  public  :
    Particle( double mass ) : mass_(mass) {}
    Particle( const Particle & ) = delete ;
    virtual ~Particle() = default ;
    double mass() const { return mass_ ; }
    virtual std::string name() const { return "Particle" ; }
  private  :
    double mass_ ;
 } ;

class ChargedParticle : public Particle
 {
  public  :
    ChargedParticle( double mass, double charge )
     : Particle(mass), charge_(charge) {}
    double charge() const { return charge_ ; }
    std::string name() const override { return "ChargedParticle" ; }
  private  :
    double charge_ = 0.0 ;
 } ;

void print( Particle & p  )
 {
  std::cout << p.name() << '\n' ;
  std::cout << "  mass = " << p.mass() << '\n' ;
 }

int main()
 {
  std::default_random_engine e;
  std::uniform_real_distribution d;
  for ( int i = 0 ; i < 5 ; ++i )
   {
    if ( d(e) < 0.5 )
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
