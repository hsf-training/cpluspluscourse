#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <random>
#include "Complex.hpp"

using namespace std;

template<typename T>
void compute(int len, T initial, T step) {
    // allocate vectors
    std::vector<T> v(len+1), diffs(len+1);

    // fill and randomize v
    generate(, , [](...) { ...; });
    shuffle(..., std::default_random_engine{});

    // compute differences
    adjacent_difference(...);

    // compute standard deviation of it
    T sum = accumulate(...);
    T sumsq = accumulate(..., [](...) { ...; });
    T mean = sum/len;
    T variance = sumsq/len - mean*mean;

    std::cout << "Range = [" << initial << ", " << step*len << "]\n"
              << "Mean = " << mean << '\n'
              << "Variance = " << variance << '\n';
}

int main() {
    compute(1000, 0.0, 7.0);
    // call compute here with Complex
}
