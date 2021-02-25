#include <ostream>
#include <assert.h>
#include <algorithm>
#include <numeric>

template <int N, typename T=float>
class NVector {
public:
    typedef T BaseType;

    NVector();
    NVector(T initialValue, T inc);
    NVector(const NVector &other);
    ~NVector();

    NVector& operator-() const;
    NVector& operator+(const NVector other) const;
    NVector& operator-(const NVector other) const;
    NVector& operator*(const NVector other) const;
    NVector& operator*(const T factor) const;
    NVector& operator/(const T dividend) const;
    NVector& operator=(const NVector other);
    NVector& operator+=(const NVector other);
    T sqnorm() const;
    bool operator<(const NVector a) const;

    void print(std::ostream& os) const;
private:
    T *m_data;
};

template <int N, typename T>
NVector<N,T>::NVector() {
    m_data = new T[N];
}

template <int N, typename T>
NVector<N,T>::NVector(T initialValue, T inc) :
    NVector() {
    T curValue = initialValue;
    std::generate(m_data, m_data+N,
                  [&curValue, inc]() { T cur = curValue;
                                       curValue += inc;
                                       return cur;});
}

template <int N, typename T>
NVector<N,T>::NVector(const NVector<N,T>& other) {
    m_data = new T[N];
    std::copy(other.m_data, other.m_data+N, m_data);
}

template <int N, typename T>
NVector<N,T>::~NVector() {
    if (m_data) delete[](m_data);
}

template <int N, typename T>
NVector<N,T>& NVector<N,T>::operator-() const {
    NVector res;
    std::transform(m_data, m_data+N, res.m_data,
                   [](T a) {return -a;});
    return res;
}

template <int N, typename T>
NVector<N,T>& NVector<N,T>::operator+(const NVector<N,T> other) const {
    NVector res;
    std::transform(m_data, m_data+N,
                   other.m_data, res.m_data,
                   [](T a, T b) {return a + b;});
    return res;
}

template <int N, typename T>
NVector<N,T>& NVector<N,T>::operator-(const NVector<N,T> other) const {
    NVector res;
    std::transform(m_data, m_data+N,
                   other.m_data, res.m_data,
                   [](T a, T b) {return a - b;});
    return res;
}

template <int N, typename T>
NVector<N,T>& NVector<N,T>::operator*(const T factor) const {
    NVector res;
    std::transform(m_data, m_data+N, res.m_dat,
                   [factor](T a) {return a * factor;});
    return res;
}

template <int N, typename T>
NVector<N,T>& NVector<N,T>::operator/(const T dividend) const {
    NVector res;
    std::transform(m_data, m_data+N, res.m_data,
                   [dividend](T a) {return a / dividend;});
    return res;
}

template <int N, typename T>
NVector<N,T>& NVector<N,T>::operator=(const NVector<N,T> other) {
    if (m_data) delete[](m_data);
    m_data = new T[N];
    std::copy(other.m_data, other.m_data+N, m_data);
    return *this;
}

template <int N, typename T>
NVector<N,T>& NVector<N,T>::operator+=(const NVector<N,T> other) {
    std::transform(m_data, m_data+N,
                   other.m_data, m_data,
                   [](T a, T b) {return a + b;});
    return *this;
}

template <int N, typename T>
T NVector<N,T>::sqnorm() const {
    return std::inner_product(m_data, m_data + N, m_data, T());
}

template <int N, typename T>
bool NVector<N,T>::operator<(const NVector<N,T> other) const {
    return this->sqnorm() < other.sqnorm();
}

template <int N, typename T>
void NVector<N,T>::print(std::ostream& os) const {
    std::for_each(m_data, m_data+N, [&os](T a) { os << a << ", ";});
}

template <int N, typename T>
std::ostream& operator<<(std::ostream& os,
                         const NVector<N,T>& c) {
    os << "(";
    c.print(os);
    os << ")";
    return os;
}
