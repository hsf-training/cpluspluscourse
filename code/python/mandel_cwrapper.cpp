#include "mandel_cwrapper.hpp"

extern "C" {

  int mandel(float r, float i) {
    return mandel(Complex(r, i));
  }

}
