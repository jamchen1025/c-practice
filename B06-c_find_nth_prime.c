/**********************************************************************************
找第n個質數
**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int isPrime(int n) {
  if (n < 2) return 0;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int findNthPrime(int nth) {
  int count = 0;
  for (int i = 0;; i++) {
    if (isPrime(i) == 1) {
      if (++count == nth) {
        return i;
      }
    }
  }
  return -1;
}

int main() {
  printf("%d\n", findNthPrime(10));
  return 0;
}

//   2   3   5   7  11
//  13  17  19  23  29
//  31  37  41  43  47
//  53  59  61  67  71
//  73  79  83  89  97
// 101 103 107 109 113
// 127 131 137 139 149
// 151 157 163 167 173
