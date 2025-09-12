#include "../includes.hpp"

class Solution {
public:
  int minimumArea(vector<vector<int>> &grid) {
    bool has1 = false;
    int R = grid.size();
    int C = grid[0].size();
    int minR = R-1, maxR = 0, minC = C-1, maxC = 0;
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        if (grid[r][c] == 1) {
          has1 = true;
          minR = min(minR, r);
          maxR = max(maxR, r);
          minC = min(minC, c);
          maxC = max(maxC, c);
        }
      }
    }
    if (!has1) return 0; // No 1s found, area is 0
    return (maxR - minR + 1) * (maxC - minC + 1);
  }
};
