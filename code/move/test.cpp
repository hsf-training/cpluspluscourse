#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <ext/numeric>
#include "Complex.hpp"
#include "NVector.sol.hpp"

using namespace std;
using namespace __gnu_cxx;

template<class T>
void compute(int len, T initial, T step) {
    // allocate vectors
    std::vector<T> v(len+1), diffs(len+1);

    // fill and randomize v
    T current = initial;
    generate(v.begin(), v.end(),
             [&current, step]() {T cur = current;
                                 current += step;
                                 return cur;});
    random_shuffle(v.begin(), v.end());
    
    // compute differences
    adjacent_difference(v.begin(), v.end(), diffs.begin());    

    // compute standard deviation of it
    T sum = accumulate(diffs.begin()+1, diffs.end(), T());
    typename T::BaseType sumsq =
        accumulate(diffs.begin()+1, diffs.end(),
                   typename T::BaseType(),
                   [](typename T::BaseType& s, T& a) {return s + a.sqnorm(); });
    T mean = sum/len;
    typename T::BaseType variance = sumsq/len - mean.sqnorm();

    std::cout << "Variance = " << variance
              << std::endl;
}

int main() {
    compute(1000, Complex(0,0), Complex(1,2));
    compute(1000, NVector(100000,3000,-3), NVector(100000,0,1));
}
