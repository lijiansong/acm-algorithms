#include <cstdio>
#include <cstdlib>

int MaxSubSlow(int *A, const int &n) {
  int max_sub = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n - i + 1; ++j) {
      int sum = 0;
      for (int k = j - 1; k < j - 1 + i; ++k) {
        sum += A[k];
      }
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
    for (int i = 0; i < n; ++i) {
      scanf("%d", &array[i]);
    }
    printf("%d\n", MaxSubSlow(array, n));
    free(array);
  }
  return 0;
}
