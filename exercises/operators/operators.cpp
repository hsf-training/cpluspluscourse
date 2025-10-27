#include <iomanip>
#include <iostream>
#include <sstream>
#include <numeric>

class Fraction {

public:

  Fraction(int a_num, int a_denom = 1) : m_num(a_num), m_denom(a_denom) {}

  std::string str() const {
    std::ostringstream oss;
    oss << m_num << '/' << m_denom;
    return oss.str();
  }

  friend bool equal( Fraction const & lhs, Fraction const & rhs ) {
    return (lhs.m_num==rhs.m_num) && (lhs.m_denom==rhs.m_denom);
  }

  friend int compare( Fraction const & lhs, Fraction const & rhs ) {
    int v1 = lhs.m_num * rhs.m_denom;
    int v2 = rhs.m_num * lhs.m_denom;
    if (v1 < v2) return -1;
    else if (v1 > v2) return 1;
    else return 0;
  }

  friend Fraction multiply( Fraction const & lhs, Fraction const & rhs ) {
    return {lhs.m_num * rhs.m_num, lhs.m_denom * rhs.m_denom};
  }

  Fraction normalized() const {
    const int gcd = std::gcd(m_num, m_denom);
    return {m_num/gcd, m_denom/gcd};
  }

private:

  int m_num, m_denom;

};

class TestResultPrinter {

public:

  TestResultPrinter( unsigned int a_width ) : m_width(a_width) {}

  void process(std::string const & what, bool passed) {
    std::cout << std::left << std::setw(m_width) << what << ": " << (passed ? "PASS" : "** FAIL **") << '\n';
  }

private:

  unsigned int m_width;

};

// This is using the cpp, the C preprocessor to expand a bit of code
// (the arguments in '...') to a pair containing a string representation
// of it and the code itself. That way, print is given a string and a
// value where the string is the code that lead to the value
#define CHECK(...) TestResultPrinter{50}.process(#__VA_ARGS__, (__VA_ARGS__))

int main() {

  // create a fraction with values 3 (which is 3/1) and 1/3
  std::cout<<std::endl;
  const Fraction three{3};
  const Fraction third{1,3};
  std::cout<<three.str()<<' '<<third.str()<<'\n';

  // equality
  std::cout<<std::endl;
  CHECK(equal(three,three));
  CHECK(equal(third,third));
  CHECK(equal(three,Fraction{3}));
  CHECK(equal(three,Fraction{3,1}));
  CHECK(equal(third,Fraction{1,3}));
  CHECK(equal(Fraction{3},three));
  CHECK(equal(Fraction{1,3},third));
  CHECK(!equal(third,Fraction{2,6}));
  CHECK(equal(third,Fraction{2,6}.normalized()));

  // equivalence & comparison
  std::cout<<std::endl;
  CHECK(compare(third,Fraction{2,6})==0);
  CHECK(compare(third,Fraction{1,4})>0);
  CHECK(compare(third,Fraction{2,4})<0);

  // multiply
  std::cout<<std::endl;
  CHECK(equal(multiply(third,2),Fraction{2,3}));
  CHECK(equal(multiply(2,third),Fraction{2,3}));
  CHECK(compare(multiply(three,third),Fraction{1,1})==0);
  CHECK(compare(multiply(3,third),Fraction{1,1})==0);
  CHECK(equal(multiply(3,third).normalized(),1));

  // end
  std::cout<<std::endl;

}
