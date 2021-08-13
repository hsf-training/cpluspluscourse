template <typename T=float>
class Complex_t {
public:
    Complex_t(T r, T i);
    Complex_t(T r);
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
    T m_r, m_i;
};

typedef Complex_t<> Complex;

template <typename T>
Complex_t<T>::Complex_t() {}

template <typename T>
Complex_t<T>::Complex_t(T r) : m_r(r), m_i(0) {}

template <typename T>
Complex_t<T>::Complex_t(T r, T i) : m_r(r), m_i(i) {}

template <typename T>
Complex_t<T> Complex_t<T>::operator+(const Complex_t<T>& other) const {
    return Complex_t(m_r + other.m_r, m_i + other.m_i);
}

template <typename T>
Complex_t<T> Complex_t<T>::operator-(const Complex_t<T>& other) const {
    return Complex_t(m_r - other.m_r, m_i - other.m_i);
}

template <typename T>
Complex_t<T> Complex_t<T>::operator*(const Complex_t<T>& other) const {
    return Complex_t(m_r*other.m_r - m_i*other.m_i,
                     m_r*other.m_i + m_i*other.m_r);
}

template <typename T>
Complex_t<T> Complex_t<T>::operator*(const T factor) const {
    return Complex_t(m_r*factor, m_i*factor);
}

template <typename T>
Complex_t<T> Complex_t<T>::operator/(const T dividend) const {
    return Complex_t(m_r/dividend, m_i/dividend);
}

template <typename T>
Complex_t<T>& Complex_t<T>::operator+=(const Complex_t<T>& other) {
    m_r += other.m_r;
    m_i += other.m_i;
    return *this;
}

template <typename T>
bool Complex_t<T>::operator<(const Complex_t<T>& other) const {
    return (m_r*m_r+m_i*m_i) < (other.m_r*other.m_r+other.m_i*other.m_i);
}
