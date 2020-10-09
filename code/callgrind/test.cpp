#include <iostream>
#include <cstdlib>
#include <math.h>

#define NBITERATIONS 20
#define MAX 40

unsigned int add(unsigned int a, unsigned int b) {
    return a + b;
}

unsigned int mul(unsigned int a, unsigned int b) {
    return a * b;
}

unsigned int power(unsigned int a, unsigned int b) {
    unsigned int res = 1;
    for (unsigned int i = 0; i < b; i++) res *= a;
    return res;
}

unsigned int fibo(int a) {
    if (a == 1 || a == 0) {
        return 1;
    } else {
        return fibo(a-1)+fibo(a-2);
    }
}

unsigned int fibo2(int n) {
    return (1/sqrt(5)) * (pow(((1 + sqrt(5)) / 2), n) - pow(((1 - sqrt(5)) / 2), n));
}

int main() {
    for (unsigned int i = 0; i < NBITERATIONS; i++) {
        unsigned int a = rand()%MAX;
        unsigned int b = rand()%MAX;
        add(a, b);
        mul(a, b);
        power(a, b);
        fibo(a);
    }
}
