#include <random>
#include <cmath>

constexpr auto NBITERATIONS = 20;
constexpr auto MAX = 40u;

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
    return static_cast<unsigned int>((1/std::sqrt(5)) * (std::pow(((1 + std::sqrt(5)) / 2), n) - std::pow(((1 - std::sqrt(5)) / 2), n)));
}

int main() {
    std::default_random_engine e;
    std::uniform_int_distribution d{0u, MAX};
    for (unsigned int i = 0; i < NBITERATIONS; i++) {
        unsigned int a = d(e);
        unsigned int b = d(e);
        add(a, b);
        mul(a, b);
        power(a, b);
        fibo(a);
    }
}
