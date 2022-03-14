#include "Structs.h" // The data structs we will work with

#include <cstdio> // For printing

void printFiveCharacters(FastToCopy argument) {
    printf("The first five characters are '%.5s'\n", argument.data);
}

void printFiveCharacters(const SlowToCopy & argument) {
    //argument.data[0] = '\n' ; // EXPECTED COMPILATION ERROR
    printf("The first five characters are '%.5s'\n", argument.data);
}

int main() {
    FastToCopy fast = {"abcdef"};
    printFiveCharacters(fast);

    SlowToCopy slow = {"ghijkl"};
    printFiveCharacters(slow);

    return 0;
}
