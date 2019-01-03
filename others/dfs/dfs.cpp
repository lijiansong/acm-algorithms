#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

int dx[] = {0, 0, 1}; // top, down, right
int dy[] = {-1, 1, 1};

void dfs(const std::vector<std::vector<int> > &matrix, std::vector<int> &ans, int x, int y, int n, int m) {
  int step = 0;
  for (int i = 0; i < 3; ++i) {
    int nextX = x + dx[i] * matrix[x][y];
    int nextY = y + dy[i] * matrix[x][y];
    if (nextX >= 0 && nextX < m - 1 && nextY >= 0 && nextY < n &&
        matrix[nextX][nextY]) {
      dfs(matrix, ans, nextX, nextY, n, m);
      ++step;
    } else if (nextX == (m - 1)) {
      ans.push_back(step);
      return;
    } else {
      // out of boundary
      ans.push_back(-1000);
      return;
    }
  }
  return;
}

// n rows and m columns
int jump(const std::vector<std::vector<int> > &matrix, int n, int m) {
  if (m == 1)
    return 0;
  std::vector<int> ans;
  int i;
  for (i = 0; i < n; ++i) {
    if (matrix[i][0])
      dfs(matrix, ans, i, 0, n, m);
  }
  sort(ans.begin(), ans.end());
  for (i = 0; i < ans.size(); ++i) {
    if (ans[i] > -1000)
      return ans[i];
  }
  return -1;
}

int main() {
  freopen("data.txt", "r", stdin);
  int n, m;
  std::vector<std::vector<int> > matrix;
  while (scanf("%d %d", &n, &m) != EOF) {
    int data;
    for (int i = 0; i < n; ++i) {
      std::vector<int> tmp;
      for (int j = 0; j < m; ++j) {
        scanf("%d", &data);
        tmp.push_back(data);
      }
      matrix.push_back(tmp);
    }
    printf("%d\n", jump(matrix, n, m));
    matrix.clear();
  }
  return 0;
}
