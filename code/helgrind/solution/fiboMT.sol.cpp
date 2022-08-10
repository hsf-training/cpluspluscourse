#include <iostream>
#include <cstring>
#include <sstream>
#include <thread>
#include <chrono>
#include <random>

constexpr auto NBITERATIONS = 5;
constexpr auto MIN = 22;
constexpr auto MAX = 25;

struct WorkToDo {
    char* title;
    int a;
};

unsigned int fibo(unsigned a) {
    if (a == 1 || a == 0) {
        return 1;
    } else {
        return fibo(a-1)+fibo(a-2);
    }
}

void computation(WorkToDo* work, unsigned long* result) {
    *result = fibo(work->a);
}

void launchFibo(const char* title, int a) {
    WorkToDo w;
    w.title = strdup(title);
    w.a = a;
    unsigned long result;
    std::thread t{computation, &w, &result};
    std::this_thread::sleep_for(std::chrono::microseconds{1});
    std::cout << "Computing " << w.title << '\n';
    std::free(w.title);
    w.title = nullptr;
    t.join();
    std::cout << title << " = " << (unsigned long)result << '\n';
}

int main() {
    std::default_random_engine e;
    std::uniform_int_distribution d{MIN, MAX};
    for (unsigned int i = 0; i < NBITERATIONS; i++) {
        unsigned int a = d(e);
        std::stringstream ss;
        ss << "Fibo(" << a << ")";
        launchFibo(ss.str().c_str(), a);
    }
}
