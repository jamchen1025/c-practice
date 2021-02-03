#include <stdio.h>
#include <stdlib.h>

void printBits(const size_t size, const void *const ptr) {
  unsigned char *b = (unsigned char *)ptr;
  for (int i = size - 1; i >= 0; i--) {
    for (int j = 7; j >= 0; j--) {
      unsigned char byte = (b[i] >> j) & 1;
      printf("%u", byte);
    }
  }
}

int main() {
  int x = -5;
  printBits(sizeof(int), &x);
  printf("\n");
  char c = 1;
  printBits(sizeof(char), &c);
  printf("\n");
  return 0;
}
