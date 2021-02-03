#include <stdio.h>
#include <stdlib.h>

size_t my_strlen(const char* str) {
  size_t l = 0;
  while (str[l] != '\0') {
    ++l;
  }
  return l;
}

int main() {
  char* str = "1234567";
  printf("%d\n", my_strlen(str));
  return 0;
}
