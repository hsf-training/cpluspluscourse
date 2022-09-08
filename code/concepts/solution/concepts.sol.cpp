#include <iostream>
#include <list>
#include <vector>

// Answer to question 1

template <typename IterT>
concept RandomAccessIterator = requires(IterT itr, unsigned d) {
  itr += d;
};

template <RandomAccessIterator IterT>
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

// Answer to question 2

#include <concepts>
#include <iterator>

template <std::random_access_iterator IterT>
void increment_q2(IterT &iter, unsigned d) {
  iter += d;
  std::cout << "(random_q2)" << std::endl;
}

template <typename IterT>
void increment_q2(IterT &iter, unsigned d) {
  while (d--)
    ++iter;
  std::cout << "(other_q2)" << std::endl;
}

// Main

int main() {
  // question 1

  {
    std::list<int> l_data = {1, 2, 3, 4, 5};
    auto l_itr = l_data.begin();
    increment(l_itr, 2);

    std::vector<int> v_data = {1, 2, 3, 4, 5};
    auto v_itr = v_data.begin();
    increment(v_itr, 2);
  }

  // question 2

  {
    std::list<int> l_data = {1, 2, 3, 4, 5};
    auto l_itr = l_data.begin();
    increment_q2(l_itr, 2);

    std::vector<int> v_data = {1, 2, 3, 4, 5};
    auto v_itr = v_data.begin();
    increment_q2(v_itr, 2);
  }
}
