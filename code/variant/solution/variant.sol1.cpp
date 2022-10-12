#include <iostream>
#include <variant>
#include <vector>
#include <algorithm>
#include <span>

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

std::size_t countNeutrons(std::span<const Particle> ps) {
    return std::count_if(ps.begin(), ps.end(), [](const Particle& p){
        return std::get_if<Neutron>(&p) != nullptr;
    });
}

int main() {
  std::vector<Particle> ps = {Electron{}, Proton{}, Neutron{}};

  for (auto p : ps) {
    print_if<Electron>(p);
    print_if<Proton>(p);
    print_if<Neutron>(p);
  }

  std::cout << "We have " << countNeutrons(ps) << " neutrons!\n";
}
