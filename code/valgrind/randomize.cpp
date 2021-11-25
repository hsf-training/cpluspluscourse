#include <iostream>
#include <math.h>
#include <cstdlib>

#define LEN 1000
#define STEP 7

void swap(int *a, int*b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void randomize(int* v, unsigned int len) {
    // we randomize via len random inversions
    for (unsigned int i = 0; i < len; i++) {
        int a = rand()%len;
        int b = rand()%len;
        swap(v+a, v+b);
    }
}

void createAndFillVector(int** v, unsigned int len) {
    *v = new int[len];
    for (unsigned int i = 0; i < len; i++) (*v)[i] = i*STEP;
}

int main() {
    int *v;
    // create and randomize vector
    createAndFillVector(&v, LEN+1);
    randomize(v, LEN+1);

    // compute diffs
    int *diffs = new int[LEN];
    for (unsigned int i = 0; i < LEN; i++)
        diffs[i] = v[i+1] - v[i];
    delete[] v;
    delete[] diffs;

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
              << "\nStdDev = " << stddev << '\n';
}
