#include <iostream>

const unsigned int numbers[]{1000001, 1000002, 1000003, 1000004, 1000005, 1000006, 1000007, 1000008, 1000009};

bool isodd(unsigned int i) { return i % 2 == 1; }

void part1() {
  unsigned int sum_odd = 0;
  unsigned int sum_eve = 0;
  for (unsigned int num : numbers) {
    (isodd(num) ? sum_odd : sum_eve) += num;
  }
  std::cout << "Sums: odd =" << sum_odd << ", even =" << sum_eve << "\n";
}

void part2while() {
  // print smallest n for which 1 + 2 + ... + n > 10000
  int sum = 0;
  int i = 0;
  while (sum <= 10000) {
    ++i;
    sum += i;
  }
  std::cout << i << "\n";
}

void part2do() {
  // print smallest n for which 1 + 2 + ... + n > 10000
  int sum = 0;
  int i = 0;
  do {
    ++i;
    sum += i;
  } while (sum <= 10000);
  std::cout << i << "\n";
}

enum class Language { English, French, German, Italian, Japanese, Other };

void part3(Language i) {
  switch (i) {
  case Language::English:
    std::cout << "Hello\n";
    break;
  case Language::French:
    std::cout << "Salut\n";
    break;
  case Language::German:
    std::cout << "Hallo\n";
    break;
  case Language::Italian:
    std::cout << "Ciao\n";
    break;
  case Language::Japanese:
    std::cout << "Konnichiwa\n";
    break;
  default:
    std::cout << "Don't speak your language\n";
  }
}

int main() {
  part1();
  part2while();
  part2do();
  part3(Language::Japanese);
  return 0;
}
