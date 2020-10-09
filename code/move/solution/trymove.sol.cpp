#include <iostream>
#include <vector>
#include "NVector.sol.hpp"

template<class T>
void swap(std::vector<T> &v, int a, int b) {
    T mem = std::move(v[a]);
    v[a] = std::move(v[b]);
    v[b] = std::move(mem);
    // even better
    //swap(v[a], v[b]);
}

template<class T>
void randomize(std::vector<T> &v) {
    // we randomize via len random inversions
    unsigned int len = v.size();
    for (unsigned int i = 0; i < len; i++) {
        int a = rand()%len;
        int b = rand()%len;
        swap(v, a, b);
    }
}

template<class T>
std::vector<T> getRandomVector(int len) {
    // allocate vectors
    std::vector<T> v(len);
    // fill and randomize v
    for (int i = 0; i < len; i++) v[i] = T();
    randomize(v);
    return v;
}

int main() {
    std::vector<NVector<10000, int>> v = getRandomVector<NVector<10000,int> >(10000);
}
