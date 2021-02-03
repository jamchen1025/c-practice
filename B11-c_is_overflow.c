/**********************************************************************************
判斷兩個int相加是否溢位(不能用long幫忙)
**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int isOverflow(int a, int b) {
  printf("%d %d: ", a, b);
  if (a > 0 && b > 0 && (a + b) < 0) return 1;
  if (a < 0 && b < 0 && (a + b) > 0) return 1;
  return 0;
}

int main() {
  int a, b;
  a = 0b01111111111111111111111111111111;
  b = 0b01111111111111111111111111111111;
  printf("%d\n", isOverflow(a, b));
  printf("%d\n", isOverflow(2, 5));
  printf("%d\n", isOverflow(-2, 5));
  printf("%d\n", isOverflow(-2, -5));
  a = 0b01111111111111111111111111111111;
  b = 0b01111111111111111111111111111111;
  printf("%d\n", isOverflow(-a, -b));
  return 0;
}
