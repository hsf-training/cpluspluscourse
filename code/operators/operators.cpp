#include <iomanip>
#include <iostream>

class Fraction {
  // TODO: constructors and operators
};

// TODO:operators

int main() {
  // create a fraction with values 3 (which is 3/1) and 1/3
  const Fraction three{3};
  const Fraction athird{1, 3};

  // print the fractions
  std::cout << "Three: " << three << '\n';
  std::cout << "One third: " << athird << '\n';

  // multiply fraction with an int
  std::cout << "One third times two: " << athird * 2 << '\n';
  // ensure symmetry
  std::cout << "One third times two: " << 2 * athird << '\n';

  // multiply two fractions
  std::cout << "Three times one third: " << three * athird << '\n';
  // normalize the fraction after multiplication so the above statement
  // prints 1/1 instead of e.g. 3/3
  // you might need to compute the greatest common divisor, for which you can
  // use the function std::gcd(a, b) from the <numeric> header
  std::cout << "Three times one third: " << 3 * athird << '\n';

  // multiply in place
  Fraction f = athird;
  f *= 2;
  std::cout << "One third times two: " << f << '\n';

  f = athird;
  f *= athird;
  std::cout << "One third times one third: " << f << '\n';

  f = athird;
  f *= f *= f;
  std::cout << "One third times itself twice: " << f << '\n';

  // you might have some redundancy between the implementation of operator* and
  // operator*=. Can you refactor your code and implement operator* in terms of
  // operator*=?

  // add an int to a fraction
  std::cout << "One third plus 2: " << athird + 2 << '\n';
  // ensure symmetry
  std::cout << "2 plus one third: " << 2 + athird << '\n';

  // add two fractions
  std::cout << "One third plus two sixth: " << athird + Fraction{2, 6} << '\n';
  // normalize the fraction after addition too so the above statement
  // prints 2/3 instead of 12/18
  // make sure the normalization between addition and multiplication is not
  // duplicated, e.g. by putting it into a separate method

  // add in place
  f = athird;
  f += f += 1;
  std::cout << "One third plus one and added to itself: " << f << '\n';
  // again, try to refactor and implement operator+ in terms of operator+=

  std::cout << std::boolalpha;  // print bools as 'true' or 'false' from now on

  // compare two fractions for equality, all of these should be 'true'
  std::cout << "One third == one third: " << (athird == Fraction{1, 3}) << '\n'
            << "One third != one forth: " << (athird != Fraction{1, 4}) << '\n'
            << "One third == two sixth: " << (athird == Fraction{2, 6}) << '\n'
            << "One third != three sixth: " << (athird != Fraction{3, 6})
            << '\n';
  // try to implement operator!= in terms of operator==

  // more comparisons
  const Fraction afourth{1, 4};
  std::cout << athird << " < " << athird << " : " << (athird < athird) << '\n'
            << afourth << " < " << athird << " : " << (afourth < athird) << '\n'
            << athird << " <= " << athird << ": " << (athird <= athird) << '\n'
            << athird << " <= " << afourth << ": " << (athird <= afourth)
            << '\n'
            << athird << " > " << athird << ": " << (athird > athird) << '\n'
            << afourth << " > " << athird << ": " << (afourth > athird) << '\n'
            << athird << " >= " << athird << ": " << (athird >= athird) << '\n'
            << athird << " >= " << afourth << ": " << (athird >= afourth)
            << '\n';
  // the operators <=, >= and > can typically be implemented just in terms of
  // operator<. Can you do this as well? ;)

  // take aways on operators:
  // * we can very often implement an arithemtic operator@ in terms of
  // operator@=
  // * it usually suffices to implement operator< and operator== and derive the
  // other relational operators from them. C++20 will do this automatically.
}

// The final output of your program should be along these lines:
// Three: 3/1
// One third: 1/3
// One third times two: 2/3
// One third times two: 2/3
// Three times one third: 1/1
// Three times one third: 1/1
// One third times two: 2/3
// One third times one third: 1/9
// One third times itself twice: 1/81
// One third plus 2: 7/3
// 2 plus one third: 7/3
// One third plus two sixth: 2/3
// One third plus one and added to itself: 8/3
// One third == one third: true
// One third != one forth: true
// One third == two sixth: true
// One third != three sixth: true
// 1/3 < 1/3 : false
// 1/4 < 1/3 : true
// 1/3 <= 1/3: true
// 1/3 <= 1/4: false
// 1/3 > 1/3: false
// 1/4 > 1/3: false
// 1/3 >= 1/3: true
// 1/3 >= 1/4: true
