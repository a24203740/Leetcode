#include "../includes.hpp"
#include <cmath>

class Solution {
public:
  const int MOD = 1e9 + 7;
  int numberOfWays(int n, int x) {
    array<int, 500> dp{0};
    for(int i = 1; i <= n; i++) {
      long long int num = pow(i, x);
      if(num > n) break;
      for(int c = n; c >= num; c--) {
        dp[c] += dp[c - num];
        dp[c] %= MOD;
      }
    }
    return dp[n] % MOD;
  }
};
