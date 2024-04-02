#include "PrintHelper.h"

/* *************************************
 * * Fundamental types and expressions *
 * *************************************
 *
 * Tasks:
 * - Compile the program and analyse the output of the different expressions
 * - Discuss with other students or your tutor in case the result of an expression is a surprise
 * - Fix the marked expressions by changing types such that they produce meaningful results
 * - Answer the questions in the code
 */

int main() {
  std::cout << "Using literals of different number types:\n";
  print(5);
  print(5/2.);          //FIXME
  print(100/2ull);
  print(2 + 4ull);
  print(2.f + 4ull);
  print(0  - 1 );       // FIXME
  print(1.0000000001 ); // FIXME Why is this number not represented correctly?
  print(1.l+ 1.E-18);   // FIXME

  std::cout << "\nUsing increment and decrement operators:\n";
  int a = 1;
  int b;
  int c;
  print(b = a++);       // Q: What is the difference between a++ and ++a?
  print(c = ++a);       // A: Whether it returns the previous or new value
  print(a);
  print(b);
  print(c);

  std::cout << "\nCompound assignment operators:\n";
  float n = 1;
  print(n *= 2);        // Q: Is there a difference between this and the next line?
  print(n *= 2.9);      // A: Yes, the computation runs in float and is converted back to int
  print(n -= 1.1f);
  print(n /= 4);        // Q: Based on the results of these expressions, is there a better type to be used for n?
                        // A: Probably yes, for example float

  std::cout << "\nLogic expressions:\n";
  const bool alwaysTrue = true;
  bool condition1 = false;
  bool condition2 = true;
  print( alwaysTrue && condition1 && condition2 );
  print( alwaysTrue || condition1 && condition2 );  // Q: Why does operator precedence render this expression useless?
  print( alwaysTrue && condition1 || condition2 );  // A: "true || " is evaluated last. The expression therefore is always true.
  print(condition1 != condition1);                  // Q: What is the difference between this and the following expression?
  print(condition2 = !condition2);                  // A: The first is a comparison, the second a negation with subsequent assignment
  print( alwaysTrue && condition1 && condition2 );
  print( alwaysTrue || condition1 && condition2 );
  print( alwaysTrue && condition1 || condition2 );

  std::cout << '\n';
  print( false || 0b10 );     // Q: What is the difference between || and | ?
  print( false | 0b10 );      // A: a boolean operation vs. a bit-wise boolean operation
  printBinary( 0b1 & 0b10 );
  printBinary( 0b1 | 0b10 );
  printBinary( 0b1 && 0b10 ); // Q: Are the operators && and || appropriate for integer types?
  printBinary( 0b1 || 0b10 ); // A: Most likely not, because the integers are first converted to boolean

  std::cout << "\nPlay with characters and strings:\n";
  print("a");                 // Q: Why is this expression two bytes at run time, the next only one?
  print('a');                 // A: Because the first one is a string, which is 0-terminated

  char charArray[20];
  // There are many ways to solve this, for example to use std::string and not manually manage the memory.
  // However, if one really desires to manage a char array, one should at least initialise it with the 0 byte:
  std::fill(std::begin(charArray), std::end(charArray), '\0');
  char* charPtr = charArray;

  print(charArray);
  print(charArray[0] = 'a');
  print(charArray);
  print(charArray[1] = 98);
  print(charArray);
  print(charPtr);
  // FIXME: Ensure that no unexpected garbage is printed above
}
