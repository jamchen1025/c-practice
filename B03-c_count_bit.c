#include <stdio.h>
#include <stdlib.h>

int countBit(int x) {
  int count = 0;
  while (x) {
    count++;
    x = x & x - 1;
  }
  return count;
}

int main() {
  printf("%d\n", countBit(0b11111111));  // 8
  return 0;
}
