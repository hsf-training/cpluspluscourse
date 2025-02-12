
/* Tasks:
 * 1. Check out Structs.h. It defines two structs that we will work with.
 *    FastToCopy
 *    SlowToCopy
 *    They are exactly what their name says, so let's try to avoid copying the latter.
 * 2. Using "printName()" as an example, write a function that prints the name of "SlowToCopy".
 *    Call it in main().
 * 3. Try passing by copy and passing by reference, see the difference.
 * 4. When passing by reference, ensure that your "printName" cannot inadvertently modify the original object.
 *    To test its const correctness, try adding something like
 *      argument.name = "other name";
 *    to your print function.
 *    Try both with and without const attributes in your print function's signature.
 */

#include "Structs.h" // The data structs we will work with

#include <iostream> // For printing

void printName(FastToCopy argument) {
    std::cout << argument.name << '\n';
}

void printName_slow(SlowToCopy argument) {
    std::cout << argument.name << '\n';
}

void printName_fast(const SlowToCopy &argument) {
    std::cout << argument.name << '\n';
}

int main() {
    FastToCopy fast = {"Fast"};
    printName(fast);

    SlowToCopy slow = {"Slow"};

    printName_slow(slow);
    printName_fast(slow);

    return 0;
}
