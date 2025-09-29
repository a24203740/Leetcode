#include "../includes.hpp"

class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int R = triangle.size();
    vector<int> dp(R + 1, 0);
    vector<int> tp(R + 1, 0);
    for (int i = 0; i < R; i++)
      dp[i] = triangle[R - 1][i];
    for (int r = R - 2; r >= 0; r--) {
      int C = r + 1;
      for (int i = 0; i < C; i++) {
        tp[i] = min(dp[i], dp[i+1]) + triangle[r][i];
      }
      dp.swap(tp);
    }
    return dp[0];
  }
};
