#include <iostream>
#include <string>

int identity(int a) {
    return a;
};

int identityConst(const int a) {
    return a;
};

int* identityp(int* a) {
    return a;
};

const int* identitypConst(const int *a) {
    return a;
};

struct ConstTest {
    void hello(std::string &s) {
        std::cout << "Hello " << s << std::endl;
    }
    void helloConst(std::string &s) const {
        std::cout << "Hello " << s << std::endl;
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
    identity(l);
    identity(m);
    identityConst(l);
    identityConst(m);

    // try constant arguments of functions with pointers
    int *p = 0;
    const int *r = 0;
    identityp(p);
    identityp(r);
    identitypConst(p);
    identitypConst(r);

    // try constant method in a class
    ConstTest t;
    const ConstTest tc;
    std::string s("World");
    t.hello(s);
    tc.hello(s);
    t.helloConst(s);
    tc.helloConst(s);
}
