#include "PrintHelper.h"

/* *************************************
 * * Fundamental types and expressions *
 * *************************************
 *
 * Tasks:
 * ------
 * - Compile the program and analyse the output of the different expressions
 * - Discuss with other students or your tutor in case the result of an expression is a surprise
 * - Fix the marked expressions by changing types such that they produce meaningful results
 * - Answer the questions in the code
 */

int main() {
  std::cout << "Using literals of different number types:\n";
  print(5);
  print(5.0/2.0);           //FIXME змінимо тип змінної на "double"
  print(100/2ull);
  print(2 + 4ull);
  print(2.f + 4ull);
  print(0 - 1);       // FIXME Видалимо "u"
  print(1.0000000001L ); // FIXME Змінимо тип змінної на "long double" або "double" Why is this number not represented correctly?
  print(1.l + 1.E-18);   // FIXME Змінимо тип "1" на "long double"

  std::cout << "\nUsing increment and decrement operators:\n";
  int a = 1;
  int b;
  int c;
  print(b = a++);       // Q: What is the difference between a++ and ++a? ++a фиконується раніше за a++
  print(c = ++a);
  print(a);
  print(b);
  print(c);

  std::cout << "\nCompound assignment operators:\n";
  int n = 1;
  print(n *= 2);        // Q: Is there a difference between this and the next line? У строці 39 змінна "n" спочатку переводиться в "double" для підрахунків. А потім записується у форматі "int".
  print(n *= 2.9);
  print(n -= 1.1f);
  print(n /= 4);        // Q: Based on the results of these expressions, is there a better type to be used for n? "float" або "double"

  std::cout << "\nLogic expressions:\n";
  const bool alwaysTrue = true;
  bool condition1 = false;
  bool condition2 = true;
  print( alwaysTrue && condition1 && condition2 );
  print( alwaysTrue || condition1 && condition2 );  // Q: Why does operator precedence render this expression useless? alwaysTrue завжди дає значення "1", а Оператор "&&" має вищий пріоретет за "||" отже ми зря обчислюємо "condition1 && condition2" 
  print( alwaysTrue && condition1 || condition2 );
  print(condition1 != condition1);                  // Q: What is the difference between this and the following expression? У строці 51 присвоюється протилежне значення для "condition2"
  print(condition2 = !condition2);
  print( alwaysTrue && condition1 && condition2 );
  print( alwaysTrue || condition1 && condition2 );
  print( alwaysTrue && condition1 || condition2 );

  std::cout << '\n';
  print( false || 0b10 );     // Q: What is the difference between || and | ? "|" побітова операція, перевіряє усі цисла, записує значення в "int"
  print( false | 0b10 );
  printBinary( 0b1 & 0b10 );
  printBinary( 0b1 | 0b10 );
  printBinary( 0b1 && 0b10 ); // Q: Are the operators && and || appropriate for integer types? ні тікі для bool
  printBinary( 0b1 || 0b10 );

  std::cout << "\nPlay with characters and strings:\n";
  print("a");                 // Q: Why is this expression two bytes at run time, the next only one? ".." Містять пихований символ '/0'
  print('a');

  char charArray[20];
  //charArray[19] = '/0'; // Make sure that our string is terminated with the null byte
  //Для виконання останнього завдання
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
