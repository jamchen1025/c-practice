#include <stdio.h>
#include <stdlib.h>
const int len = 10;

void Swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void QuickSort(int* data, int start, int end) {
  if (start >= end) {
    return;
  }

  int mid = data[end];
  int low = start;
  int high = end - 1;
  while (low < high) {
    while (data[low] < mid && low < high) low++;
    while (mid <= data[high] && low < high)
      high--;  // 讓大於或等於mid的數值都放到mid右側（大的那一邊)
    Swap(&data[low], &data[high]);
  }

  // 如果這樣low還是大於等於mid就表示mid是最小值，所以把mid跟low交換，讓mid右側都是最大值
  if (data[low] >= mid)
    Swap(&data[low], &data[end]);
  else
    low++;

  QuickSort(data, start, low - 1);
  QuickSort(data, low + 1, end);
}

void BubbleSort(int* data, int len) {
  for (int i = len - 1; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (data[j] > data[j + 1]) {
        Swap(&data[j], &data[j + 1]);
      }
    }
  }
}

void PrintArray(int* data) {
  for (int i = 0; i < len; ++i) {
    printf("%d ", data[i]);
  }
  printf("\n");
}

int main() {
  int a[len] = {9, 8, 2, 3, 4, 3, 8, 5, 6, 0};
  PrintArray(a);
  QuickSort(a, 0, len - 1);
  PrintArray(a);
  printf("=============\n");
  int b[len] = {9, 8, 2, 3, 4, 3, 8, 5, 6, 0};
  PrintArray(b);
  BubbleSort(b, len);
  PrintArray(b);
  return 0;
}

/*
---
9 8 2 3 4 3 8 5 6 0
0 2 3 3 4 5 6 8 8 9
=============
9 8 2 3 4 3 8 5 6 0
0 2 3 3 4 5 6 8 8 9
Program ended with exit code: 0
*/
