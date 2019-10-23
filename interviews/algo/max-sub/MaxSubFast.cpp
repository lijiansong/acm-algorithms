#include <cstdio>
#include <cstdlib>

int MaxSubFast(int *A, int *S, const int &n) {
  if (n <= 0)
    return 0;
  S[0] = 0, S[1] = A[0];
  for (int i = 1; i < n; ++i) {
    S[i + 1] = S[i] + A[i];
  }
  int max_sub = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n - i + 1; ++j) {
      int sum = S[j - 1 + i] - S[j - 1];
      if (sum > max_sub) {
        max_sub = sum;
      }
    }
  }
  return max_sub;
}

int main() {
  freopen("in.txt", "r", stdin);
  int n;
  while (scanf("%d", &n) != EOF) {
    int *array = (int *)malloc(n * sizeof(int));
    int *pre_sum = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; ++i) {
      scanf("%d", &array[i]);
    }
    printf("%d\n", MaxSubFast(array, pre_sum, n));
    free(array);
    free(pre_sum);
  }
  return 0;
}
