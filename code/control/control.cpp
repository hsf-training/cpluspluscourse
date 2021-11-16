#include <cstdio>

int isodd(int i) { return i % 2; }

int main() {

  int const nnums = 9;
  int numbers[nnums] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  int sum_odd = 0;
  int sum_eve = 0;
  for (int i = 0; i < nnums; ++i) {
    int num = numbers[i];
    if (isodd(num)) {
      sum_odd += num;
    } else {
      sum_eve += num;
    }
  }
  printf("Sums: odd = %d, even = %d\n", sum_odd, sum_eve);
}
