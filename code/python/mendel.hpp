#include "Complex.hpp"

template <class T=float>
int mendel(T a) {
  T z = 0;
  for (int n = 1; n < 100; n++) {
    z = z*z + a;
    if (T(2) < z) {
      return n;
    }
  }
  return -1;
}

