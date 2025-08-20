#include "../includes.hpp"

class Solution {
public:
  double soupServings(int n) {
    unordered_map<int, unordered_map<int, double>> dp;
    const double eps = 1e-5;
    auto trans = [&](int a, int b) {
      double res = dp[max(a-4, 0)][b]
        + dp[max(a-3, 0)][max(b-1, 0)]
        + dp[max(a-2, 0)][max(b-2, 0)]
        + dp[max(a-1, 0)][max(b-3, 0)];
      return res / 4.0;
    };
    int ope = (n + 24) / 25;
    dp[0][0] = 0.5;
    for(int m = 1; m <= ope; m++) {
      dp[0][m] = 1.0;
      dp[m][0] = 0.0;
      for(int j = 1; j <= m; j++) {
        dp[j][m] = trans(j, m);
        dp[m][j] = trans(m, j);
      }
      if(abs(dp[m][m] - 1.0) < eps) {
        return 1.0;
      }
    }
    return dp[ope][ope];
  }
};
