#include "../includes.hpp"

using ll = long long;
class Solution {
public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    vector<pair<int,int>> dp(n + 1, {0, 0});
    ll spreading = 1;
    ll knowing = 1;
    dp[forget].second = 1;
    const int mod = 1e9 + 7;
    for (int i = delay; i < n; i++) {
      int start = i + delay;
      if (start > n) start = n;
      int stop = i + forget;
      if (stop > n) stop = n;
      // n will be ingnored day
      spreading += dp[i].first;
      spreading -= dp[i].second;
      spreading = (spreading + mod) % mod;
      // {spreading} people know the secret at day i
      knowing += spreading;
      knowing -= dp[i].second;
      knowing = (knowing + mod) % mod;
      dp[start].first = (dp[start].first + spreading) % mod;
      dp[stop].second = (dp[stop].second + spreading) % mod;
    } 
    return knowing % mod;
  }
};
