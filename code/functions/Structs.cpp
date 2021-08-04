#include "Structs.h"

#include <chrono>
#include <thread>
#include <cstdio>

/// Construct a new instance of SlowToCopy.
SlowToCopy::SlowToCopy() {
    strncpy(data, "Large type", sizeof(data));
}

/// Construct a new instance of SlowToCopy, copying the data from 'other'.
SlowToCopy::SlowToCopy(const SlowToCopy& other) {
    printf("%s: Please don't copy me. This is slow.\n", __func__);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    memcpy(data, other.data, sizeof(data));
}
