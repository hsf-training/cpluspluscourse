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
    static TestResultPrinter& instance() {
        static TestResultPrinter printer(64);
        return printer;
    }

    void operator()(std::string const & what, bool passed) {
        std::cout << std::left << std::setw(m_width) << what << ": "
                  << (passed ? "PASS" : "** FAIL **") << '\n';
    }
private:
    TestResultPrinter(unsigned int a_width) : m_width(a_width) {}
    unsigned int m_width;
};

// This is using the cpp, the C preprocessor to expand a bit of code
// (the what argument) to a pair containing a string representation
// of it and the code itself. That way, print is given a string and a
// value where the string is the code that lead to the value
#define CHECK(...) TestResultPrinter::instance()(#__VA_ARGS__, (__VA_ARGS__))

int main() {

  // create a fraction with values 3 (which is 3/1) and 1/3
  std::cout<<std::endl;
  const Fraction three{3};
  const Fraction third{1,3};
  std::cout<<three<<' '<<third<<'\n';

  // equality
  std::cout<<std::endl;
  CHECK(three==three);
  CHECK(third==third);
  CHECK(three==Fraction{3});
  CHECK(three==Fraction{3,1});
  CHECK(third==Fraction{1,3});
  CHECK(Fraction{3}==three);
  CHECK(Fraction{1,3}==third);
  CHECK(third!=Fraction{2,6});
  CHECK(third==(Fraction{2,6}.normalized()));

  // equivalence & comparison
  std::cout<<std::endl;
  CHECK(std::is_eq(third<=>Fraction{2,6}));
  CHECK(std::is_gt(third<=>Fraction{1,4}));
  CHECK(std::is_lt(third<=>Fraction{2,4}));
  CHECK(third>Fraction{1,4});
  CHECK(third<Fraction{2,4});
  CHECK(!(third<=Fraction{1,4}));
  CHECK(!(third>=Fraction{2,4}));
  CHECK(third>=Fraction{1,4});
  CHECK(third<=Fraction{2,4});
  CHECK(third>=Fraction{1,3});
  CHECK(third<=Fraction{2,3});
  CHECK(!(third<Fraction{1,4}));
  CHECK(!(third>Fraction{2,4}));
  CHECK(!(third<Fraction{1,3}));
  CHECK(!(third>Fraction{2,3}));

  // multiply
  std::cout<<std::endl;
  CHECK((third*2)==Fraction{2,3});
  CHECK((2*third)==Fraction{2,3});
  CHECK(std::is_eq((three*third)<=>Fraction{1,1}));
  CHECK(std::is_eq((3*third)<=>Fraction{1,1}));
  CHECK((3*third).normalized()==1);

  // multiply in place
  std::cout<<std::endl;
  Fraction one {third};
  ((one *= 2) *=  3) *= Fraction{1,2};
  CHECK(std::is_eq(one<=>1));
  CHECK(one.normalized()==1);
  CHECK(one!=1);

  // end
  std::cout<<std::endl;

}
