#include <stdlib.h>
#include <stdexcept>

template <typename T>
struct less {
  bool operator() (const T& x, const T& y) const {return x<y;}
};

template<typename ElementType, typename Compare=less<ElementType> >
class OrderedVector {
public:
    OrderedVector(unsigned int maxLen);
    ~OrderedVector();
    OrderedVector(const OrderedVector&) = delete;
    OrderedVector& operator=(const OrderedVector&) = delete;
    bool add(ElementType value);
    ElementType& get(unsigned int n);
    ElementType& operator[](unsigned int n);
private:
    unsigned int m_len;
    unsigned int m_maxLen;
    Compare m_compare;
    ElementType* m_data;
};
    
template<typename ElementType, typename Compare>
OrderedVector<ElementType,Compare>::~OrderedVector() {
    delete[](m_data);
}

template<typename ElementType, typename Compare>
OrderedVector<ElementType,Compare>::OrderedVector(unsigned int maxLen) :
m_len(0), m_maxLen(maxLen), m_compare() {
    m_data = new ElementType[m_maxLen];
}

template<typename ElementType, typename Compare>
bool OrderedVector<ElementType,Compare>::add(ElementType value) {
    if (m_len >= m_maxLen) {
        return false;
    }
    // find insertion point
    unsigned int insertIndex = 0;
    while (insertIndex < m_len && m_compare(m_data[insertIndex], value))
        insertIndex++;
    // move end of vector
    unsigned int index = m_len;
    while (index > insertIndex) {
        m_data[index] = m_data[index-1];
            index--;
    }
    // actual insertion
    m_data[index] = value;
    m_len++;
    return true;
}

template<typename ElementType, typename Compare>
ElementType& OrderedVector<ElementType,Compare>::get(unsigned int n) {
    if (n >= m_len) {
        throw std::out_of_range("too big");
    }
    return m_data[n];
}

template<typename ElementType, typename Compare>
ElementType& OrderedVector<ElementType,Compare>::operator[](unsigned int n) {
    return get(n);
}
