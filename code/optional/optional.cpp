
/*

In the code below, modify the function `mysqrt` below so that it returns
an `std::optional<double>` rather than a double, and the program prints
`nothing` rather than `nan` for the call with `-10`. It will also require
to modify `square`.

*/

#include <cmath>
#include <iostream>
#include <optional>

double mysqrt( double d )   // TO BE MODIFIED
 { return std::sqrt(d) ; }  // TO BE MODIFIED

double square( double d )   // TO BE MODIFIED
 { return d*d ; }           // TO BE MODIFIED

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
