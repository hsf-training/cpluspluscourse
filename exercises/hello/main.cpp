#include "hello.hpp"

int main() {
  int n = 3;
  for (int i = 0; i < n; i++) {
    printHello(i);
  }
  checkCpp20();
  return 0;
}
