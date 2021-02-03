/**********************************************************************************
可改進：
- 考慮正負
- 判斷字串是否是合法數字
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkValid(char* c) {
  // check c is a valid number
  return 1;
}

void printNum(const char* num) {
  int len = strlen(num);
  int i = 0;
  for (; i < len && num[i] == '0'; ++i)
    ;
  while (i < len) {
    printf("%d", num[i] - '0');
    ++i;
  }
  printf("\n");
}

char* add(char* a, char* b) {
  if (checkValid(a) == 0) {
    if (checkValid(b) == 0) {
      return "0";
    } else {
      return b;
    }
  }
  if (checkValid(b) == 0) {
    return a;
  }

  int len_a = strlen(a);
  int len_b = strlen(b);
  int len_r =
      ((len_a > len_b) ? len_a : len_b) + 2;  // +1 for '\0', +1 for carry
  char* result = (char*)malloc(sizeof(char) * len_r);
  result[0] = '0';
  result[--len_r] = '\0';

  int carry = 0;
  len_a--;
  len_b--;
  len_r--;
  while (len_a >= 0 || len_b >= 0 || carry != 0) {
    int sum = 0;
    if (len_a >= 0) {
      sum += a[len_a--] - '0';
    }

    if (len_b >= 0) {
      sum += b[len_b--] - '0';
    }

    if (carry != 0) {
      sum += carry;
    }
    carry = sum / 10;
    result[len_r--] = sum % 10 + '0';
  }
  return result;
}

int main() {
  char* a = "12345";
  char* b = "1234567890";  // 1234567890, 99999
  char* r = add(a, b);     // 1234580235
  printNum(r);
  free(r);
  return 0;
}
