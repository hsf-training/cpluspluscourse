#include <iostream>
#include <string>

void copy(int a) {
    [[maybe_unused]] int val = a;
};

void copyConst(const int a) {
    [[maybe_unused]] int val = a;
};

void write(int* a) {
    *a = 42;
};

void read(const int *a) {
    [[maybe_unused]] int val = *a;
};

struct Test {
    void hello(std::string &s) {
        std::cout << "Hello " << s << '\n';
    }
    void helloConst(std::string &s) const {
        std::cout << "Hello " << s << '\n';
    }
};

int main() {
    // try pointer to constant
    int a = 1, b = 2;
    int const *i = &a;
    *i = 5;
    i = &b;

    // try constant pointer
    int * const j = &a;
    *j = 5;
    j = &b;

    // try constant pointer to constant
    int const * const k = &a;
    *k = 5;
    k = &b;

    // try constant arguments of functions
    int l = 0;
    const int m = 0;
    copy(l);
    copy(m);
    copyConst(l);
    copyConst(m);

    // try constant arguments of functions with pointers
    int *p = 0;
    const int *r = 0;
    write(p);
    write(r);
    read(p);
    read(r);

    // try constant method in a class
    Test t;
    const Test tc;
    std::string s("World");
    t.hello(s);
    tc.hello(s);
    t.helloConst(s);
    tc.helloConst(s);
}
