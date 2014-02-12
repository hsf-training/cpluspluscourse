int* identity(int *a) {
    return a;
};

const int* identityConst(const int *a) {
    return a;
};

int main() {
    // test pointer to constant
    int a = 1, b = 2;
    int const *i = &a;
    *i = 5; // error, i is const
    i = &b; // ok, pointer is not const

    // test constant pointer
    int * const j = &a;
    *j = 5; // ok, value can be changed
    j = &b; // error, pointer is const

    // test constant pointer to constant
    int const * const k = &a;
    *k = 5; // error, value is const
    k = &b; // error, pointer is const

    // test function constness
    int *p = 0;
    const int *r = 0;
    identity(p);
    identity(r);
    identityConst(p);
    identityConst(r);    

}
