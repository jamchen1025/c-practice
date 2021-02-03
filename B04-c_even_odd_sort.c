/**********************************************************************************
給你一個n，接下來有n個整數，對他們排序使得
(1) 偶數在前奇數在後
(2) 偶數遞減、奇數遞增
輸出這個數列
**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
const int len = 10;

void Swap(int* a, int* b) {
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

void PrintArray(int* data, int len) {
  for (int i = 0; i < len; ++i) {
    printf("%d ", data[i]);
  }
  printf("\n");
}

void BubbleSort(int* data, int len, int reverse) {
  for (int i = len - 1; i > 0; i--)
    for (int j = 0; j < i; j++)
      if ((reverse == 1 && (data[j] < data[j + 1])) ||
          (reverse == 0 && (data[j] > data[j + 1]))) {
        Swap(&data[j], &data[j + 1]);
      }
}

void EvenOddSort(int* data, int len) {
  if (data == NULL || len < 2) {
    return;
  }
  int low = 0;
  int high = len - 1;
  while (low < high) {
    while (low < high && data[low] % 2 == 0) low++;
    while (low < high && data[high] % 2 == 1) high--;
    Swap(&data[low], &data[high]);
  }

  if (data[low] % 2 == 1) {  // keep data[low] at even;
    low--;
  }
  BubbleSort(data, low + 1, 1);
  BubbleSort(data + low + 1, len - low - 1, 0);
}

int main() {
  int a[len] = {9, 8, 2, 3, 4, 3, 8, 5, 6, 0};
  PrintArray(a, len);
  EvenOddSort(a, len);
  PrintArray(a, len);
  return 0;
}

