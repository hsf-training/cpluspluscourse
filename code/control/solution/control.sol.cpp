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

  // range based loop
  sum_odd = 0;
  sum_eve = 0;
  for (int i : numbers) {
    if (isodd(i)) {
      sum_odd += i;
    } else {
      sum_eve += i;
    }
  }
  printf("Sums: odd = %d, even = %d\n", sum_odd, sum_eve);

  // conditional operator
  sum_odd = 0;
  sum_eve = 0;
  for (int i : numbers) {
    isodd(i) ? sum_odd += i : sum_eve += i;
  }
  printf("Sums: odd = %d, even = %d\n", sum_odd, sum_eve);

  // switch statement
  sum_odd = 0;
  sum_eve = 0;
  for (int i : numbers) {
    switch (isodd(i)) {
    case 1:
      sum_odd += i;
      break;
    case 0:
      sum_eve += i;
      break;
    }
  }
  printf("Sums: odd = %d, even = %d\n", sum_odd, sum_eve);

  // while loop
  sum_odd = 0;
  sum_eve = 0;
  int i = 0;
  while (i < nnums) {
    int num = numbers[i++];
    isodd(num) ? sum_odd += num : sum_eve += num;
  }
  printf("Sums: odd = %d, even = %d\n", sum_odd, sum_eve);

  // do while loop
  sum_odd = 0;
  sum_eve = 0;
  i = 0;
  do {
    int num = numbers[i++];
    isodd(num) ? sum_odd += num : sum_eve += num;
  } while (i < nnums);
  printf("Sums: odd = %d, even = %d\n", sum_odd, sum_eve);
}
