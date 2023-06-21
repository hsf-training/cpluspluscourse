#pragma once

#include <string>

struct FastToCopy {
    std::string name;
};

struct SlowToCopy {
    std::string name;
    int bigdata[1000000];

    // Functions to create and copy this struct.
    // We go into details on the next days.
    SlowToCopy();
    SlowToCopy(const std::string& name);
    SlowToCopy(const SlowToCopy& other);
};
