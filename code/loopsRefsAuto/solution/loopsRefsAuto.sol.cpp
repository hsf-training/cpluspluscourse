#include <cstdio>

struct DontCopyMe {
  int resultA;
  int resultB ;

  // This is material for the second day:
  DontCopyMe() = default;
  DontCopyMe(const DontCopyMe& other):
      resultA(other.resultA),
      resultB(other.resultB)
  { printf("Please don't copy me\n"); }
};

int main() {

  DontCopyMe collection[10];

  for  ( int i = 0 ; i<10 ; ++i ) {
     collection[i].resultA = i;
     collection[i].resultB = 2*i;
  }

  int resultA = 0;
  int resultB = 0;
  for (auto const & item : collection) {
     resultA += item.resultA;
     resultB += item.resultB;
  }

  printf("resultA = %d\tresultB = %d\n", resultA, resultB);

  return 0;
}
