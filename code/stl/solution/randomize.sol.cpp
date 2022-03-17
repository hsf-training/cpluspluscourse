#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <random>
#include "Complex.hpp"

using namespace std;

template<typename T>
struct Generator {
    T m_value, m_step;
    Generator(T initial, T step):m_value(initial), m_step(step){};
    T operator()() {
        T cur_value = m_value;
        m_value += m_step;
        return cur_value;
    }
};

template<typename T>
struct sumsquare {
    T operator()(const T& s, const T& a) { return s + a * a; };
};

template<typename T>
void compute(int len, T initial, T step) {
    // allocate vectors
    std::vector<T> v(len+1), diffs(len+1);

    // fill and randomize v
    generate(v.begin(), v.end(), Generator<T>(initial, step));
    shuffle(v.begin(), v.end(), std::default_random_engine{});

    // compute differences
    adjacent_difference(v.begin(), v.end(), diffs.begin());

    // compute standard deviation of it
    T sum = reduce(diffs.begin()+1, diffs.end(), T());
    T sumsq = reduce(diffs.begin()+1, diffs.end(), T(), sumsquare<T>());
    T mean = sum/len;
    T variance = sumsq/len - mean*mean;

    std::cout << "Range = [" << initial << ", " << step*len << "]\n"
              << "Mean = " << mean << '\n'
              << "Variance = " << variance << '\n';
}

int main() {
    compute(1000, 0.0, 7.0);
    compute(1000, Complex(0,0), Complex(1,2));
}
