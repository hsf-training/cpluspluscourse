#include <iostream>
#include <thread>
#include <vector>

/*
 * This program tries to increment an integer 100 times from multiple threads.
 * If the result comes out at 100*nThread, it stays silent, but it will print
 * an error if a race condition is detected.
 * If you don't see it racing, try ./run ./racing, which keeps invoking the
 * executable until a race condition is detected.
 */

constexpr unsigned int nThread = 2;

int main() {
  int nError = 0;

  for (int j = 0; j < 1000; j++) {
    int a = 0;

    // Increment the variable a 100 times:
    auto inc100 = [&a](){
      for (int i = 0; i < 100; ++i) {
        a++;
      }
    };

    // Start up all threads:
    std::vector<std::thread> threads;
    for (unsigned int i = 0; i < nThread; ++i) threads.emplace_back(inc100);
    for (auto & thread : threads) thread.join();

    // Check
    if (a != nThread * 100) {
      std::cerr << "Race detected! Result: " << a << '\n';
      nError++;
    }
  }

  return nError;
}
