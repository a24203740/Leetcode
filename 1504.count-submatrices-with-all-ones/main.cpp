#include "../includes.hpp"

class Solution {
public:
  int numSubmat(vector<vector<int>> &mat) {
    int R = mat.size();
    int C = mat[0].size();
    int ans = 0;
    for(int r = 0; r < R; r++) {
      for(int c = 0; c < C; c++) {
        if(mat[r][c] == 1) {
          mat[r][c] = (c == 0 ? 1 : mat[r][c - 1] + 1);
          int minWidth = mat[r][c];
          int tpr = r;
          while (tpr >= 0 && minWidth > 0) {
            minWidth = min(minWidth, mat[tpr][c]);
            ans += minWidth;
            tpr--;
          }
        } else {
          mat[r][c] = 0;
        }
      }
    }
    return ans;
  }
};
