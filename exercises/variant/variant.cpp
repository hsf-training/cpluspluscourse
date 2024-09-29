/*

In the code below, replace inheritance with the use of a `std::variant<Electron, Proton, Neutron>`.
There is no more need for a base class, and no more need pointers.
Two solutions are provided :
1. with `std::get_if`,
2. with `std::visit`.

*/

#include <iostream>
#include <memory>
#include <vector>

struct Particle {
  virtual void print() const = 0;
  virtual ~Particle() = default;
};

struct Electron : Particle {
  void print() const override { std::cout << "E\n"; }
};

struct Proton : Particle {
  void print() const override { std::cout << "P\n"; }
};

struct Neutron : Particle {
  void print() const override { std::cout << "N\n"; }
};

int main() {
  std::vector<std::unique_ptr<Particle>> ps;
  ps.push_back(std::make_unique<Electron>());
  ps.push_back(std::make_unique<Proton>());
  ps.push_back(std::make_unique<Neutron>());

  for (auto const &p : ps) {
    p->print();
  }
}
