#include <iostream>
#include <vector>
#include <random>
#include "NVector.hpp"

template<typename T>
void swap(std::vector<T> &v, int a, int b) {
    const T mem = v[a];
    v[a] = v[b];
    v[b] = mem;
}

template<typename T>
void randomize(std::vector<T> &v) {
    // we randomize via len random inversions
    const std::size_t len = v.size();
    std::default_random_engine e;
    std::uniform_int_distribution<std::size_t> d{0, len-1};
    for (std::size_t i = 0; i < len; i++) {
        const int a = d(e);
        const int b = d(e);
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
