/*

In the code below, replace inheritance and dynamic allocation (make_unique) with the use of a std::variant.
Multiple solutions are possible. We provide solutions using:
1. `std::get_if`,
2. `std::visit`/`std::holds_alternative`.

*/

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <span>

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

std::size_t countNeutrons(std::span<const std::unique_ptr<Particle>> ps) {
    return std::count_if(ps.begin(), ps.end(), [](const std::unique_ptr<Particle>& p){
        return typeid(*p) == typeid(Neutron);
    });
}

int main() {
  std::vector<std::unique_ptr<Particle>> ps;
  ps.push_back(std::make_unique<Electron>());
  ps.push_back(std::make_unique<Proton>());
  ps.push_back(std::make_unique<Neutron>());

  for (auto const &p : ps) {
    p->print();
  }

  std::cout << "We have " << countNeutrons(ps) << " neutrons!\n";
}
