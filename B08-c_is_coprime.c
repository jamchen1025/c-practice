#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
  int t;
  printf("%d %d\n", a, b);
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
    printf("%d %d\n", a, b);
  }
  return a;
}

int main() {
  if (gcd(109, 127) == 1)
    printf("T\n");
  else
    printf("F\n");
  return 0;
}
