#include <stdio.h>
#include <stdlib.h>

int maxSubbArray(int* data, const int len) {
  int* dp = (int*)malloc(sizeof(int) * len);
  dp[0] = data[0];
  int result = data[0];

  for (int i = 1; i < len; ++i) {
    dp[i] = data[i] + ((dp[i - 1] < 0) ? 0 : dp[i - 1]);
    if (dp[i] > result) result = dp[i];
  }
  free(dp);         //XXXXX
  return result;
};

int main() {
  int data[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int result = maxSubbArray(data, sizeof(data) / sizeof(data[0]));
  printf("%d\n", result);  // Output: 6
  // Explanation: [4,-1,2,1] has the largest sum = 6.
  return 0;
}
