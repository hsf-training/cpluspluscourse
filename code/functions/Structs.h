#pragma once

struct FastToCopy {
    char data[10];
};

struct SlowToCopy {
    char data[1000000];

    // Functions to create and copy this struct.
    // We go into details on the next days.
    SlowToCopy();
    SlowToCopy(const char* string);
    SlowToCopy(const SlowToCopy& other);
};
