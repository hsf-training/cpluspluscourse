#include <iostream>
#include <cmath>
#include <random>

constexpr auto LEN = 1000;
constexpr auto STEP = 10;

void swap(int *a, int*b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void randomize(int* v, unsigned int len) {
    std::default_random_engine e;
    std::uniform_int_distribution d{0u, len};
    // we randomize via len random inversions
    for (unsigned int i = 0; i < len; i++) {
        int a = d(e);
        int b = d(e);
        swap(v+a, v+b);
    }
}

void fillVector(int* v, unsigned int len) {
    for (unsigned int i = 0; i < len; i++) v[i] = i*STEP;
}

int main() {
    int v[LEN+1];
    // create and randomize vector
    fillVector(v, LEN+1);
    randomize(v, LEN+1);

    // compute diffs
    int diffs[LEN];
    for (unsigned int i = 0; i < LEN; i++)
        diffs[i] = v[i+1] - v[i];

    // compute standard deviation of it
    float sum = 0;
    float sumsq = 0;
    for (unsigned int i = 0; i < LEN; i ++) {
        sum += diffs[i];
        sumsq += diffs[i]*diffs[i];
    }
    float mean = sum/LEN;
    float stddev = std::sqrt(sumsq/LEN - mean*mean) ;
    std::cout << "Range = [0, " << STEP*LEN << "]\n"
              << "Mean = " << mean
              << "\nStdDev = " << stddev << '\n';
}
