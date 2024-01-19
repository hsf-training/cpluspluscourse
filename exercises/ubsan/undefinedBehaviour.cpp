#include <iostream>
#include <limits>

// You don't need to change any code in these structs:
struct Base {
  virtual void print() = 0;
  virtual ~Base() {}
};
struct Derived1 : public Base {
  void print() override {
    std::cout << "Derived1::print()\n";
  }
};
struct Derived2 : public Base {
  void print() override {
    std::cout << "Derived2::print()\n";
  }
};


/**
 * ***************
 *  Instructions:
 * ***************
 *
 * Compile and run this program using a compiler invocation like
 * <compiler> -g -std=c++17 -o undefinedBehaviour undefinedBehaviour.cpp
 *
 * You might see warnings depending on the compiler, but on most platforms the program runs without observable issues.
 * Smart compilers will warn with most of these bugs, but the compilers can easily be deceived by hiding a nullptr in
 * a variable, or passing it as a function argument or similar.
 *
 * Since UBSan does runtime checks, it will catch these errors even if they are obscured.
 * Recompile with "-fsanitize=undefined", and observe that almost every second line contains a serious bug.
 * Try to understand what's wrong.
 */

int runTests() {
  int arr[] = {1, 2, 3, 4};
  std::cout << "arr[4]=" << arr[4] << "\n";

  unsigned short s = 1;
  std::cout << "s << 33=" << (s << 33) << "\n";

  int i = std::numeric_limits<int>::max();
  std::cout << "i + 1 =" << i + 1 << "\n";

  Derived1 d1;
  Base & base = d1;
  auto & d2 = static_cast<Derived2&>(base);
  d2.print();

  Derived2 * d2ptr = nullptr;
  Derived2 & nullref = static_cast<Derived2&>(*d2ptr);
}

int main() {
  const auto result = runTests();
  return result;
}
