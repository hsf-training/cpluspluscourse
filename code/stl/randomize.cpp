#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <random>
#include "Complex.hpp"

template<typename T>
void compute(int len, T initial, T step) {
    // allocate vectors
    std::vector<T> v(len+1), diffs(len+1);

    // fill and randomize v
    std::generate(, , [](...) { ...; });
    std::shuffle(..., std::default_random_engine{});

    // compute differences
    std::adjacent_difference(...);

    // compute standard deviation of all differences
    const T sum = std::reduce(...);
    const T sumsq = std::reduce(..., [](...) { ...; });
    const T mean = sum/len;
    const T variance = sumsq/len - mean*mean;

    std::cout << "Range = [" << initial << ", " << step*len << "]\n"
              << "Mean = " << mean << '\n'
              << "Variance = " << variance << '\n';
}

int main() {
    compute(1000, 0.0, 7.0);
    // call compute here with Complex
}
