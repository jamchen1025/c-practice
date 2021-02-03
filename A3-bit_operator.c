#include <stdio.h>
#include <stdlib.h>

void ShowHex(int x) {
  char* c_ptr = (char*)&x;
  for (int i = 0; i < 4; ++i) {
    printf("%p: %02X\n", (void*)c_ptr, (unsigned char)*c_ptr++);
  }
}

void ShowHighBitIdx(int x) {
  if (x == 0) {
    printf("0\n");
    return;     // XXX
  }
  uint bit;
  asm("bsr %1, %0" : "=r"(bit) : "r"(x));
  printf("%d \n", bit);
}

void ShowLowBitIdx(int x) {
  if (x == 0) {
    printf("0\n");
    return;     // XXX
  }
  uint bit;
  asm("bsf %1, %0" : "=r"(bit) : "r"(x));
  printf("%d \n", bit);
}

void Show1BitCount(int x) {
  uint count = 0;
  while (x) {
    ++count;
    x = (x & (x - 1));
  }
  printf("%d \n", count);
}

int main() {
  ShowHex(0x1234ABCD);

  int x = 11228;
  ShowHighBitIdx(x);  // 0010 1011 1101 1100 -> 13
  ShowLowBitIdx(x);   // 0010 1011 1101 1100 -> 2
  Show1BitCount(x);   // 0010 1011 1101 1100 -> 9

  return 0;
}
