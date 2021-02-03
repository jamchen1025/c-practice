/**********************************************************************************
給一個字串，判斷這個字串是不是接下來字串們的prefix。
char* prefix = "8591"
"8591abcdefg":T
"8888dfs1sde":F
"85919293949":T
"8591ds1fe5d3sa":T
"8558f1s1d1f1a1":F
**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int isMatchStrPrefix(const char* prefix, const char* target) {
  int len = strlen(prefix);
  int len_t = strlen(target);
  if (len > len_t) return 0;

  for (int i = 0; i < len; i++) {
    if (prefix[i] != target[i]) {
      return 0;
    }
  }
  return 1;
}


int main() {
  char* prefix = "8591";
  char* data[] = {"8591abcdefg", "8888dfs1sde", "85919293949", "8591ds1fe5d3sa",
                  "8558f1s1d1f1a1"};
  const int len = sizeof(data) / sizeof(data[0]);

  for (int i = 0; i < len; ++i) {
    printf("%s:%c\n", data[i], isMatchStrPrefix(prefix, data[i]) ? 'T' : 'F');
  }
  return 0;
}
