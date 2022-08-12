#include "OrderedVector.sol.hpp"
#include "Complex.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

struct RevOrderString {
    bool operator() (const std::string &s, const std::string &t) const {
        std::string rs = s;
        std::string rt = t;
        std::reverse(rs.begin(), rs.end());
        std::reverse(rt.begin(), rt.end());
        return rs < rt;
    }
};

struct ManhattanOrder {
    bool operator() (const Complex &a, const Complex &b) const {
        return std::abs(a.real()) + std::abs(a.imaginary()) < std::abs(b.real()) + std::abs(b.imaginary());
    }
};

int main() {
    std::cout << "Integer\n";
    OrderedVector<int> v(10);
    for (int i = 10; i > 0; i--)
        v.add(i);
    for (int i = 0; i < 10; i++)
        std::cout << v[i] << " ";
    std::cout << "\n\n";

    std::cout << "String\n";
    OrderedVector<std::string> vs(5);
    vs.add(std::string("one"));
    vs.add(std::string("two"));
    vs.add(std::string("three"));
    vs.add(std::string("four"));
    vs.add(std::string("five"));
    for (int i = 0; i < 5; i++)
        std::cout << vs[i] << " ";
    std::cout << "\n\n";

    std::cout << "Complex\n";
    OrderedVector<Complex> vc(5);
    vc.add(Complex(1.5,0.0));
    vc.add(Complex(1.0,1.0));
    vc.add(Complex(-1.0,0.0));
    vc.add(Complex(1.0,2.0));
    vc.add(Complex(0.0,0.0));
    for (int i = 0; i < 5; i++)
        std::cout << vc[i] << " ";
    std::cout << "\n\n";

    std::cout << "String\n";
    OrderedVector<std::string, RevOrderString> vsr(5);
    vsr.add(std::string("one"));
    vsr.add(std::string("two"));
    vsr.add(std::string("three"));
    vsr.add(std::string("four"));
    vsr.add(std::string("five"));
    for (int i = 0; i < 5; i++)
        std::cout << vsr[i] << " ";
    std::cout << "\n\n";

    std::cout << "Complex with manhatan order\n";
    OrderedVector<Complex, ManhattanOrder> vcm(5);
    vcm.add(Complex(1.5,0.0));
    vcm.add(Complex(1.0,1.0));
    vcm.add(Complex(-1.0,0.0));
    vcm.add(Complex(1.0,2.0));
    vcm.add(Complex(0.0,0.0));
    for (int i = 0; i < 5; i++)
        std::cout << vcm[i] << " ";
    std::cout << "\n\n";

    std::cout << "Int Complex\n";
    using IComplex = Complex_t<int>;
    OrderedVector<IComplex> vci(5);
    vci.add(IComplex(2,0));
    vci.add(IComplex(1,1));
    vci.add(IComplex(-1,0));
    vci.add(IComplex(1,2));
    vci.add(IComplex(0,0));
    for (int i = 0; i < 5; i++)
        std::cout << vci[i] << " ";
    std::cout << "\n\n";

    std::cout << "Very Complex\n";
    using VComplex = Complex_t<Complex>;
    OrderedVector<VComplex> vcv(5);
    vcv.add(VComplex(Complex(2,0),Complex(1,0)));
    vcv.add(VComplex(Complex(2,0),Complex(0,2)));
    vcv.add(VComplex(Complex(1,0),Complex(0,0)));
    vcv.add(VComplex(Complex(0,1),Complex(1,0)));
    vcv.add(VComplex(Complex(2,0),Complex(0,0)));
    for (int i = 0; i < 5; i++)
        std::cout << vcv[i] << " ";
    std::cout << "\n\n";

}
