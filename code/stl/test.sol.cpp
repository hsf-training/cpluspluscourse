#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <ext/numeric>
#include "Complex.hpp"

using namespace std;
using namespace __gnu_cxx;

template<class T>
struct Generator {
    T m_value, m_step;
    Generator(T initial, T step):m_value(initial-step), m_step(step){};
    T operator()() {
        T cur_value = m_value;
        m_value += m_step;
        return cur_value;
    }
};

template<class T>
struct square {
    T operator()(T& a) { return a * a; };
};
    
template<class T>
void computeStdDev(int len, T initial, T step) {
    // allocate vectors
    std::vector<T> v(len+1), diffs(len+1);

    // fill and randomize v
    generate(v.begin(), v.end(), Generator<T>(initial, step));
    random_shuffle(v.begin(), v.end());
    
    // compute differences
    adjacent_difference(v.begin(), v.end(), diffs.begin());    

    // compute standard deviation of it
    T sum = T();
    T sumsq = T();
    sum = accumulate(diffs.begin()+1, diffs.end(), sum);
    transform(diffs.begin()+1, diffs.end(),
              diffs.begin()+1,
              diffs.begin()+1,
              multiplies<T>());
    sumsq = accumulate(diffs.begin()+1, diffs.end(), sumsq);
    T mean = sum/len;
    T variance = sumsq/len - mean*mean;

    std::cout << "Range = [" << initial << ", " << step*len << "]\n"
              << "Mean = " << mean << "\n"
              << "Variance = " << variance << std::endl;
}

int main() {
    computeStdDev(1000, 0.0, 7.0);
    computeStdDev(1000, Complex(0,0), Complex(1,2));
}
