#include <ostream>

template <class T=float>
class Complex_t {
public:
    Complex_t(T r, T i);
    Complex_t();

    T real() const {return m_r;};
    T imaginary() const {return m_i;};

    Complex_t operator+(const Complex_t& other) const;
    Complex_t operator-(const Complex_t& other) const;
    Complex_t operator*(const Complex_t& other) const;
    Complex_t operator*(const T factor) const;
    Complex_t operator/(const T dividend) const;
    Complex_t& operator+=(const Complex_t& other);
    bool operator<(const Complex_t& a) const;
private:
  T m_r{}, m_i{};
};

typedef Complex_t<> Complex;

template <class T>
Complex_t<T>::Complex_t() {}

template <class T>
Complex_t<T>::Complex_t(T r, T i) : m_r(r), m_i(i) {}

template <class T>
Complex_t<T> Complex_t<T>::operator+(const Complex_t<T>& other) const {
    return Complex_t(m_r + other.m_r, m_i + other.m_i);
}

template <class T>
Complex_t<T> Complex_t<T>::operator-(const Complex_t<T>& other) const {
    return Complex_t(m_r - other.m_r, m_i - other.m_i);
}

template <class T>
Complex_t<T> Complex_t<T>::operator*(const Complex_t<T>& other) const {
    return Complex_t(m_r*other.m_r - m_i*other.m_i,
                     m_r*other.m_i + m_i*other.m_r);
}

template <class T>
Complex_t<T> Complex_t<T>::operator*(const T factor) const {
    return Complex_t(m_r*factor, m_i*factor);
}

template <class T>
Complex_t<T> Complex_t<T>::operator/(const T dividend) const {
    return Complex_t(m_r/dividend, m_i/dividend);
}

template <class T>
Complex_t<T>& Complex_t<T>::operator+=(const Complex_t<T>& other) {
    m_r += other.m_r;
    m_i += other.m_i;
    return *this;
}

template <class T>
bool Complex_t<T>::operator<(const Complex_t<T>& other) const {
    return (m_r*m_r+m_i*m_i) < (other.m_r*other.m_r+other.m_i*other.m_i);
}

template <class T>
std::ostream& operator<<(std::ostream& os,
                         const Complex_t<T>& c) {
    os << "(" << c.real() << ", " << c.imaginary() << ")";
    return os;
}
