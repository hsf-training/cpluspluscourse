#include <iostream>

constexpr int numbers[]{1, 2, 3, 4, 5, 6, 7, 8, 9};

bool isodd(int i) { return i % 2; }

void part1() {
  int sum_odd = 0;
  int sum_eve = 0;
  for (int i = 0; i < 9; ++i) {
    int num = numbers[i];
    if (isodd(num)) {
      sum_odd += num;
    } else {
      sum_eve += num;
    }
  }
  std::cout << "Sums: odd = " << sum_odd << ", even = " << sum_eve << "\n";
}

enum class Language { English, French, German, Italian, Other };

void part2() {
  // print smallest n for which 1 + 2 + ... + n > 10000
  int sum = 0;
  for (int i = 1; ; i++) {
    sum += i;
    if (sum > 10000) {
      std::cout << i << "\n";
      break;
    }
  }
}

void part3(Language l) {
  if (l == Language::English) {
    std::cout << "Hello\n";
  } else if (l == Language::French) {
    std::cout << "Salut\n";
  } else if (l == Language::German) {
    std::cout << "Hallo\n";
  } else if (l == Language::Italian) {
    std::cout << "Ciao\n";
  } else {
    std::cout << "Don't speak your language\n";
  }
}

int main() {
  part1();
  part2();
  part3(Language::English);
  return 0;
}
