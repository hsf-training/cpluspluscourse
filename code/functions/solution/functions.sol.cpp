
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
 *      argument.name[0] = 'a';
 *    to your print function.
 *    Try both with and without const attributes in your print function's signature.
 */

#include "Structs.h" // The data structs we will work with

#include <iostream> // For printing

void printFiveCharacters(FastToCopy argument) {
    for (int i = 0; i < 5; i++)
        std::cout << argument.name[i];
    std::cout << '\n';

    // alternative 1: std::cout << argument.name.substr(0, 5) << '\n';
    // alternative 2: std::cout << std::string_view{argument.name.data(), 5} << '\n';
    // alternative C: std::printf("%.5s\n", argument.name.c_str());
    // alternative C++23: std::print("{:.5}\n", argument);
}

void printFiveCharacters(const SlowToCopy & argument) {
    //argument.data[0] = '\n' ; // EXPECTED COMPILATION ERROR
    std::cout << argument.name << '\n';
}

void printFiveCharactersWithCopy(SlowToCopy argument) {
    std::cout << argument.name << '\n';
    // We can actually modify the argument if we want, since it's a copy:
    argument.name[0] = 'a';
}

int main() {
    FastToCopy fast = {"abcdefghijkl"};
    printFiveCharacters(fast);

    SlowToCopy slow = {"ABCDEFGHIJKL"};
    printFiveCharacters(slow);

    std::cout << "Now printing with copy:\n";
    printFiveCharactersWithCopy(slow);

    return 0;
}
