#include "../includes.hpp"

using pii = pair<int, int>;
using ll = long long;
const int MOD = 1e9 + 7;
class Solution {
public:
  int possibleStringCount(string word, int k) {
    int n = word.size();
    if(n < k) return 0;
    vector<pii> appear; 
    char prev = word[0];
    int count = 0;
    for(int i = 0; i < n; i++) {
      if(word[i] == prev) {
        count++;
      } else {
        appear.push_back({prev, count});
        prev = word[i];
        count = 1;
      }
    }
    appear.push_back({prev, count});
    int minimal = appear.size();
    ll falseCombinations;
    ll allCombinations = 1;
    int maxCount = 0;
    for(auto [c, cnt] : appear) {
      maxCount = max(maxCount, cnt);
    }
    for(auto [c, cnt] : appear) {
      // one of the characters must be chosen
      // for the left n-1 of this character
      // choose 0 - cnt-1 of this character
      allCombinations = (allCombinations * cnt) % MOD;
    }
    if(minimal >= k) {
      falseCombinations = 0;
    }
    else {
      int falseUB = k - minimal - 1;
      vector<ll> dp(falseUB + 1, 0);
      dp[0] = 1; // base case
      for(auto [c, cnt] : appear) {
        if(cnt == 1)continue;
        int r = falseUB;
        int l = max(falseUB - cnt + 1, 0);
        ll window = 0;
        for(int i = l; i <= r; i++) {
          window = (window + dp[i]) % MOD;
        }
        while(r) {
          ll tp = dp[r];
          dp[r] = window % MOD;
          window -= tp;
          if(l > 0) {
            l--;
            window += dp[l];
          }
          window %= MOD;
          r--;
        }
      }
      for(int i = 0; i <= falseUB; i++) {
        falseCombinations = (falseCombinations + dp[i]) % MOD;
      }
    }
    ll res = allCombinations - falseCombinations;
    while(res < 0) {
      res += MOD;
    }
    return res % MOD;
  }
};
