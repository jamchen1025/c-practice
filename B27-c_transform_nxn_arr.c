#include <stdio.h>
#include <stdlib.h>

int** createArr(int r, int c) {
  int** arr = (int**)malloc(sizeof(int*) * r);
  for (int i = 0; i < r; ++i) {
    arr[i] = (int*)malloc(sizeof(int) * c);
  }
  return arr;
}

void printArr(int** arr, int r, int c) {
  if (arr == NULL) {
    return;
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("%2d ", arr[i][j]);
    }
    printf("\n");
  }
}

void freeArr(int*** arr, int r) {
  if (*arr == NULL) {
    return;
  }
  for (int i = 0; i < r; i++) {
    free((*arr)[i]);
  }
  free(*arr);
  *arr = NULL;
}

void transformArr(int** source, int r) {
  for (int i = 1; i < r; i++) {
    for (int j = i + 1; j < r; j++) {
      int temp = source[i][j];
      source[i][j] = source[j][i];
      source[j][i] = temp;
    }
  }
}

int main() {
  int r = 5, c = 5;

  int** arr = createArr(r, c);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      arr[i][j] = i * c + j;
    }
  }
  printArr(arr, r, c);
  printf("====================\n");

  transformArr(arr, r);
  printArr(arr, r, c);

  freeArr(&arr, r);

  return 0;
}
