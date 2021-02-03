#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 30;

  // find largest bit 1, (1+2), (1+2+3), (1+2+3+4) ...
  int add = 1;
  int threshold = add;
  while (threshold < n) {
    n -= threshold;
    add++;
    threshold += add;
  }
  int largest_bit = add + 1;

  // find second bit;
  int i;
  for (i = 1; i <= largest_bit; i++) {
    if (i < n) {
      n -= i;
      continue;
    }
    break;
  }
  int second_bit = i;

  // find third bit;
  int third_bit = n - 1;

  printf("%d\n", (1 << largest_bit) + (1 << second_bit) + (1 << third_bit));
  return 0;
}
