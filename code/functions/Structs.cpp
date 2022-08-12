#include "Structs.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <cstring>

/// Construct a new instance of SlowToCopy.
SlowToCopy::SlowToCopy() : name("Large type") {}

/// Construct a new instance of SlowToCopy.
SlowToCopy::SlowToCopy(const std::string& name) : name(name) {}

/// Construct a new instance of SlowToCopy, copying the data from 'other'.
SlowToCopy::SlowToCopy(const SlowToCopy& other) {
    std::cout << __func__ << ": Please don't copy me. This is slow.\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    name = other.name;
    std::memcpy(bigdata, other.bigdata, sizeof(bigdata));
}
