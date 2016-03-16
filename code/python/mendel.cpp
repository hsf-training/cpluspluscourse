#include "mendel.hpp"

int mendel(const Complex &a) {
  Complex z = 0;
  for (int n = 1; n < 100; n++) {
    z = z*z + a;
    if (Complex(2) < z) {
      return n;
    }
  }
  return -1;
}

