#include <iomanip>
#include <iostream>
#include <sstream>
#include <compare>
#include <numeric>

class Fraction {

public:

  Fraction(int a_num, int a_denom = 1) : m_num(a_num), m_denom(a_denom) {}

  std::string str() const {
    std::ostringstream oss;
    oss << m_num << '/' << m_denom;
    return oss.str();
  }

  friend bool operator==(Fraction const & lhs, Fraction const & rhs) {
    return lhs.m_num == rhs.m_num && lhs.m_denom == rhs.m_denom;
  }

  friend bool operator!=(Fraction const & lhs, Fraction const & rhs) {
    return !(lhs==rhs);
  }

  friend auto operator<=>( Fraction const & lhs, Fraction const & rhs ) {
    return ((lhs.m_num*rhs.m_denom)<=>(rhs.m_num*lhs.m_denom));
  }

  Fraction & operator*=(Fraction const & other) {
    m_num *= other.m_num;
    m_denom *= other.m_denom;
    return *this;
  }

  friend Fraction operator*( Fraction lhs, Fraction const & rhs ) {
    return lhs*=rhs;
  }

  Fraction normalized() const {
    const int gcd = std::gcd(m_num, m_denom);
    return {m_num/gcd, m_denom/gcd};
  }

private:

  int m_num, m_denom;

};

std::ostream & operator<<(std::ostream & os, Fraction const & f) {
    return (os<<f.str()) ;
}

class TestResultPrinter {

public:

  TestResultPrinter( unsigned int a_width ) : m_width(a_width) {}

  void operator()(std::string const & what, bool passed) {
    std::cout << std::left << std::setw(m_width) << what << ": " << (passed ? "PASS" : "** FAIL **") << '\n';
  }

private:

  unsigned int m_width;

};

#define CHECK(printer,what) printer(#what, what)

int main() {

  // create a fraction with values 3 (which is 3/1) and 1/3
  std::cout<<std::endl;
  const Fraction three{3};
  const Fraction third{1,3};
  std::cout<<three<<' '<<third<<'\n';

  // equality
  std::cout<<std::endl;
  TestResultPrinter p1{36};
  CHECK(p1,three==three);
  CHECK(p1,third==third);
  CHECK(p1,three==Fraction{3});
  CHECK(p1,(three==Fraction{3,1}));
  CHECK(p1,(third==Fraction{1,3}));
  CHECK(p1,(Fraction{3}==three));
  CHECK(p1,(Fraction{1,3}==third));
  CHECK(p1,(third!=Fraction{2,6}));
  CHECK(p1,third==(Fraction{2,6}.normalized()));

  // equivalence & comparison
  std::cout<<std::endl;
  TestResultPrinter p2{34};
  CHECK(p2,std::is_eq(third<=>Fraction{2,6}));
  CHECK(p2,std::is_gt(third<=>Fraction{1,4}));
  CHECK(p2,std::is_lt(third<=>Fraction{2,4}));
  CHECK(p2,(third>Fraction{1,4}));
  CHECK(p2,(third<Fraction{2,4}));
  CHECK(p2,!(third<=Fraction{1,4}));
  CHECK(p2,!(third>=Fraction{2,4}));
  CHECK(p2,(third>=Fraction{1,4}));
  CHECK(p2,(third<=Fraction{2,4}));
  CHECK(p2,(third>=Fraction{1,3}));
  CHECK(p2,(third<=Fraction{2,3}));
  CHECK(p2,!(third<Fraction{1,4}));
  CHECK(p2,!(third>Fraction{2,4}));
  CHECK(p2,!(third<Fraction{1,3}));
  CHECK(p2,!(third>Fraction{2,3}));

  // multiply
  std::cout<<std::endl;
  TestResultPrinter p3{42};
  CHECK(p3,((third*2)==Fraction{2,3}));
  CHECK(p3,((2*third)==Fraction{2,3}));
  CHECK(p3,std::is_eq((three*third)<=>Fraction{1,1}));
  CHECK(p3,std::is_eq((3*third)<=>Fraction{1,1}));
  CHECK(p3,((3*third).normalized()==1));

  // multiply in place
  std::cout<<std::endl;
  TestResultPrinter p4{20};
  Fraction one {third};
  ((one *= 2) *=  3) *= Fraction{1,2};
  CHECK(p4,std::is_eq(one<=>1));
  CHECK(p4,one.normalized()==1);
  CHECK(p4,one!=1);

  // end
  std::cout<<std::endl;

}
