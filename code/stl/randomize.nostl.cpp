#include <iostream>
#include <math.h>
#include <cstdlib>

#define LEN 1000
#define STEP 7

void randomize(int* v, unsigned int len) {
    // we randomize via len random inversions
    for (unsigned int i = 0; i < len; i++) {
        int a = rand()%len;
        int b = rand()%len;
        int mem = v[a];
        v[a] = v[b];
        v[b] = mem;
    }
}

int main() {
    // create vector
    int *v = new int[LEN+1];
    for (unsigned int i = 0; i <= LEN; i++) v[i] = i*STEP;

    // randomize it
    randomize(v, LEN+1);

    // compute diffs
    int *diffs = new int[LEN];
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
    float stddev = sqrt(sumsq/LEN - mean*mean) ;
    std::cout << "Range = [0, " << STEP*LEN << "]\n"
              << "Mean = " << mean
              << "\nStdDev = " << stddev << std::endl;

    delete[] v;
    delete[] diffs;
}
