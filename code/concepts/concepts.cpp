#include <iostream>
#include <list>
#include <vector>

/*

In the code below, we provide two implementations of the function increment().
The second one is optimized for the iterators which fulfill the requirements of
the concept RandomAccessIterator.

1. Complete the concept RandomAccessIterator : check that the class IterT has some operator +=.
2. Find an existing concept in the standard library, which can replace the previous user-defined concept.

*/


template< typename IterT>
concept RandomAccessIterator = requires( /* TO BE COMPLETED */ )
 { /* TO BE COMPLETED */ } ;

template< RandomAccessIterator IterT >
void increment( IterT & iter, unsigned d )
 {
  iter += d ;
  std::cout<<"(random)"<<std::endl ;
 }

template< typename IterT >
void increment( IterT & iter, unsigned d )
 {
  while (d--) ++iter ;
  std::cout<<"(other)"<<std::endl ;
 }

int main()
 {
  std::list<int> l_data = { 1, 2, 3, 4, 5 } ;
  auto l_itr = l_data.begin() ;
  increment(l_itr,2) ;

  std::vector<int> v_data = { 1, 2, 3, 4, 5 } ;
  auto v_itr = v_data.begin() ;
  increment(v_itr,2) ;
 }
