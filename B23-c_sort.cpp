#include <stdio.h>
#include <stdlib.h>
const int len = 10;

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSort(int* data, int start, int end) {
    if (start >= end) return;  // 如果start >= end就不用比較了，直接回傳
    
    int mid = data[end];                        // 指定比較元素
    int low = start, high = end - 1;            // 指定頭尾位置
    while (low < high) {                        // 當low < high才需要比較
        while (data[low] < mid && low < high)   // 讓小於mid的數值都放到左側（小的那一邊)
            low++;
        while (mid <= data[high] && low < high) // 讓大於或等於mid的數值都放到右側（大的那一邊)
            high--;
        Swap(&data[low], &data[high]);
    }
    // 注意離開while時，low high應該相等，所以才能跳出迴圈
    
    if (data[low] >= mid) // 如果這樣low還是大於等於mid，表示mid是最小值，所以把mid跟low交換，讓mid右側都是最大值
        Swap(&data[low], &data[end]);
    else  //因為data[low]小於mid，low又已經盡可能地往右邊走，此時把low++表示把low移動到可以當作mid的元素的位址
        low++;
    
    // 把mid左右邊分別在餵入quicksort
    QuickSort(data, start, low - 1);
    QuickSort(data, low + 1, end);
}

void BubbleSort(int* data, int len) {
    for (int i = len - 1; i >= 0; --i) {
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
