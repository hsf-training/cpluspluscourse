#include "Structs.h" // The data structs we will work with

#include <cstdio> // For printing

void printFiveCharacters(FastToCopy argument) {
    printf("The first five characters are '%.5s'\n", argument.data);
}

/* Tasks:
 * 1. Check out Structs.h. It defines two structs that we will work with.
 *    FastToCopy
 *    SlowToCopy
 *    They are exactly what their name says, so let's try to avoid copying the latter.
 * 2. Using "printFiveCharacters()" as an example, write a function that prints the first five characters of "SlowToCopy".
 *    Call it in main().
 * 3. Try passing by copy and passing by reference, see the difference.
 * 4. When passing by reference, ensure that your "printFiveCharacters" cannot inadvertently modify the original object.
 *    To test its const correctness, try adding something like
 *      argument.data[0] = 'a';
 *    to your print function.
 *    Try both with and without const attributes in your print function's signature.
 */

int main() {
    FastToCopy fast = {"abcdef"};
    printFiveCharacters(fast);

    SlowToCopy slow = {"ghijk"};
    // print it here



    return 0;
}
