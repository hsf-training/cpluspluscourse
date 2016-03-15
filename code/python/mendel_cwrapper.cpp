#include "mendel_cwrapper.hpp"

extern "C" {

  int mendel(float r, float i) {
    return mendel(Complex(r, i));
  }

}
