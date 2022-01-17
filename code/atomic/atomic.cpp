#include <atomic>
#include <iostream>
#include <thread>

/*
 * You know this program already from "racing". It tries to increment an integer 200 times in two threads.
 * Last time, we fixed the race condition using a lock, but now we'll try atomics.
 *
 * Tasks:
 * - Replace the counter 'a' by an atomic. Run the program, and check for race conditions.
 * - Go back to 'racing', and check the execution time of the atomic vs the lock solution, e.g. using
 *   time ./atomic
 *   You might have to increase the number of tries if it completes too fast.
 */

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
