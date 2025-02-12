#include <iostream>

struct DontCopyMe {
   int resultA = 0;
   int resultB = 0;

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

   for (int i = 0; i < 10; ++i) {
      collection[i].resultA = i * 2;
      collection[i].resultB = i * 3;
   }

   int resultA = 0;
   int resultB = 0;
   for (const auto& item : collection) {
      resultA += item.resultA;
      resultB += item.resultB;
   }

   std::cout << "resultA = " << resultA << "\tresultB = " << resultB << "\n";

   return 0;
}
