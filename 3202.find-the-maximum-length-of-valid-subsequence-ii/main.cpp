#include "../includes.hpp"

class Solution {
public:
  int maximumLength(vector<int> &nums, int k) {
    vector<vector<int>> dp(k+1, vector<int>(k+1, 0));
    int n = nums.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
      nums[i] %= k;
      for(int rem = 0; rem < k; rem++) {
        int target = (rem - nums[i] + k) % k;
        dp[rem][nums[i]] = dp[rem][target] + 1;
        ans = max(ans, dp[rem][nums[i]]);
      }
    }
    return ans;
  }
};
