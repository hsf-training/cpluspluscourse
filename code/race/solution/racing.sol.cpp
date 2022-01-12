#include <iostream>
#include <thread>
#include <mutex>

/*
 * This program tries to increment an integer 200 times in two threads.
 * We fix the race condition by locking a mutex before each increment.
 */

int main() {
  int nError = 0;

  for (int j = 0; j < 1000; j++) {
    int a = 0;
    std::mutex aMutex;

    // Increment the variable a 100 times:
    auto inc100 = [&a,&aMutex](){
      for (int i = 0; i < 100; ++i) {
        std::scoped_lock lock{aMutex};
        a++;
      }
    };

    // Run with two threads
    std::thread t1(inc100);
    std::thread t2(inc100);
    for (auto t : {&t1,&t2}) t->join();

    // Check
    if (a != 200) {
      std::cout << "Race: " << a << ' ';
      nError++;
    } else {
      std::cout << '.';
    }
  }
  std::cout << '\n';

  return nError;
}
