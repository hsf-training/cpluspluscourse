#include <iostream>
#include <thread>

int a = 0;

void inc() {
  a++;
}

void inc100() {
  for (int i = 0; i < 100; i++)
    inc();
}

int main() {
  for (int j = 0; j < 1000; j++) {
    a = 0;
    std::thread t1(inc100);
    std::thread t2(inc100);
    for (auto t: {&t1,&t2}) t->join();
    if (a != 200) {
      std::cout << a;
    } else {
      std::cout << '.';
    }
  }
  std::cout << '\n';
}
