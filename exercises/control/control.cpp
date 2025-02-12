#include <iostream>

const unsigned int numbers[]{1000001, 1000002, 1000003, 1000004, 1000005, 1000006, 1000007, 1000008, 1000009};

bool isodd(unsigned int i) { return i % 2 == 1; }

void part1() {
  unsigned int sum_odd = 0;
  unsigned int sum_eve = 0;

  // Using range-based for loop
  for (unsigned int num : numbers) {
    // Using conditional (ternary) operator
    isodd(num) ? sum_odd += num : sum_eve += num;
  }

  std::cout << "Sums: odd = " << sum_odd << ", even = " << sum_eve << "\n";
}

void part2_while() {
  int sum = 0;
  int i = 1;

  while (sum <= 10000) {
    sum += i;
    if (sum > 10000) {
      std::cout << i << "\n";
      break;
    }
    i++;
  }
}

void part2_do_while() {
  int sum = 0;
  int i = 1;

  do {
    sum += i;
    if (sum > 10000) {
      std::cout << i << "\n";
      break;
    }
    i++;
  } while (true);
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
      std::cout << "I don't speak your language\n";
    break;
  }
}

int main() {
  part1();
  part2_while();
  part2_do_while();
  part3(Language::English);
  return 0;
}
