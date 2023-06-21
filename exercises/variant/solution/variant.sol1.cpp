#include <iostream>
#include <variant>
#include <vector>

struct Electron {
  void print() const { std::cout << "E\n"; }
};

struct Proton {
  void print() const { std::cout << "P\n"; }
};

struct Neutron {
  void print() const { std::cout << "N\n"; }
};

using Particle = std::variant<Electron, Proton, Neutron>;

template <typename T> void print_if(Particle const &p) {
  // if the real type of p is not T,
  // get_if returns nullptr
  T const *ptr = std::get_if<T>(&p);
  if (ptr)
    ptr->print();
}

int main() {
  std::vector<Particle> ps = {Electron{}, Proton{}, Neutron{}};

  for (auto p : ps) {
    print_if<Electron>(p);
    print_if<Proton>(p);
    print_if<Neutron>(p);
  }
}
