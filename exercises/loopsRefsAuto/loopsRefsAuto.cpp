#include <iostream>

struct DontCopyMe {
   int resultA;
   int resultB;

   // This is material for the second day:
   DontCopyMe() = default;
   DontCopyMe(const DontCopyMe& other) :
       resultA(other.resultA),
       resultB(other.resultB)
   { std::cout << "Please don't copy me\n"; }
};

int main() {
   // We create an array of DontCopyMe structs:
   DontCopyMe collection[10];

   // Task 1:
   // Write a for loop that initialises each struct's resultA and resultB with ascending integers.
   // Verify the output of the program before and after you do this.


   // Task 2:
   // We use a range-based for loop to analyse the array of structs.
   // The problem is: we are copying every DontCopyMe ...
   // Fix this loop using references.
   // Hint: Fix the type declaration "auto" in the loop head.
   int resultA = 0;
   int resultB = 0;
   for (auto item : collection) {
      resultA += item.resultA;
      resultB += item.resultB;
   }
   std::cout << "resultA = " << resultA << "\tresultB = " << resultB << "\n";

   return 0;
}

// Task 3:
// Think about which loop needs write access to the DontCopyMe.
// Make sure that all references that don't need write access are const.
// Hint: C++ understands "auto const".
