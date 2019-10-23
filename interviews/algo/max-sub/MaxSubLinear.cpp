#include <algorithm>
#include <cstdio>
#include <cstdlib>

// dynamic programming
// M_t = max{0, M_{t-1} + A[t]}
// TODO: Since we only want to get the max, so we dont need the array M, a state
// variable is OK.
int MaxSubLinear(int *A, int *M, const int &n) {
  M[0] = 0;
  M[1] = std::max(0, A[0]);
  for (int i = 1; i < n; ++i) {
    M[i + 1] = std::max(0, M[i] + A[i]);
  }
  int max_sub = 0;
  for (int i = 1; i <= n; ++i) {
    max_sub = std::max(max_sub, M[i]);
  }
  return max_sub;
}

int main() {
  freopen("in.txt", "r", stdin);
  int n;
  while (scanf("%d", &n) != EOF) {
    int *array = (int *)malloc(n * sizeof(int));
    int *m = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; ++i) {
      scanf("%d", &array[i]);
    }
    printf("%d\n", MaxSubLinear(array, m, n));
    free(array);
    free(m);
  }
  return 0;
}
