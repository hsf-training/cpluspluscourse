#include <cassert>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <tuple>

// we start with the tuple from the slides on variadic templates

template <typename... Ts>
struct tuple {};

template <typename T, typename... Ts>
struct tuple<T, Ts...> : tuple<Ts...> {
    // exercise 1: TODO

    // exercise 2: TODO
    tuple(T head, Ts... tail) : tuple<Ts...>(tail...), m_head(head) {}

    T m_head;
};

// we need a deduction guide, because the compiler only searches the primary template for constructors
template <typename... Ts>
tuple(Ts...) -> tuple<Ts...>;

// here is a helper to get the tail of a tuple
template <typename Head, typename... Tail>
auto& tail(tuple<Head, Tail...>& t) {
    // we just cast the tuple to its base class, which holds 1 element less
    return static_cast<tuple<Tail...>&>(t);
}

// exercise 3: implement head(tuple) here

// exercise 4: implement get<I> here

// exercise 5: specialize std::tuple_size

// exercise 6: specialize std::tuple_element

// exercise 7: implement tuple_cat(tuple, tuple)
template <typename... Ts1, typename... Ts2>
auto tupleCat(tuple<Ts1...> t1, tuple<Ts2...> t2) {
    // TODO
}

// exercise 8: implement sum(tuple)
template <typename... Ts>
auto sum(tuple<Ts...>& t) {
    // TODO
}
// exercise 9: implement operator<< for tuple producing comma separated output
template <typename... Ts>
std::ostream& operator<<(std::ostream& os, tuple<Ts...>& t) {
    // TODO
    return os;
}

template <typename... Ts>
std::string toString(tuple<Ts...>& t) {
    std::stringstream ss;
    ss << std::boolalpha << t;
    return ss.str();
}

int main() {
    // tuple construction
    tuple t1{};
    tuple t2{42, 3.14f, false};

    // exercise 1: make tuple default-constructible, so the following code compiles:
    tuple<int, float> t3{};

    // exercise 2: avoid implicit construction from a single value. make the following line not compile:
    tuple t4 = 42;

    // exercise 3: write head(tuple), which returns the first element of a tuple
    static_assert(std::is_same_v<decltype(head(t2)), int&>);
    assert(head(t2) == 42);
    head(t2) = 43;
    assert(head(t2) == 43);

    // exercise 4: implement get<I>(tuple), use head() and tail() to help you
    //             'if constexpr' may help you there
    static_assert(std::is_same_v<decltype(get<0>(t2)), int&>);
    static_assert(std::is_same_v<decltype(get<1>(t2)), float&>);
    static_assert(std::is_same_v<decltype(get<2>(t2)), bool&>);
    assert(get<0>(t2) == 43);
    assert(get<1>(t2) == 3.14f);
    assert(get<2>(t2) == false);
    get<0>(t2) = 42;
    assert(get<0>(t2) == 42);

    // exercise 5: specialize std::tuple_size (used by std::tuple_size_v) for tuple
    static_assert(std::tuple_size_v<decltype(t1)> == 0);
    static_assert(std::tuple_size_v<decltype(t2)> == 3);
    static_assert(std::tuple_size_v<decltype(t3)> == 2);

    // exercise 6: specialize std::tuple_element (used by std::tuple_element_t),
    //             you can reuse your get<I>(tuple) to determine the I-th type
    //             and std::remove_reference_t to strip the reference
    static_assert(std::is_same_v<std::tuple_element_t<0, decltype(t2)>, int>);
    static_assert(std::is_same_v<std::tuple_element_t<1, decltype(t2)>, float>);
    static_assert(std::is_same_v<std::tuple_element_t<2, decltype(t2)>, bool>);

    // congratulations! structured bindings should now work for your tuple!
    auto& [i, f, b] = t2;
    assert(get<0>(t2) == 42);
    assert(get<1>(t2) == 3.14f);
    assert(get<2>(t2) == false);
    i = 1337;
    assert(get<0>(t2) == 1337);

    // exercise 7: implement a binary tuple_cat(tuple, tuple).
    //             you will likely need std::index_sequence again, but now one for each tuple.
    auto t4 = tupleCat(t2, t3);
    static_assert(std::is_same_v<decltype(t4), tuple<int, float, bool, int, float>>);
    assert(get<0>(t4) == 1337);
    assert(get<1>(t4) == 3.14f);
    assert(get<2>(t4) == false);
    assert(get<3>(t4) == 0);
    assert(get<4>(t4) == 0.0f);

    // exercise 8: implement a function sum(tuple) that will add up all elements of the tuple
    //             use a fold expression and the lambda/index_sequence pattern
    std::cout << "sum t1: " << sum(t1) << '\n';
    std::cout << "sum t2: " << sum(t2) << '\n';
    std::cout << "sum t4: " << sum(t4) << '\n';
    assert(sum(t1) == 0);
    assert(sum(t2) == 1340.14f); // false == 0
    assert(sum(t4) == 1340.14f);

    // exercise 9: make your operator<< produce exactly the following output.
    //             you may need a fold expression over the comma operator, since you need to output the ", " as well
    //             for each tuple element, except the last.
    //             use a helper function with index_sequence.
    std::cout << std::boolalpha;
    std::cout << t1 << '\n';
    std::cout << t2 << '\n';
    std::cout << t4 << '\n';
    assert(toString(t1) == "tuple{}");
    assert(toString(t2) == "tuple{1337, 3.14, false}");
    assert(toString(t4) == "tuple{1337, 3.14, false, 0, 0}");
}
