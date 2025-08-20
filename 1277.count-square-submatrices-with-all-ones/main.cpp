#include "../includes.hpp"

class Solution {
public:
  int countSquares(vector<vector<int>> &matrix) {
    int R = matrix.size();
    int C = matrix[0].size();
    int ans = 0;
    for(int r = 0; r < R; r++) {
      for(int c = 0; c < C; c++) {
        if(matrix[r][c] && r && c) {
          matrix[r][c] = min({matrix[r-1][c], matrix[r][c-1], matrix[r-1][c-1]}) + 1;
        }
        ans += matrix[r][c];
      }
    }
    return ans; 
  }
};
