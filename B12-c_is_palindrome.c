#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isCharValid(char c) {
  if ('0' <= c && c <= '9') return 1;
  if ('a' <= c && c <= 'z') return 1;
  if ('A' <= c && c <= 'Z') return 1;
  return 0;
}

char toLowerCase(char c) {
  if ('A' <= c && c <= 'Z') {
    return c - 'A' + 'a';
  }
  return c;
}

int isPalindrome(char* a) {
  int len = strlen(a);
  if (len < 2) return 1;

  int low = 0;
  int high = len - 1;
  while (low < high) {
    while (low < high && isCharValid(a[low]) == 0) low++;
    while (low < high && isCharValid(a[high]) == 0) high--;

    if (toLowerCase(a[low++]) != toLowerCase(a[high--])) {
      return 0;
    }
  }
  return 1;
}

int main() {
  char* data[] = {"saddas",
                  "sadidas",
                  "sadjas",
                  "sadijas",
                  "A man, a plan, a canal, Panama.",
                  ".,,,"};
  const int len = sizeof(data) / sizeof(data[0]);
  for (int i = 0; i < len; ++i) {
    printf("Is it palindrome ? %s: %s\n", data[i],
           isPalindrome(data[i]) ? "true" : "false");
  }
  return 0;
}
