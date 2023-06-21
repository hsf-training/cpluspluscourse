#include <ostream>

template <typename T=float>
class Complex_t {
public:
    Complex_t() = default;

    Complex_t(T r, T i)
    : m_r(r), m_i(i) {}

    T real() const { return m_r; }

    T imaginary() const { return m_i; }

    Complex_t operator+(const Complex_t& other) const {
        return Complex_t(m_r + other.m_r, m_i + other.m_i);
    }

    Complex_t operator-(const Complex_t& other) const {
        return Complex_t(m_r - other.m_r, m_i - other.m_i);
    }

    Complex_t operator*(const Complex_t& other) const {
        return Complex_t(m_r * other.m_r - m_i * other.m_i,
            m_r * other.m_i + m_i * other.m_r);
    }

    Complex_t operator*(const T factor) const {
        return Complex_t(m_r * factor, m_i * factor);
    }

    Complex_t operator/(const T dividend) const {
        return Complex_t(m_r / dividend, m_i / dividend);
    }

    Complex_t& operator+=(const Complex_t& other) {
        m_r += other.m_r;
        m_i += other.m_i;
        return *this;
    }

    friend bool operator<(const Complex_t& a, const Complex_t& b) {
        return (a.m_r * a.m_r + a.m_i * a.m_i) < (b.m_r * b.m_r + b.m_i * b.m_i);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex_t& c) {
        return os << "(" << c.real() << ", " << c.imaginary() << ")";
    }

private:
    T m_r{}, m_i{};
};

using Complex = Complex_t<>;
