#include "../includes.hpp"

using ll = long long;
class Solution {
public:
  long long countSubarrays(vector<int> &nums, long long k) {
    int l, r, cnt;
    int n = nums.size();
    ll ans = 0;
    ll currentSum = 0;
    l = r = cnt = 0;
    while (r < n) {
      currentSum += nums[r];
      r++;
      cnt++;
      while (l < r && currentSum * cnt >= k) {
          currentSum -= nums[l];
          l++;
          cnt--;
      }
      ans += cnt;
    }
    return ans;
  }
};
