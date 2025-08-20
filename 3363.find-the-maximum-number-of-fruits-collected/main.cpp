#include "../includes.hpp"

class Solution {
public:
  int maxCollectedFruits(vector<vector<int>> &fruits) {
    int n = fruits.size();
    vector<vector<int>> dpRT(n, vector<int>(n, 0)), dpLB(n, vector<int>(n, 0));
    for(int col = 0; col < n-1; col++) {
      for(int row = n - 1 - col; row < n; row++) {
        if (row != col) {
          dpLB[row][col] += fruits[row][col];
        }
        int from = max(row - 1, 0);
        int to = min(row + 1, n - 1);
        for(int i = from; i <= to; i++) {
          dpLB[i][col+1] = max(dpLB[i][col+1], dpLB[row][col]);
        }
      }
    }
    for(int row = 0; row < n - 1; row++) {
      for(int col = n - 1 - row; col < n; col++) {
        if(row != col) {
          dpRT[row][col] += fruits[row][col];
        }
        int from = max(col - 1, 0);
        int to = min(col + 1, n - 1);
        for(int i = from; i <= to; i++) {
          dpRT[row+1][i] = max(dpRT[row+1][i], dpRT[row][col]);
        }
      }
    }
    int ans = dpRT[n-1][n-1] + dpLB[n-1][n-1];
    for(int i = 0; i < n; i++) {
      ans += fruits[i][i];
    }
    return ans;
  }
};
