#include <iostream>

constexpr int numbers[]{1, 2, 3, 4, 5, 6, 7, 8, 9};

bool isodd(int i) { return i % 2 == 1; }

void part1() {
  int sum_odd = 0;
  int sum_eve = 0;
  for (int num : numbers) {
    (isodd(num) ? sum_odd : sum_eve) += num;
  }
  std::cout << "Sums: odd = " << sum_odd << ", even = " << sum_eve << "\n";
}

void part2() {
  // print smallest n for which 1 + 2 + ... + n > 10000
  int sum = 0;
  int i = 0;
  while (sum < 10000) {
    ++i;
    sum += i;
  }
  std::cout << i << "\n";
}

void part2bis() {
  // print smallest n for which 1 + 2 + ... + n > 10000
  int sum = 0;
  int i = 0;
  do {
    ++i;
    sum += i;
  } while (sum < 10000);
  std::cout << i << "\n";
}

enum class Language { English, French, German, Italian, Other };

void part3(Language l) {
  switch (l) {
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
  default:
    std::cout << "Don't speak your language\n";
  }
}

int main() {
  part1();
  part2();
  part2bis();
  part3(Language::English);
  return 0;
}
