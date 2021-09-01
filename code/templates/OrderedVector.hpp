#include <stdlib.h>
#include <stdexcept>

template<class ElementType>
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
    ElementType* m_data;
};

template<class ElementType>
OrderedVector<ElementType>::~OrderedVector() {
    delete[](m_data);
}

template<class ElementType>
OrderedVector<ElementType>::OrderedVector(unsigned int maxLen) :
m_len(0), m_maxLen(maxLen) {
    m_data = new ElementType[m_maxLen];
}

template<class ElementType>
bool OrderedVector<ElementType>::add(ElementType value) {
    if (m_len >= m_maxLen) {
        return false;
    }
    // find insertion point
    unsigned int insertIndex = 0;
    while (insertIndex < m_len && m_data[insertIndex] < value)
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

template<class ElementType>
ElementType& OrderedVector<ElementType>::get(unsigned int n) {
    if (n >= m_len) {
        throw std::out_of_range("too big");
    }
    return m_data[n];
}

template<class ElementType>
ElementType& OrderedVector<ElementType>::operator[](unsigned int n) {
    return get(n);
}
