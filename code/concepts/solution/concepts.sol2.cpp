#include <iostream>
#include <list>
#include <vector>
#include <concepts>

template <std::random_access_iterator IterT>
void increment(IterT &iter, unsigned d) {
  iter += d;
  std::cout << "(random)" << std::endl;
}

template <typename IterT>
void increment(IterT &iter, unsigned d) {
  while (d--)
    ++iter;
  std::cout << "(other)" << std::endl;
}

// Main

int main() {

  std::list<int> l_data = {1, 2, 3, 4, 5};
  auto l_itr = begin(l_data);
  increment(l_itr, 2);

  std::vector<int> v_data = {1, 2, 3, 4, 5};
  auto v_itr = begin(v_data);
  increment(v_itr, 2);

}
