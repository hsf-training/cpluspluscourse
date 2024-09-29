
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

int main() {
  std::vector<Particle> ps = {Electron{}, Proton{}, Neutron{}};

  for (auto const &p : ps) {
    // With "auto" as argument, we provide a generic lambda. The compiler
    // will instantiate it for all the types that the variant can hold, and at run
    // time, the correct overload will be chosen automatically:
    std::visit([](const auto &p) { p.print(); }, p);
  }
}
