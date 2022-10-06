#include <iostream>
#include <vector>
#include <random>
#include "NVector.sol.hpp"

template<typename T>
void swap(std::vector<T> &v, int a, int b) {
    T mem = std::move(v[a]);
    v[a] = std::move(v[b]);
    v[b] = std::move(mem);
    // even better
    //swap(v[a], v[b]);
}

template<typename T>
void randomize(std::vector<T> &v) {
    // we randomize via len random inversions
    std::size_t len = v.size();
    std::default_random_engine e;
    std::uniform_int_distribution<std::size_t> d{0, len};
    for (std::size_t i = 0; i < len; i++) {
        int a = d(e);
        int b = d(e);
        swap(v, a, b);
    }
}

template<typename T>
std::vector<T> getRandomVector(int len) {
    // allocate vector and initialise
    std::vector<T> v(len);
    // randomize v
    randomize(v);
    return v;
}

int main() {
    std::vector<NVector<10000, int>> v = getRandomVector<NVector<10000,int> >(10000);
}
