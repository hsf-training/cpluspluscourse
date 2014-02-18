#include <ostream>
#include <assert.h>

template <class T=float>
class NVector_t {
    NVector_t(unsigned int dimension);
public:
    typedef T BaseType;

    NVector_t();
    NVector_t(unsigned int dimension, T initialValue, T inc);
    NVector_t(const NVector_t &other);
    NVector_t(NVector_t &&other) : NVector_t() { swap(*this, other); };
    ~NVector_t();

    NVector_t operator-() const;
    NVector_t operator+(const NVector_t& other) const;
    NVector_t operator-(const NVector_t& other) const;
    NVector_t operator*(const NVector_t& other) const;
    NVector_t operator*(const T factor) const;
    NVector_t operator/(const T dividend) const;
    NVector_t& operator=(NVector_t other);
    NVector_t& operator+=(const NVector_t& other);
    T sqnorm() const;
    bool operator<(const NVector_t& a) const;

    void print(std::ostream& os) const;
    template<class R> friend void swap(NVector_t<R> &a, NVector_t<R> &b);
private:
    unsigned int m_dimension;
    T *m_data;
};

typedef NVector_t<> NVector;

template <class T>
NVector_t<T>::NVector_t() :
    m_dimension(0), m_data(0) {
}

template <class T>
NVector_t<T>::NVector_t(unsigned int dimension) :
    m_dimension(dimension) {
    m_data = new T[dimension];
}

template <class T>
NVector_t<T>::NVector_t(unsigned int dimension, T initialValue, T inc) :
    NVector_t(dimension) {
    T curValue = initialValue;
    std::generate(m_data, m_data+m_dimension,
                  [&curValue, inc]() { T cur = curValue;
                                       curValue += inc;
                                       return cur;});
}

template <class T>
NVector_t<T>::NVector_t(const NVector_t<T>& other) {
    m_dimension = other.m_dimension;
    m_data = new T[m_dimension];
    std::copy(other.m_data, other.m_data+other.m_dimension, m_data);
}

template <class T>
NVector_t<T>::~NVector_t() {
    if (m_data) delete[](m_data);
}

template <class T>
NVector_t<T> NVector_t<T>::operator-() const {
    assert(m_dimension > 0);
    NVector_t res(m_dimension);
    std::transform(m_data, m_data+m_dimension, res.m_data,
                   [](T a) {return -a;});
    return res;
}

template <class T>
NVector_t<T> NVector_t<T>::operator+(const NVector_t<T>& other) const {
    assert((m_dimension == other.m_dimension && m_dimension > 0) || 0 == m_dimension);
    if (0 == m_dimension) {
        return NVector_t(other);
    }
    NVector_t res(other.m_dimension);
    std::transform(m_data, m_data+m_dimension,
                   other.m_data, res.m_data,
                   [](T a, T b) {return a + b;});
    return res;
}

template <class T>
NVector_t<T> NVector_t<T>::operator-(const NVector_t<T>& other) const {
    assert((m_dimension == other.m_dimension && m_dimension > 0) || 0 == m_dimension);
    if (0 == m_dimension) {
        return -NVector_t(other);
    }
    NVector_t res(m_dimension);
    std::transform(m_data, m_data+m_dimension,
                   other.m_data, res.m_data,
                   [](T a, T b) {return a - b;});
    return res;
}

template <class T>
NVector_t<T> NVector_t<T>::operator*(const T factor) const {
    assert(m_dimension > 0);
    NVector_t res(m_dimension);
    std::transform(m_data, m_data+m_dimension, res.m_dat,
                   [factor](T a) {return a * factor;});
    return res;
}

template <class T>
NVector_t<T> NVector_t<T>::operator/(const T dividend) const {
    assert(m_dimension > 0);
    NVector_t res(m_dimension);
    std::transform(m_data, m_data+m_dimension, res.m_data,
                   [dividend](T a) {return a / dividend;});
    return res;
}

template <class T>
NVector_t<T>& NVector_t<T>::operator=(NVector_t<T> other) {
    swap(*this, other);
    return *this;
}

template <class T>
NVector_t<T>& NVector_t<T>::operator+=(const NVector_t<T>& other) {
    assert(m_dimension == other.m_dimension || 0 == m_dimension);
    if (0 == m_dimension) {
        m_dimension = other.m_dimension;
        m_data = new T[m_dimension];
        std::copy(other.m_data, other.m_data+other.m_dimension, m_data);
        return *this;
    }
    std::transform(m_data, m_data+m_dimension,
                   other.m_data, m_data,
                   [](T a, T b) {return a + b;});
    return *this;
}

template <class T>
T NVector_t<T>::sqnorm() const {
    assert(m_dimension > 0);
    T norm;
    std::for_each(m_data, m_data+m_dimension,
                  [&norm](T a) { norm += a*a; });
    return norm;
}

template <class T>
bool NVector_t<T>::operator<(const NVector_t<T>& other) const {
    assert(m_dimension == other.m_dimension);
    return this->sqnorm() < other.sqnorm();
}

template <class T>
void NVector_t<T>::print(std::ostream& os) const {
    assert(m_dimension > 0);
    std::for_each(m_data, m_data+m_dimension, [&os](T a) { os << a << ", ";});
}

template <class T>
std::ostream& operator<<(std::ostream& os,
                         const NVector_t<T>& c) {
    os << "(";
    c.print(os);
    os << ")";
    return os;
}

template <class T>
void swap(NVector_t<T> &a, NVector_t<T> &b) {
    unsigned int c_dimension = a.m_dimension;
    T* c_data = a.m_data;
    a.m_dimension = b.m_dimension;
    a.m_data = b.m_data;
    b.m_dimension = c_dimension;
    b.m_data = c_data;
}
