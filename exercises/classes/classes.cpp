#include <iomanip>
#include <iostream>
#include <numeric>

class Fraction {

public:

  // ADD YOUR CODE HERE

  std::string str() const {
    std::ostringstream oss;
    oss << m_num << '/' << m_denom;
    return oss.str();
  }

  int numerator() const {
    return m_num;
  }
  int denominator() const {
    return m_denom;
  }

private:

  void normalize() {
    const int gcd = std::gcd(m_num, m_denom);
    m_num /= gcd;
    m_denom /= gcd;
  }

  int m_num, m_denom;
};

// ADD YOUR CODE HERE

#define CHECK(print,what) print(#what, what)

unsigned int WIDTH {20};

void printTestResult(std::string const & what, bool passed) {
  std::cout << std::setw(WIDTH) << what << ": " << (passed ? "PASS" : "** FAIL **") << '\n';
}

int main() {

  // create a fraction with values 3 (which is 3/1) and 1/3
  std::cout<<std::endl;
  const Fraction three{3};
  const Fraction third{1, 3};
  std::cout<<three.str()<<' '<<third.str()<<'\n';

  // equality
  std::cout<<std::endl;
  CHECK(printTestResult,equal(three,three));
  CHECK(printTestResult,equal(third,third));
  CHECK(printTestResult,equal(three,Fraction{3}));
  CHECK(printTestResult,equal(three,Fraction{3, 1}));
  CHECK(printTestResult,equal(third,Fraction{1, 3}));
  CHECK(printTestResult,equal(Fraction{3},three));
  CHECK(printTestResult,equal(Fraction{1, 3},third));
  CHECK(printTestResult,equal(third,Fraction{2, 6}));

  // multiply
  std::cout<<std::endl;
  CHECK(printTestResult,equal(multiply(third,2),Fraction{2, 3}));
  CHECK(printTestResult,equal(multiply(2,third),Fraction{2, 3}));
  CHECK(printTestResult,equal(multiply(three,third),Fraction{1, 1}));
  CHECK(printTestResult,equal(multiply(3,third),1));

  // end
  std::cout<<std::endl;

}
