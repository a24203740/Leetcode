#include "includes.hpp"

class Solution {
public:
  const int dr[4] = {1, 0, -1, 0};
  const int dc[4] = {0, 1, 0, -1};
  int val;
  bool isValid(int r, int c, int R, int C) {
    return r >= 0 && r < R && c >= 0 && c < C;
  }
  void DFS(int r, int c, int R, int C, vector<vector<int>> &grid) {
    val += grid[r][c];
    grid[r][c] = 0;
    for (int d = 0; d < 4; d++) {
      int nr = r + dr[d], nc = c + dc[d];
      if (isValid(nr, nc, R, C) && grid[nr][nc] > 0) {
        DFS(nr, nc, R, C, grid);
      }
    }
  }
  int findMaxFish(vector<vector<int>> &grid) {
    int R = grid.size(), C = grid[0].size();
    int ans = 0;
    for (int r = 0; r < R; r++) {
      for (int c = 0; c < C; c++) {
        if(grid[r][c] > 0) {
          val = 0;
          DFS(r, c, R, C, grid);
          ans = max(ans, val);
        }
      }
    }
    return ans;
  }
};
