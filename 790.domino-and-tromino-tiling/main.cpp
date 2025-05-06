#include "../includes.hpp"

class Solution {
public:
  int numTilings(int n) {
    if(n <= 2)return n;
    enum {
      FULLY_CHARGED,
      UPPER_POKE,
      BOTTOM_POKE
    } state;
    const int mod = 1e9 + 7;
    vector<array<int, 3>> dp(n+1, array<int, 3>{0, 0, 0});
    dp[1] = {1, 0, 0};
    dp[2] = {2, 1, 1};
    for(int i = 3; i <= n; i++) {
      dp[i][FULLY_CHARGED] = (dp[i-1][FULLY_CHARGED] + dp[i-2][FULLY_CHARGED]) % mod;
      dp[i][FULLY_CHARGED] += (dp[i-1][UPPER_POKE] + dp[i-1][BOTTOM_POKE]) % mod;
      dp[i][FULLY_CHARGED] %= mod;
      dp[i][UPPER_POKE] = (dp[i-1][BOTTOM_POKE] + dp[i-2][FULLY_CHARGED]) % mod;
      dp[i][BOTTOM_POKE] = (dp[i-1][UPPER_POKE] + dp[i-2][FULLY_CHARGED]) % mod;
    }
    return dp[n][FULLY_CHARGED];
  }
};
