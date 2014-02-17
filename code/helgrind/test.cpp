#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string.h>
#include <sstream>

#define NBITERATIONS 5
#define MIN 32
#define MAX 35

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

void * computation(void* arg) {
    WorkToDo *work = (WorkToDo*) arg;
    unsigned long f = fibo(work->a);
    free(work->title);
    work->title = 0;
    return (void*)f;
}

void launchFibo(const char* title, int a) {
    pthread_t t;
    WorkToDo w;
    w.title = strdup(title);
    w.a = a;
    if (pthread_create(&t, NULL, computation, &w)) {
        std::cerr << "Error creating thread" << std::endl;
        return;
    }
    std::cout << "Computing " << w.title << std::endl;
    void *result;
    pthread_join(t, &(result));
    std::cout << title << " = " << (unsigned long)result << std::endl;
}

int main() {
    for (unsigned int i = 0; i < NBITERATIONS; i++) {
        unsigned int a = MIN+rand()%(MAX-MIN);
        std::stringstream ss;
        ss << "Fibo(" << a << ")";
        launchFibo(ss.str().c_str(), a);
    }
}
