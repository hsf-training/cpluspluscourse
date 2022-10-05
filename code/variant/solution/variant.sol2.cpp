#include <iostream>
#include <variant>
#include <vector>

struct Electron {
  void print() const { std::cout << "E" << std::endl; }
};

struct Proton {
  void print() const { std::cout << "P" << std::endl; }
};

struct Neutron {
  void print() const { std::cout << "N" << std::endl; }
};

using Particle = std::variant<Electron, Proton, Neutron>;

int main() {
  std::vector<Particle> ps = {Electron(), Proton(), Neutron()};

  for (auto const &p : ps) {
    std::visit([](const auto &p) { p.print(); }, p);
  }
}
