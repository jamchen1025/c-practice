/**********************************************************************************
考char *s1 = "XXX"; 是字串常數的觀念，不可修改裡面的值
**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* c) {
  for (int i = 0, j = strlen(c) - 1; i < j; i++, j--) {
    c[i] = c[i] ^ c[j];
    c[j] = c[i] ^ c[j];
    c[i] = c[i] ^ c[j];
  }
}

int main(void) {
  // char *s1 = "ABCDEFG";
  char s1[] = "ABCDEFG";
  printf("%s\n", s1);
  reverse(s1);
  printf("%s\n", s1);
  return 0;
}