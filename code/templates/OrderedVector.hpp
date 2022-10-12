#include <memory>
#include <stdexcept>

template<typename ElementType>
class OrderedVector {
public:
    OrderedVector(unsigned int maxLen);
    OrderedVector(const OrderedVector&) = delete;
    OrderedVector& operator=(const OrderedVector&) = delete;
    bool add(ElementType value);
    ElementType& at(unsigned int n);
    ElementType& operator[](unsigned int n);
private:
    unsigned int m_len;
    unsigned int m_maxLen;
    std::unique_ptr<ElementType[]> m_data;
};

template<typename ElementType>
OrderedVector<ElementType>::OrderedVector(unsigned int maxLen) :
m_len(0), m_maxLen(maxLen), m_data(std::make_unique<ElementType[]>(m_maxLen)) { }

template<typename ElementType>
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

template<typename ElementType>
ElementType& OrderedVector<ElementType>::at(unsigned int n) {
    if (n >= m_len) {
        throw std::out_of_range("too big");
    }
    return m_data[n];
}

template<typename ElementType>
ElementType& OrderedVector<ElementType>::operator[](unsigned int n) {
    return at(n);
}
