/**********************************************************************************
給你一個8-bit的整數數列，要你找出這串數列的連續最長的1bit的長度和他的起始位置
255=11111111 -> 8個連續的1bit
119=01110111 -> 3個連續的1bit
247=11110111 -> 4個連續的1bit
**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
const int len = 8;

void maxSubBitSequence(int num) {
  int* dp_len = (int*)malloc(len * sizeof(int));
  dp_len[0] = (num & 1) ? 1 : 0;
  num >>= 1;
  int max_len = 0;

  int start_idx = -1;
  if (dp_len[0]) {
    max_len = 1;
    start_idx = 0;
  }

  for (int i = 1; i < len; ++i) {
    dp_len[i] = (num & 1) ? dp_len[i - 1] + 1 : 0;
    num >>= 1;

    if (max_len < dp_len[i]) {
      max_len = dp_len[i];
      start_idx = i + 1 - max_len;
    }
  }
  printf("start_idx: %d, max_len:%d\n", start_idx, max_len);
  free(dp_len);
  return;
}

int main() {
  maxSubBitSequence(255);
  maxSubBitSequence(119);
  maxSubBitSequence(247);
  return 0;
}
