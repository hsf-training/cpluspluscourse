#include <algorithm>
#include <iostream>

void swap(int * a, int * b)
{
  int c = *a;
  *a = *b;
  *b = c;
}

void reverse(int * v, unsigned int len)
{
  for (unsigned int i = 0; i < (len + 1) / 2; i++) {
    const int a = i;
    const int b = len - i;

    swap(v + a, v + b);
  }
}

int * createAndFillVector(unsigned int len)
{
  auto v = new int[len];
  for (unsigned int i = 0; i < len; i++) {
    v[i] = i;
  }
  return v;
}

int main()
{
  constexpr auto arraySize = 100;
  int * v = nullptr;
  // create and reverse the vector of LEN numbers
  v = createAndFillVector(arraySize);
  reverse(v, arraySize);

  // check if the revert worked:
  const bool isReversed = std::is_sorted(v, v + arraySize, std::greater{});
  std::cout << "Vector reversed successfully: " << std::boolalpha
            << isReversed << "\n";

  return isReversed ? 0 : 1;
}
