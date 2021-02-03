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

void transformArr(int** source, int** target, int r, int c) {
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < r; j++) {
      target[i][j] = source[j][i];
    }
  }
}

int main() {
  int r = 3, c = 10;

  int** arr = createArr(r, c);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      arr[i][j] = i * c + j;
    }
  }
  printArr(arr, r, c);

  printf("====================\n");

  int** t_arr = createArr(c, r);
  transformArr(arr, t_arr, r, c);
  printArr(t_arr, c, r);

  freeArr(&t_arr, c);
  freeArr(&arr, r);

  return 0;
}
