#ifndef FUNCTIONS_STRUCTS_H_
#define FUNCTIONS_STRUCTS_H_

struct FastToCopy {
    char data[10];
};

struct SlowToCopy {
    char data[1000000];

    // Functions to create and copy this struct.
    // We go into details on the next days.
    SlowToCopy();
    SlowToCopy(const SlowToCopy& other);
};

#endif /* FUNCTIONS_STRUCTS_H_ */
