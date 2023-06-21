module; // start the module global partition

#include <ostream>
#include <cmath>

export module math; // declare that we intend to export a new module named 'math'

// You may export Complex_t as well, but for the exercise only the alias Complex at the bottom is neccessary
template <typename T=float>
class Complex_t {
public:
    Complex_t() = default;
    Complex_t(T r, T i) : m_r(r), m_i(i) {}

    T real() const { return m_r; }
    T imaginary() const { return m_i; }

    T norm_sqr() const {
        return m_r * m_r + m_i * m_i;
    }

    T norm() const {
        return std::sqrt(norm_sqr());
    }

    Complex_t& operator+=(const Complex_t& other) {
        m_r += other.m_r;
        m_i += other.m_i;
        return *this;
    }

    Complex_t& operator-=(const Complex_t& other) {
        m_r -= other.m_r;
        m_i -= other.m_i;
        return *this;
    }

    Complex_t& operator*=(const Complex_t& other) {
        const auto r = m_r * other.m_r - m_i * other.m_i;
        const auto i = m_r * other.m_i + m_i * other.m_r;
        m_r = r;
        m_i = i;
        return *this;
    }

    Complex_t& operator*=(T factor) {
        m_r *= factor;
        m_i *= factor;
        return *this;
    }

    Complex_t& operator/=(const Complex_t& other) {
        const T ns = other.norm_sqr();
        const auto r = (m_r * other.m_r + m_i * other.m_i) / ns;
        const auto i = (m_i * other.m_r - m_r * other.m_i) / ns;
        m_r = r;
        m_i = i;
        return *this;
    }

    Complex_t& operator/=(T divisor) {
        m_r /= divisor;
        m_i /= divisor;
        return *this;
    }

    friend Complex_t operator+(Complex_t a, const Complex_t& b) {
        return a += b;
    }

    friend Complex_t operator-(Complex_t a, const Complex_t& b) {
        return a -= b;
    }

    friend Complex_t operator*(Complex_t a, const Complex_t& b) {
        return a *= b;
    }

    friend Complex_t operator*(Complex_t c, T factor) {
        return c *= factor;
    }

    friend Complex_t operator*(T factor, Complex_t c) {
        return c *= factor;
    }

    friend Complex_t operator/(Complex_t a, Complex_t b) {
        return a /= b;
    }

    friend Complex_t operator/(Complex_t c, T divisor) {
        return c /= divisor;
    }

    friend Complex_t operator/(T dividend, const Complex_t& c) {
        return Complex_t(dividend, 0) / c;
    }

    friend bool operator==(const Complex_t& a, const Complex_t& b) {
        return a.m_r == b.m_r && a.m_i == b.m_i;
    }

    friend bool operator<(const Complex_t& a, const Complex_t& b) {
        return a.norm_sqr() < b.norm_sqr();
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex_t<T>& c) {
        return os << "(" << c.real() << ", " << c.imaginary() << ")";
    }

private:
    T m_r{}, m_i{};
};

export using Complex = Complex_t<>; // export the alias Complex
