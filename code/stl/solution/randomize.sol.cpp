#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <random>
#include "Complex.hpp"

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
    std::generate(v.begin(), v.end(), Generator<T>(initial, step));
    // Alternatively:
    // std::generate(v.begin(), v.end(), [value = initial, step]() mutable {
    //     const T cur = value;
    //     value += step;
    //     return cur;
    // });

    std::shuffle(v.begin(), v.end(), std::default_random_engine{});

    // compute differences
    std::adjacent_difference(v.begin(), v.end(), diffs.begin());

    // compute standard deviation of it
    const T sum = std::reduce(diffs.begin()+1, diffs.end(), T());
    const T sumsq = std::reduce(diffs.begin()+1, diffs.end(), T(), sumsquare<T>());
    // Alternatively:
    // const T sumsq = std::reduce(diffs.begin()+1, diffs.end(), T(),
    //                             [](const T& s, const T& a) { return s + a * a; });
    const T mean = sum/len;
    const T variance = sumsq/len - mean*mean;

    std::cout << "Range = [" << initial << ", " << step*len << "]\n"
              << "Mean = " << mean << '\n'
              << "Variance = " << variance << '\n';
}

int main() {
    compute(1000, 0.0, 7.0);
    compute(1000, Complex(0,0), Complex(1,2));
}
