#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <ext/numeric>
#include "Complex.hpp"

using namespace std;
using namespace __gnu_cxx;

template<typename T>
struct Generator {
    ...
};

template<typename T>
void compute(int len, T initial, T step) {
    // allocate vectors
    std::vector<T> v(len+1), diffs(len+1);

    // fill and randomize v
    generate(, , Generator...);
    random_shuffle(...);

    // compute differences
    adjacent_difference(...);

    // compute standard deviation of it
    T sum = accumulate(...);
    T sumsq = accumulate(...);
    T mean = sum/len;
    T variance = sumsq/len - mean*mean;

    std::cout << "Range = [" << initial << ", " << step*len << "]\n"
              << "Mean = " << mean << "\n"
              << "Variance = " << variance << std::endl;
}

int main() {
    compute(1000, 0.0, 7.0);
}
