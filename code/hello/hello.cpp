#include "hello.hpp"

#include <iostream>
#include <array>
#include <string>

void printHello(int i) {
  std::cout << "Hello, world " << i << '\n';
}

void checkCpp20() {
  std::array<std::string, 4> worldHellos{"Bonjour", "Ciao", "Guten Tag", "Hello"};
  for (int i=0; auto const& hello : worldHellos) {
    i++;
    std::cout << "(" << i << ") " << hello << "\n";
  }
}
