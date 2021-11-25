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
    *i = 5; // error, i is const
    i = &b; // ok, pointer is not const

    // try constant pointer
    int * const j = &a;
    *j = 5; // ok, value can be changed
    j = &b; // error, pointer is const

    // try constant pointer to constant
    int const * const k = &a;
    *k = 5; // error, value is const
    k = &b; // error, pointer is const

    // try constant arguments of functions
    // all is fine as arguments are passed by value
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
    identityp(r);  // error due to constness
    identitypConst(p);
    identitypConst(r);

    // try constant method in a class
    ConstTest t;
    const ConstTest tc;
    std::string s("World");
    t.hello(s);
    tc.hello(s);      // error due to constness
    t.helloConst(s);
    tc.helloConst(s);
}
