#include <iostream>
#include <list>
#include <vector>

/*

In the code below, we provide two implementations of the function increment().
The commented one is optimized for iterators which fulfill the requirements of
the concept RandomAccessIterator.

1. Uncomment and complete the concept RandomAccessIterator: check that the
   class IterT has operator +=.
2. Find an existing concept in the standard library, which can replace the
   previous user-defined concept.
3. If you comment out the default general implementation of `increment()`,
   why the compiler refuse to use remaining implementation with the list ?
   (which requirement is not fulfilled ?)

*/

/*

template <typename IterT>
concept RandomAccessIterator = requires(... TO BE COMPLETED...) {
  ... TO BE COMPLETED...
  (Only add what is necessary for this example)
};

template <RandomAccessIterator IterT>
void increment(IterT &iter, unsigned d) {
  iter += d;
  std::cout << "(random)\n";
}

*/

template <typename IterT>
void increment(IterT &iter, unsigned d) {
  while (d--)
    ++iter;
  std::cout << "(other)\n";
}

int main() {
  std::list<int> l_data = {1, 2, 3, 4, 5};
  auto l_itr = l_data.begin();
  increment(l_itr, 2);

  std::vector<int> v_data = {1, 2, 3, 4, 5};
  auto v_itr = v_data.begin();
  increment(v_itr, 2);
}
