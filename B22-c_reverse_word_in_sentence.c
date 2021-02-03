#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char* s = "I am a boy";
  printf("%s\n", s);

  int len = strlen(s);

  char* sr = (char*)malloc(sizeof(char) * len + 1);
  sr[len] = '\0';
  int idx = 0;

  for (int i = len - 1; i >= 0; i--) {
    if (s[i] == ' ') {
      for (int j = i + 1; j < len; j++) {
        sr[idx++] = s[j];
      }
      sr[idx++] = s[i];
      len = i;
    }

    if (i == 0) {
      for (int j = i; j < len; j++) {
        sr[idx++] = s[j];
      }
    }
  }
  printf("%s\n", sr);
  free(sr);
  return 0;
}
