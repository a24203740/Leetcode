#include "../includes.hpp"
#include <algorithm>
#include <cstdio>

using ll = long long;

class Solution {
public:
  long long countSubarrays(vector<int> &nums, int k) {
    int mx = 0;
    int cnt = 0, n = nums.size();
    int l = 0, r = 0;
    ll ans = 0;
    for (auto &x : nums) {
      mx = max(mx, x);
    }
    while (r < n) {
      if (nums[r] == mx) {
        cnt++;
      }
      r++;
      while (l < r && cnt >= k) {

        if (nums[l] == mx) {
          cnt--;
        }
        l++;
      }
      ans += l;
    }
    return ans;
  }
};
