
#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

constexpr std::size_t nThread = 10;
constexpr std::size_t nInc = 1000;
constexpr std::size_t nRepeat = 1000;

int main() {
  int nError = 0;

  for (std::size_t j = 0; j < nRepeat; j++) {
    std::atomic<int> a{0};

    // Increment the variable a 100 times:
    auto increment = [&a](){
      for (std::size_t i = 0; i < nInc; ++i) {
        a++;
      }
    };

    // Start up all threads
    std::vector<std::thread> threads;
    for (std::size_t i = 0; i < nThread; ++i) threads.emplace_back(increment);
    for (auto & thread : threads) thread.join();

    // Check
    if (a != nThread * nInc) {
      std::cerr << "Race detected! Result: " << a << '\n';
      nError++;
    }
  }

  return nError;
}
