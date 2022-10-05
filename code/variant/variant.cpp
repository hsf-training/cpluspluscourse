/*

In the code below, replace inheritance with the use of a std::variant.
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

struct Electron : public Particle {
  virtual void print() const { std::cout << "E" << std::endl; }
};

struct Proton : public Particle {
  virtual void print() const { std::cout << "P" << std::endl; }
};

struct Neutron : public Particle {
  virtual void print() const { std::cout << "N" << std::endl; }
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
