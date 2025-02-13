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
  
  friend bool equivalent( Fraction const & lhs, Fraction const & rhs ) {
    return (lhs.m_num*rhs.m_denom==rhs.m_num*lhs.m_denom);
  }
  
  friend Fraction multiply( Fraction const & lhs, Fraction const & rhs ) {
    return {lhs.m_num*rhs.m_num, lhs.m_denom*rhs.m_denom};
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

#define CHECK(printer,what) printer.process(#what, what)

int main() {

  // create a fraction with values 3 (which is 3/1) and 1/3
  std::cout<<std::endl;
  const Fraction three{3};
  const Fraction third{1, 3};
  std::cout<<three.str()<<' '<<third.str()<<'\n';
  
  // equality
  std::cout<<std::endl;
  TestResultPrinter p1{27};
  CHECK(p1,equal(three,three));
  CHECK(p1,equal(third,third));
  CHECK(p1,equal(three,Fraction{3}));
  CHECK(p1,equal(three,Fraction{3,1}));
  CHECK(p1,equal(third,Fraction{1,3}));
  CHECK(p1,equal(Fraction{3},three));
  CHECK(p1,equal(Fraction{1,3},third));

  // equivalence
  std::cout<<std::endl;
  TestResultPrinter p2{40};
  CHECK(p2,!equal(third,Fraction{2,6}));
  CHECK(p2,equivalent(third,Fraction{2,6}));
  CHECK(p2,equal(third,Fraction{2,6}.normalized()));

  // multiply
  std::cout<<std::endl;
  TestResultPrinter p3{48};
  CHECK(p3,equal(multiply(third,2),Fraction{2,3}));
  CHECK(p3,equal(multiply(2,third),Fraction{2,3}));
  CHECK(p3,equivalent(multiply(three,third),Fraction{1,1}));
  CHECK(p3,equivalent(multiply(3,third),1));

  // end
  std::cout<<std::endl;

}
