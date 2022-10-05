#include <cmath>
#include <iostream>
#include <optional>

std::optional<double> mysqrt( double d )
 {
  if (d<0) { return std::nullopt ; }
  else { return std::sqrt(d) ; }
 }

std::optional<double> square( std::optional<double> d )
 {
  if (d) { return d.value()*d.value() ; }
  else { return {} ; }
 }

template< typename A >
std::ostream & operator<<( std::ostream & os, std::optional<A> const & opt )
 {
  if (opt) { return os<<opt.value() ; }
  else { return os<<"nothing" ; }
 }

int main()
 {
  std::cout<<square(mysqrt(10))<<std::endl ;
  std::cout<<square(mysqrt(-10))<<std::endl ;
 }
